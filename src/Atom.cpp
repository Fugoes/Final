//
// Created by fugoes on 12/2/16.
//

#include "Atom.h"

void printSpace(int i) {
    for (int j = 0; j < i; j++) {
        std::cout << " ";
    }
}

bool isBlank(const char & achar) {
    return achar == ' ' || achar == '\n' || achar == '\t';
}

/*
 * Search for a word begin from pos and change the pos to the end + 1
 * of next unblank.
 */
std::string getWord(const std::string & str, unsigned long & pos) {
    unsigned long count = 0;
    auto begin = pos;
    while (!isBlank(str[pos + count]) && str[pos + count] != ')') {
        count++;
    }
    pos += count;
    return str.substr(begin, count);
}


Bracket::Bracket(const std::string &str, unsigned long &pos) {
    assert(str[pos] == '(');
    pos++;
    func = getWord(str, pos);
    Atom* temp;
    while (str[pos] != ')') {
        if (isBlank(str[pos])) {
            pos++; } else if (str[pos] == '(') {
            para.push_back(new Bracket(str, pos));
            pos++;
        } else {
            para.push_back(new Symbol(getWord(str, pos)));
        }
    }
}

Bracket::~Bracket() {
    auto cursor = para.begin();
    while (cursor != para.end()) {
        if (*cursor != NULL) {
            delete *cursor;
            *cursor = NULL;
        }
        cursor++;
    }
}

void Bracket::display(int indent) {
    printSpace(indent);
    std::cout << "(" << func << std::endl;
    for (auto & i: para) {
        i->display(indent + 1);
    }
    printSpace(indent);
    std::cout << ")" << std::endl;
}

Data *Bracket::eval(Runtime *runtime) {
    runtime->pushVarEnv();
    Data* result;
    if (func == "+") {
        result = Data::plus(genParaData(runtime));
    } else if (func == "*") {
        result = Data::times(genParaData(runtime));
    } else if (func == "-") {
        result = Data::minus(genParaData(runtime));
    } else if (func == "=") {
        result = Data::equal(genParaData(runtime));
    } else if (func == ">") {
        result = Data::bigger(genParaData(runtime));
    } else if (func == "<") {
        result = Data::smaller(genParaData(runtime));
    } else if (func == "print") {
        result = Data::print(genParaData(runtime));
    } else if (func == "assign") {
        runtime->assignVar( ((Symbol*)(*para.begin()))->name,
                            (*(++para.begin()))->eval(runtime) );
        result = new Data("true");
    } else if (func == "begin") {
        auto temp = genParaData(runtime);
        auto cursor = temp->begin();
        while (cursor != --temp->end()) {
            Data::check(*cursor);
            cursor++;
        }
        result = temp->back();
        delete temp;
    } else if (func == "if") {
        auto cursor = para.begin();
        auto temp = (*cursor)->eval(runtime);
        if (temp->type) {
            cursor++;
            result = (*cursor)->eval(runtime);
        } else {
            cursor++;
            cursor++;
            result = (*cursor)->eval(runtime);
        }
        Data::check(temp);
    } else if (func == "function") {
        Function::newFunction(&para);
        result = new Data("true");
    } else {
        result = Function::call(func, genParaData(runtime));
    }
    runtime->popVarEnv();
    return result;
}

std::list<Data *> *Bracket::genParaData(Runtime *runtime) {
    auto result = new std::list<Data*>;
    for (auto & i: para) {
        result->push_back(i->eval(runtime));
    }
    return result;
}

Atom *Bracket::copy() {
    auto result = new Bracket();
    result->func = func;
    for (auto & i: para) {
        result->para.push_back(i->copy());
    }
    return result;
}

Bracket::Bracket() { }

Symbol::Symbol(const std::string &str) {
    name = str;
}

Symbol::~Symbol() {
}

void Symbol::display(int indent) {
    printSpace(indent);
    std::cout << name << std::endl;
}

Data *Symbol::eval(Runtime *runtime) {
    if (name[0] == '-' || (name[0] <= '9' && name[0] >= '0') ) {
        return new Data(name);
    } else if (name == "true" || name == "false") {
        return new Data(name);
    } else {
        return runtime->getVar(name);
    }
}

Atom *Symbol::copy() {
    return new Symbol(name);
}
