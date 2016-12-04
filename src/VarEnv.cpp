//
// Created by fugoes on 12/2/16.
//

#include "VarEnv.h"

VarEnv::VarEnv() {}

VarEnv::~VarEnv() {
    for (auto &i: vars) {
        (i.second)->uncite();
        Data::check(i.second);
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
    data->cite();
    if (search != vars.end()) {
        (search->second)->uncite();
        Data::check(search->second);
        search->second = data;
    } else {
        vars.insert(std::pair<std::string, Data *>(name, data));
    }
}

void VarEnv::display() {
    for (auto &i: vars) {
        std::cout << std::endl;
        std::cout << "name : " << i.first << std::endl;
        i.second->display();
    }
}
