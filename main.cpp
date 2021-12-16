#include <iostream>
#include "Worker.h"
#include "ParseWorkers.cpp"
#include <map>
#include <memory>

using namespace std;

int main() {

    map<int,vector<string>> blocks;
    vector<shared_ptr<Worker>> workers;
    vector<vector<string>> vin;
    vector<vector<string>> vout;

    try{
        workers = ParseWorkers(R"(workflowR2.txt)",blocks);
    }
    catch (const string ex){
        cout<<ex<<endl;
        return -1;
    }

    for (auto& c : workers) {
        try {
            c->run(vin, vout);
        }
        catch (const string ex){
            cout<<ex<<endl;
            return -2;
        }
    }
    return 0;
}
