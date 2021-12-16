#include <string>
#include <vector>
#include <map>
#include <iterator>
#include "Worker.h"
#include "Operators.cpp"
#include "ParseWorkers.h"
#include <memory>

using namespace std;

void create_worker(const string& name, map<int, vector<string>> blocks,int number, vector<shared_ptr<Worker>> &workers) {
    if(name=="readfile"){
        if(blocks[number].size()==4) {
            auto Operator = make_shared<Readfile>(blocks[number][3]);
            workers.push_back(Operator);
        }
        else throw runtime_error("Readfile arguments is wrong\n");

    }
    else if(name=="writefile"){
        if(blocks[number].size()==4) {
            auto Operator = make_shared<Writefile>(blocks[number][3]);
            workers.push_back(Operator);
        }
        else throw runtime_error("Writefile arguments is wrong\n");
    }
    else if(name=="sort"){
        auto Operator = make_shared<Sort>();
        workers.push_back(Operator);
    }
    else if(name=="grep"){
        if(blocks[number].size()==5) {
            auto Operator = make_shared<Grep>(blocks[number][4]);
            workers.push_back(Operator);
        }
        else throw runtime_error("Grep arguments is wrong\n");
    }
    else if(name=="replace"){
        if(blocks[number].size()==5) {
            auto Operator = make_shared<Replace>(blocks[number][3], blocks[number][4]);
            workers.push_back(Operator);
        }
        else throw runtime_error("Replace arguments is wrong\n");
    }
    else if(name=="dump"){
        if(blocks[number].size()==4) {
            auto Operator = make_shared<Dump>(blocks[number][3]);
            workers.push_back(Operator);
        }
        else throw runtime_error("Dump arguments is wrong\n");
    }
    else throw name + string(" realization not found");

}
vector<shared_ptr<Worker>> ParseWorkers (const string& filename,map<int,vector<string>> blocks){
    vector<shared_ptr<Worker>> workers;
    ifstream file (filename);
    string line;
    int flag = 0;
    int flag_sub = 0;
    if(file.is_open()){
        bool flag_desc = false,flag_csed = false;
        while(getline(file,line)){

            if(line == "desc"){
                flag_desc = true;
                continue;
            }
            if(line == "csed"){
                flag_csed = true;
                continue;
            }

            if(flag_desc && !flag_csed){
                try{
                    if(line.size() < 3){
                        throw -1;
                    }
                }
                catch (int ex) {
                    if(line.empty()){
                        throw string("Line in \"") + filename + string("\" is empty:\n");
                    }
                    throw string("This line in \"") + filename + string("\" is wrong:\n") + line;
                }
                istringstream ss(line);
                istream_iterator<string> begin(ss), end;

                vector<string> arrayTokens(begin, end);
                int number;
                try{

                    number=stoi(arrayTokens[0]);
                }

                catch(const exception&  ex){
                    throw string("This line in \"") + filename + string("\" is wrong:\n") + line;
                }
                auto search = blocks.find(number);
                if (search != blocks.end()) {
                    throw string("This line in \"") + filename + string("\" is wrong(redefinition operator):\n") + line;
                } else {
                    blocks[number]=arrayTokens;
                }
                flag = 1;
            }
            else if(!flag_desc && flag != 1){
                throw runtime_error("Desc is missing");
            }
            else if(flag_csed){
                std::istringstream ss(line);
                std::istream_iterator<string> begin(ss), end;

                vector<string> arrayTokens(begin, end);
                for(int i=0;i<arrayTokens.size();i+=2){
                    int number;
                    try{
                        number=stoi(arrayTokens[i]);
                    }
                    catch(const exception&  ex){
                        throw string("This line in \"") + filename + string("\" is wrong:\n") + line;
                    }
                    auto search = blocks.find(number);
                    if (search != blocks.end()) {
                        string operator_name = blocks[number][2];
                        create_worker( operator_name,blocks, number,workers);
                    }
                    else {
                        throw string("Operator under the number ") + arrayTokens[i] +string(" not found");
                    }
                    flag_sub = 1;
                }
            }
            else {
                throw string("This line in \"") + filename + string("\" is wrong:\n") + line;
            }
        }
        if(!flag_csed){
            throw runtime_error("Csed is missing");
        }
        else if(flag_sub != 1){
            throw runtime_error("Subsequence is missing!");
        }
    }
    else {
        throw runtime_error("File is not open!");
    }
    file.close();
    return workers;
}
