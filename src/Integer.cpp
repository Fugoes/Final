//
// Created by fugoes on 12/4/16.
//

#include "Data.h"

Integer::~Integer() { }

Integer::Integer() {
    value = 0;
}

void Integer::print() {
    std::cout << value;
}

void Integer::display() {
    std::cout << "type : Integer" << std::endl;
    std::cout << "value: " << value << std::endl;
}

Integer::Integer(const long &value) {
    this->value = value;
}

Data *Integer::plus(std::vector<Data *> &dataPara) {
    auto result = new Integer(0);
    for (int i = 0; i < dataPara.size(); i++) {
        result->value += (dynamic_cast<Integer*>(dataPara[i]))->value;
    }
    return result;
}
