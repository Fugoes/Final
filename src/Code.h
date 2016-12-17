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

/**
 * 用于提供一个交互运行代码的Shell
 */
class Code {
public:
    /**
     * 用于提供一个交互运行代码的Shell
     */
    static void FinalShell();

private:
    /**
     * 用于存储用户输入的代码
     */
    std::list<std::string *> brackets;
};

#endif //FINAL_CODE_H
