#include <string>
#include <vector>
#include "Worker.h"
#include <algorithm>
#ifndef TASK_33_OPERATORS_H
#define TASK_33_OPERATORS_H


class Readfile: public Worker{
private:
    std::string in_file_name;
public:
    explicit Readfile(std::string file_name):in_file_name(file_name){};
    virtual void run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out);
};


class Writefile: public Worker{
private:
    std::string out_file_name;
public:
    explicit Writefile(std::string file_name):out_file_name(file_name){};
    virtual void run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out);
};


class Grep: public Worker{
private:
    std::string word;
public:
    explicit Grep(std::string word) : word(word) {};
    virtual void run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out);
}; //save string only with word


class Sort: public Worker{
public:
    explicit Sort()= default;;
    virtual void run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out);
}; //sort tokens


class Replace: public Worker{
private:
    std::string word_1;
    std::string word_2;
public:
    explicit Replace(std::string word1,std::string word2) : word_1(word1),word_2(word2) {};
    virtual void run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out);
};


class Dump: public Worker{
private:
    std::string out_file_name;
public:
    explicit Dump(std::string file_name):out_file_name(file_name){};
    virtual void run(std::vector<std::vector<std::string>> &in,std::vector<std::vector<std::string>> &out);
};




#endif //TASK_33_OPERATORS_H