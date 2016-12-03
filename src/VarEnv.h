//
// Created by fugoes on 12/2/16.
//

#ifndef FINAL_VARENV_H
#define FINAL_VARENV_H

class VarEnv;

#include <map>
#include <string>
#include <list>
#include "Data.h"


class VarEnv {
public:
    VarEnv();
    ~VarEnv();
    Data* getVar(const std::string & name);
    void assignVar(const std::string & name, Data *data);
    void display();
private:
    std::map<std::string, Data*> vars;
};

#endif //FINAL_VARENV_H
