#include <iostream>
#include <fstream>
#include "Code.h"
#include "Atom.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        Code::FinalShell();
    } else {
        auto runtime = new Runtime();
        std::ifstream t(argv[1]);
        std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
        unsigned long pos = 0;
        std::list<Bracket *> brackets;
        Bracket* temp;
        while (pos < str.length()) {
            if (str[pos] != '(') {
                pos++;
            } else {
                temp = new Bracket(str, pos);
                Data::check(temp->eval(runtime));
            }
        }
        delete runtime;
    }

    return 0;
}
