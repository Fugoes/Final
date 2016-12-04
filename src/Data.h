//
// Created by fugoes on 12/4/16.
//

#ifndef FINAL_DATANEW_H
#define FINAL_DATANEW_H

class Data;
class Integer;

#include <string>
#include <vector>
#include <iostream>


class Data {
public:
    Data();
    virtual ~Data() {};
    static Data* newData(const std::string & str);

    static void check(Data* data);
    void uncite();
    void cite();

    virtual void print() = 0;
    virtual void display() = 0;

    static Data* plus(std::vector<Data*>* paraData);

private:
    unsigned int cited;

    friend class Integer;
};

class Integer: public Data {
public:
    Integer();
    Integer(const long & value);
    virtual ~Integer();
    virtual void print();
    virtual void display();

    static Data* plus(std::vector<Data*>& dataPara);

private:
    long value;
};

#endif //FINAL_DATANEW_H
