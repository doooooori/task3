#include <iostream>
#include "Worker.h"
#include "ParseWorkers.cpp"
#include <map>
#include <memory>

int main() {

    std::map<int,std::vector<std::string>> blocks;
    std::vector<std::shared_ptr<Worker>> workers;
    std::vector<std::vector<std::string>> vin;
    std::vector<std::vector<std::string>> vout;

    try{
        workers = ParseWorkers(R"(C:\Users\Dori\CLionProjects\task33\workflowR2.txt)",blocks);
    }
    catch (const std::string  ex){
        std::cout<<ex<<std::endl;
        return -1;
    }

    for (auto& c : workers) {
        try {
            c->run(vin, vout);
        }
        catch (const std::string  ex){
            std::cout<<ex<<std::endl;
            return -2;
        }
    }
    return 0;
}