//
// Created by fugoes on 12/2/16.
//

#ifndef FINAL_INTEGER_H
#define FINAL_INTEGER_H

class Integer;

#include <list>
#include <string>
#include <iostream>
#include <sstream>

//#include "Data.h"

class Integer {
public:
    Integer(const std::string & str);
    ~Integer();
    void print();
    void plus(Integer *b);
    void minus(Integer *b);
    void times(Integer *b);
    bool bigger(Integer *b);
    bool equal(Integer *b);
private:
    long value;
};

#endif //FINAL_INTEGER_H
