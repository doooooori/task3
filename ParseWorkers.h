#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <iterator>
#include "Worker.h"
#include "Operators.h"
#include <memory>
#ifndef TASK_33_PARSEWORKERS_H
#define TASK_33_PARSEWORKERS_H
void create_worker(const std::string& name,std::map<int,std::vector<std::string>> blocks,int number, std::vector<std::shared_ptr<Worker>> &workers);
std::vector<std::shared_ptr<Worker>> ParseWorkers (const std::string& filename,std::map<int,std::vector<std::string>> blocks);

#endif //TASK_33_PARSEWORKERS_H