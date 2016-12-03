//
// Created by fugoes on 12/2/16.
//

#include "Integer.h"

Integer::Integer(const std::string &str) {
    std::stringstream temp;
    temp << str;
    temp >> value;
}

Integer::~Integer() {}

void Integer::print() {
    std::cout << value;
}

void Integer::plus(Integer *b) {
    value += b->value;
}

void Integer::times(Integer *b) {
    value *= b->value;
}

bool Integer::bigger(Integer *b) {
    return value > b->value;
}

bool Integer::equal(Integer *b) {
    return value == b->value;
}

void Integer::minus(Integer *b) {
    value -= b->value;
}

bool Integer::smaller(Integer *b) {
    return value < b->value;
}

