//
// Created by fugoes on 12/4/16.
//

#include "Data.h"

Bool::Bool(bool value) {
    this->value = value;
}

Bool::~Bool() {}

void Bool::print() {
    if (value) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }
}

void Bool::display() {
    std::cout << "cited: " << cited << std::endl;
    std::cout << "type : bool" << std::endl;
    std::cout << "value: ";
    print();
    std::cout << std::endl;
    std::cout << std::endl;
}

Bool::Bool(bool value, int) : Data(1) {
    this->value = value;
}
