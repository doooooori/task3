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

using namespace std;

void create_worker(const string& name,map<int,vector<string>> blocks,int number, vector<shared_ptr<Worker>> &workers);
vector<shared_ptr<Worker>> ParseWorkers (const string& filename,map<int,vector<string>> blocks);

#endif //TASK_33_PARSEWORKERS_H
