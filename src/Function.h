//
// Created by fugoes on 12/3/16.
//

#ifndef FINAL_FUNCTION_H
#define FINAL_FUNCTION_H

class Function;

#include <list>
#include <string>
#include <map>
#include "Runtime.h"
#include "Atom.h"

class Function {
public:
    Function();
    ~Function();
    static void newFunction(std::list<Atom*>* source);
    Data* eval(std::vector<Data*>* parasData);
    static Data* call(std::string & name, std::vector<Data*>* parasData);
private:
    std::list<std::string> paras;
    std::list<Atom*> body;

    static std::map<std::string, Function*> FuncEnv;
};

#endif //FINAL_FUNCTION_H
