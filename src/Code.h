//
// Created by fugoes on 12/3/16.
//

#ifndef FINAL_CODE_H
#define FINAL_CODE_H

class Code;

#include <string>
#include <list>
#include <iostream>
#include "Atom.h"

class Code {
public:
    static void FinalShell();
private:
    std::list<std::string*> brackets;
};

#endif //FINAL_CODE_H
