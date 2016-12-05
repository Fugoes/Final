//
// Created by fugoes on 12/2/16.
//

#include "Runtime.h"

Runtime::Runtime() {
    varEnvs.push_front(NULL);
}

Runtime::~Runtime() {
    for (auto &i: varEnvs) {
        if (i != NULL) {
            delete i;
        }
    }
}

void Runtime::setVar(std::string &name, Data *data) {
    auto target = getVar(name);
    if ((dynamic_cast<Integer *>(target)) != NULL) {
        ((Integer *) target)->value = ((Integer *) data)->value;
    }
}

void Runtime::assignVar(std::string &name, Data *data) {
    auto cursor = varEnvs.begin();
    cursor++;
    if (*cursor == NULL) {
        *cursor = new VarEnv();
    }
    (*cursor)->assignVar(name, data);
}

Data *Runtime::getVar(std::string &name) {
    auto cursor = varEnvs.begin();
    Data *result = NULL;
    while (result == NULL) {
        if ((*cursor) == NULL) {
            cursor++;
        } else {
            result = (*cursor)->getVar(name);
        }
    }
    return result;
}

void Runtime::pushVarEnv() {
    varEnvs.push_front(NULL);
}

void Runtime::popVarEnv() {
    if ((*(varEnvs.begin())) != NULL) {
        delete (*(varEnvs.begin()));
    }
    varEnvs.pop_front();
}

void Runtime::assignVarToTop(std::string &name, Data *data) {
    auto cursor = varEnvs.begin();
    if ((*cursor) == NULL) {
        *cursor = new VarEnv();
    }
    (*cursor)->assignVar(name, data);
}

void Runtime::display() {
    for (auto &i: varEnvs) {
        if (i != NULL) {
            i->display();
        }
    }
}

