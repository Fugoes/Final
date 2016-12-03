//
// Created by fugoes on 12/2/16.
//

#ifndef FINAL_ATOM_H
#define FINAL_ATOM_H

class Atom;
class Bracket;
class Symbol;

#include <iostream>
#include <string>
#include <list>
#include <cassert>
#include "Runtime.h"
#include "Function.h"
#include "Atom.h"
//#include "VarEnv.h"

class Atom {
public:
    Atom() {};
    virtual ~Atom() {};
    virtual void display(int indent) = 0;
    virtual Data* eval(Runtime * runtime) = 0;
    virtual Atom* copy() = 0;
};

class Bracket: public Atom {
public:
    Bracket(const std::string &str, unsigned long &pos);
    Bracket();
    virtual ~Bracket();
    virtual void display(int indent);
    virtual Data* eval(Runtime * runtime);
    virtual Atom* copy();
private:
    std::string func;
    std::list<Atom*> para;

    std::list<Data*>* genParaData(Runtime *runtime);

    friend class Runtime;
    friend class Function;
};

class Symbol: public Atom {
public:
    Symbol(const std::string &str);
    virtual ~Symbol();
    virtual void display(int indent);
    virtual Data* eval(Runtime * runtime);
    virtual Atom* copy();
private:
    std::string name;

    friend class Runtime;
    friend class Bracket;
    friend class Function;
};

#endif //FINAL_ATOM_H
