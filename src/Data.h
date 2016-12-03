//
// Created by fugoes on 12/2/16.
//

#ifndef FINAL_DATA_H
#define FINAL_DATA_H

class Data;

#include <list>
#include <string>
#include <iostream>
#include <cassert>

#include "Integer.h"

class Data {
public:
    Data(const std::string & str);
    ~Data();
    static Data* cite(Data* data);
    static void uncite(Data* data);
    static void check(Data* data);
    static Data* plus(std::list<Data*>* paraData);
    static Data* minus(std::list<Data*>* paraData);
    static Data* times(std::list<Data*>* paraData);
    static Data* bigger(std::list<Data*>* paraData);
    static Data* smaller(std::list<Data*>* paraData);
    static Data* equal(std::list<Data*>* paraData);

    void display();

private:
    unsigned int cited;
    /*
     * type = 0 false
     *      = 1 true
     *      = 2 integer
     */
    unsigned short type;
    void * value;

    friend class Bracket;
};

#endif //FINAL_DATA_H
