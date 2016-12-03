//
// Created by fugoes on 12/3/16.
//

#include "Code.h"

bool isValidCode(std::string & str) {
    unsigned long i = 0;
    long count = 0;
    for (i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            count++;
        } else if (str[i] == ')') {
            count--;
        }
    }
    assert(count >= 0);
    if (count == 0) {
        return true;
    } else if (count > 0){
        return false;
    }
}


void Code::FinalShell() {
    std::cout << "Welcome to Final Shell!" << std::endl;
    std::cout << ">>> ";

    auto runtime = new Runtime();
    auto sourceCode = new std::string;
    auto temp = new std::string;
    auto pos = new unsigned long(0);
    Bracket* bracket;
    while (true) {
        std::getline(std::cin, *sourceCode);
        while (!isValidCode(*sourceCode)) {
            std::cout << "... ";
            std::getline(std::cin, *temp);
            if (*temp == "") {
                *sourceCode = *temp;
                break;
            }
            *sourceCode += " " + *temp;
        }
        if (*sourceCode == "") {
            break;
        }
        *pos = 0;
        bracket = new Bracket(*sourceCode, *pos);
        bracket->eval(runtime)->display();
        delete bracket;
        std::cout << ">>> ";
    }
}
