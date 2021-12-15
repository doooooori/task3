#include <fstream>
#include <string>
#include <vector>
#include "Worker.h"
#include "Operators.h"
#include <algorithm>
#include <sstream>

using namespace std;

    void Readfile::run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out) {
    std::ifstream in_file (in_file_name);
    std::string line;

    if(in_file.is_open()){

        while(getline(in_file,line)){

            std::istringstream ss(line);
            std::istream_iterator<std::string> begin(ss), end;
            //putting all the tokens in the vector
            std::vector<std::string> arrayTokens(begin, end);
            in.push_back(arrayTokens);

        }
    }
    else{
        throw std::string("File is not open! \n")+in_file_name;
    }
    in_file.close();
}

    void Writefile::run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out) {
    std::ofstream out_file(out_file_name);
    for(auto & string : in){
        for(auto & word : string){
            out_file << word << " ";
        }
        out_file << "\n";
    }
    out_file.close();
}

    void Grep::run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out) {

    for(auto & string : in) {
        bool word_not_exist=true;
        for (auto & this_word : string) {
            if(this_word==word){
                word_not_exist=false;
            }
        }
        if(word_not_exist){
            out.push_back(string);
        }

    }
    in=out;
}

    void Sort::run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out) {

    for(auto & string : in) {
        std::sort(string.begin(), string.end());
    }
}

    void Replace::run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out) {
    for(auto & string : in) {

        for (auto & word : string) {
            if(word==word_1){
                word=word_2;
            }
        }
        out.push_back(string);

    }
    in=out;
}

    void Dump::run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out) {
    std::ofstream out_file(out_file_name);
    for(auto & string : in){
        for(auto & word : string){
            out_file << word << " ";
        }
        out_file << "\n";
    }
    out_file.close();
}
