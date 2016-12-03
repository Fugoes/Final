//
// Created by fugoes on 12/2/16.
//

#include "Data.h"

Data::Data(const std::string &str) {
    cited = 0;
    if ((str[0] >= '0' && str[0] <= '9') || str[0] == '-') {
        type = 2;
        value = (void *)new Integer(str);
    } else if (str == "true") {
        type = 1;
    } else if (str == "false") {
        type = 0;
    } else assert(false);
}

Data::~Data() {
    if (type == 2) {
        delete ((Integer *)value);
    }
}

Data* Data::cite(Data *data) {
    data->cited++;
    return data;
}

void Data::uncite(Data *data) {
    data->cited--;
}

void Data::check(Data *data) {
    if (data->cited == 0) {
        delete data;
        data = NULL;
    }
}

void Data::display() {
    std::cout << "cited: " << cited << std::endl;
    if (type == 0) {
        std::cout << "type : false" << std::endl;
    } else if (type == 1) {
        std::cout << "type : true" << std::endl;
    } else if (type == 2) {
        std::cout << "type : integer" << std::endl;
        std::cout << "value: ";
        ((Integer *) value)->print();
        std::cout << std::endl;
    } else assert(false);
}

Data *Data::plus(std::list<Data *> *paraData) {
    auto result = new Data("0");
    auto todo = new std::list<Data*>();
    for (auto & i: *paraData) {
        assert(i->type == 2);
        ((Integer*)(result->value))->plus((Integer*)(i->value));
        todo->push_back(i);
    }
    for (auto & i: *todo) {
        check(i);
    }
    delete paraData;
    return result;
}

Data *Data::times(std::list<Data *> *paraData) {
    auto result = new Data("1");
    auto todo = new std::list<Data*>();
    for (auto & i: *paraData) {
        assert(i->type == 2);
        ((Integer*)(result->value))->times((Integer*)(i->value));
        todo->push_back(i);
    }
    for (auto & i: *todo) {
        check(i);
    }
    delete paraData;
    return result;
}

Data *Data::bigger(std::list<Data *> *paraData) {
    auto cursora = paraData->begin();
    auto cursorb = --paraData->end();
    assert((*cursora)->type == 2);
    assert((*cursorb)->type == 2);
    if (((Integer*)((*cursora)->value))->bigger((Integer*)((*cursorb)->value))) {
        Data::check(*cursora);
        Data::check(*cursorb);
        return new Data("true");
    } else {
        Data::check(*cursora);
        Data::check(*cursorb);
        return new Data("false");
    }
    delete paraData;
}

Data *Data::smaller(std::list<Data *> *paraData) {
    auto cursorb = paraData->begin();
    auto cursora = --paraData->end();
    assert((*cursora)->type == 2);
    assert((*cursorb)->type == 2);
    if (((Integer*)((*cursora)->value))->bigger((Integer*)((*cursorb)->value))) {
        Data::check(*cursora);
        Data::check(*cursorb);
        return new Data("true");
    } else {
        Data::check(*cursora);
        Data::check(*cursorb);
        return new Data("false");
    }
    delete paraData;
}

Data *Data::equal(std::list<Data *> *paraData) {
    auto cursora = paraData->begin();
    auto cursorb = --paraData->end();
    assert((*cursora)->type == 2);
    assert((*cursorb)->type == 2);
    if (((Integer*)((*cursora)->value))->equal((Integer*)((*cursorb)->value))) {
        Data::check(*cursora);
        Data::check(*cursorb);
        return new Data("true");
    } else {
        Data::check(*cursora);
        Data::check(*cursorb);
        return new Data("false");
    }
    delete paraData;
}

Data *Data::minus(std::list<Data *> *paraData) {
    auto result = new Data("0");
    auto todo = new std::list<Data*>();
    auto i = paraData->begin();
    assert((*i)->type == 2);
    ((Integer*)(result->value))->plus((Integer*)((*i)->value));
    todo->push_back(*i);
    i++;
    assert((*i)->type == 2);
    ((Integer*)(result->value))->minus((Integer*)((*i)->value));
    todo->push_back(*i);
    for (auto & i: *todo) {
        check(i);
    }
    delete paraData;
    return result;
}

Data *Data::print(std::list<Data *> *paraData) {
    for (auto & i: *paraData) {
        if (i->type == 0) {
            std::cout << "false";
        } else if (i->type == 1) {
            std::cout << "true";
        } else if (i->type == 2) {
            ((Integer*)i->value)->print();
        }
        std::cout << std::endl;
    }
    return new Data("true");
}

void Data::print() {
    if (type == 0) {
        std::cout << "false";
    } else if (type == 1) {
        std::cout << "true";
    } else if (type == 2) {
        ((Integer*)value)->print();
    }
}
