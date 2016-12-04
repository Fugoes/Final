//
// Created by fugoes on 12/4/16.
//

#include "Data.h"

Integer::~Integer() {}

Integer::Integer() {
    value = 0;
}

void Integer::print() {
    std::cout << value;
}

void Integer::display() {
    std::cout << "cited: " << cited << std::endl;
    std::cout << "type : Integer" << std::endl;
    std::cout << "value: " << value << std::endl;
    std::cout << std::endl;
}

Integer::Integer(const long &value) {
    this->value = value;
}

Data *Integer::plus(std::vector<Data *> *dataPara) {
    auto result = new Integer(0);
    for (int i = 0; i < dataPara->size(); i++) {
        result->value += (dynamic_cast<Integer *>((*dataPara)[i]))->value;
    }
    return result;
}

Data *Integer::minus(std::vector<Data *> *dataPara) {
    auto result = new Integer(((Integer *) ((*dataPara)[0]))->value);
    result->value -= ((Integer *) ((*dataPara)[1]))->value;
    return result;
}

Data *Integer::times(std::vector<Data *> *dataPara) {
    auto result = new Integer(1);
    for (int i = 0; i < dataPara->size(); i++) {
        result->value *= (dynamic_cast<Integer *>((*dataPara)[i]))->value;
    }
    return result;
}

Data *Integer::divide(std::vector<Data *> *dataPara) {
    auto result = new Integer(((Integer *) ((*dataPara)[0]))->value);
    result->value /= ((Integer *) ((*dataPara)[1]))->value;
    return result;
}
