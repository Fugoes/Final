//
// Created by fugoes on 12/2/16.
//

#ifndef FINAL_RUNTIME_H
#define FINAL_RUNTIME_H

class Runtime;

#include <list>
#include <forward_list>
#include "VarEnv.h"
#include "Atom.h"

class Runtime {
public:
    Runtime();
    ~Runtime();
    void assignVar(std::string & name, Data* data);
    void assingVarToTop(std::string & name, Data* data);
    Data* getVar(std::string & name);
    void pushVarEnv();
    void popVarEnv();
    void display() {
        for (auto & i: varEnvs) {
            if (i != NULL) {
                i->display();
            }
        }
    }
    /*
     * run bracket and do bracket++
     */
//    Data* run(std::list<Bracket*>::iterator bracket);
private:
    std::forward_list<VarEnv*> varEnvs;
};

#endif //FINAL_RUNTIME_H
