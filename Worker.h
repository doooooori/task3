#include <vector>
#ifndef TASK_33_WORKER_H
#define TASK_33_WORKER_H
class Worker {
public:
    virtual void run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out) {};
};
#endif //TASK_33_WORKER_H