//
// Created by fugoes on 12/2/16.
//

#include "VarEnv.h"

VarEnv::VarEnv() {}

VarEnv::~VarEnv() {
    std::list<Data*> todo(0);
    for (auto & i: vars) {
        Data::uncite(i.second);
        todo.push_back(i.second);
    }
    for (auto & i: todo) {
        Data::check(i);
    }
}

Data *VarEnv::getVar(const std::string &name) {
    auto search = vars.find(name);
    if (search != vars.end()) {
        return search->second;
    } else {
        return NULL;
    }
}

void VarEnv::assignVar(const std::string &name, Data *data) {
    auto search = vars.find(name);
    Data::cite(data);
    if (search != vars.end()) {
        Data::uncite(search->second);
        Data::check(search->second);
        search->second = data;
    } else {
        vars.insert(std::pair<std::string, Data*>(name, data));
    }
}

void VarEnv::display() {
    for (auto & i: vars) {
        std::cout << std::endl;
        std::cout << "name : " << i.first << std::endl;
        i.second->display();
    }
}
