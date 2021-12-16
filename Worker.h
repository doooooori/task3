#include <vector>
#ifndef TASK_33_WORKER_H
#define TASK_33_WORKER_H

using namespace std;

class Worker {
public:
    virtual void run(vector<vector<string>> &in,vector<vector<string>> &out) { };
};

#endif //TASK_33_WORKER_H
