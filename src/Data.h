//
// Created by fugoes on 12/4/16.
//

#ifndef FINAL_DATANEW_H
#define FINAL_DATANEW_H

class Data;

class Integer;

class Bool;

#include <string>
#include <vector>
#include <iostream>


class Data {
public:
    Data();

    Data(int);

    virtual ~Data() {};

    static Data *newData(const std::string &str);

    static void check(Data *data);

    void uncite();

    void cite();

    virtual void print() = 0;

    virtual void display() = 0;

    static Data *plus(std::vector<Data *> *dataPara);

    static Data *minus(std::vector<Data *> *dataPara);

    static Data *equal(std::vector<Data *> *dataPara);

    static Data *times(std::vector<Data *> *dataPara);

    static Data *divide(std::vector<Data *> *dataPara);

    static Data *bigger(std::vector<Data *> *dataPara);

    static Data *smaller(std::vector<Data *> *dataPara);

    static Data *mod(std::vector<Data *> *dataPara);

    static Data *print(std::vector<Data *> *dataPara);

    static Data *display(std::vector<Data *> *dataPara);

    static Data *trueData;
    static Data *falseData;

private:
    unsigned int cited;

    friend class Integer;

    friend class Bool;

    friend class VarEnv;
};

class Integer : public Data {
public:
    Integer();

    Integer(const long &value);

    virtual ~Integer();

    virtual void print();

    virtual void display();

    static Data *plus(std::vector<Data *> *dataPara);

    static Data *minus(std::vector<Data *> *dataPara);

    static Data *times(std::vector<Data *> *dataPara);

    static Data *divide(std::vector<Data *> *dataPara);

private:
    long value;

    friend class Data;

    friend class Runtime;
};

class Bool : public Data {
public:
    Bool(bool value);

    Bool(bool value, int);

    virtual ~Bool();

    virtual void print();

    virtual void display();

private:
    bool value;

    friend class Data;

    friend class Bracket;

    friend class Runtime;
};

#endif //FINAL_DATANEW_H
