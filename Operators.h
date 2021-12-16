#include <string>
#include <utility>
#include <vector>
#include "Worker.h"
#include <algorithm>
#ifndef TASK_33_OPERATORS_H
#define TASK_33_OPERATORS_H

using namespace std;

class Readfile: public Worker{
private:
    string in_file_name;
public:
    explicit Readfile(string file_name):in_file_name(move(file_name)){};
    void run(vector<vector<string>> &in,vector<vector<string>> &out) override;
};


class Writefile: public Worker{
private:
    std::string out_file_name;
public:
    explicit Writefile(string file_name):out_file_name(move(file_name)){};
    void run(vector<vector<string>> &in,vector<vector<string>> &out) override;
};


class Grep: public Worker{
private:
    string word;
public:
    explicit Grep(string word) : word(move(word)) {};
    void run(vector<vector<string>> &in,vector<vector<string>> &out) override;
}; //save string only with word


class Sort: public Worker{
public:
    explicit Sort()= default;
    void run(vector<vector<string>> &in,vector<vector<string>> &out) override;
}; //sort tokens


class Replace: public Worker{
private:
    string word_1;
    string word_2;
public:
    explicit Replace(string word1,string word2) : word_1(move(word1)),word_2(move(word2)) {};
    void run(vector<vector<string>> &in,vector<vector<string>> &out) override;
};


class Dump: public Worker{
private:
    string out_file_name;
public:
    explicit Dump(string file_name):out_file_name(move(file_name)){};
    void run(vector<vector<string>> &in,vector<vector<string>> &out) override;
};


#endif //TASK_33_OPERATORS_H
