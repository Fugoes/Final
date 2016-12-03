//
// Created by fugoes on 12/3/16.
//

#include "Function.h"

std::map<std::string, Function*> Function::FuncEnv;

Function::~Function() {
    for (auto & i: body) {
        delete i;
        i = NULL;
    }
}

Function::Function() { }

Data *Function::eval(std::list<Data*>* parasData) {
    Data* result;
    auto runtime = new Runtime();
    auto parasCursor = paras.begin();
    auto parasDataCursor = parasData->begin();
    while (parasCursor != paras.end()) {
        runtime->assingVarToTop(*parasCursor, *parasDataCursor);
        parasCursor++;
        parasDataCursor++;
    }
    auto bracketsCursor = body.begin();
    while (bracketsCursor != (--body.end())) {
        result = (*bracketsCursor)->eval(runtime);
        Data::check(result);
        bracketsCursor++;
    }
    result = (*bracketsCursor)->eval(runtime);
    delete runtime;
    return result;
}

void Function::newFunction(std::list<Atom*>* source) {
    auto cursor = source->begin();
    auto name = ((Bracket*)(*cursor))->func;
    auto function = new Function;
    for (auto & i: ((Bracket*)(*cursor))->para) {
        function->paras.push_back( ((Symbol*)i)->name );
    }
    cursor++;
    while (cursor != source->end()) {
        function->body.push_back((*cursor)->copy());
        cursor++;
    }
    FuncEnv.insert(std::pair<std::string, Function*>(name, function));
    for (auto & i: *source) {
        if (i != NULL) {
            delete i;
            i = NULL;
        }
    }
}

Data *Function::call(std::string &name, std::list<Data *> *parasData) {
    auto search = FuncEnv.find(name);
    if (search != FuncEnv.end()) {
        return search->second->eval(parasData);
    } else {
        return new Data("false");
    }
}
