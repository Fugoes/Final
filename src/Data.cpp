//
// Created by fugoes on 12/4/16.
//

#include <sstream>
#include "Data.h"

void Data::uncite() {
    cited--;
}

void Data::cite() {
    cited++;
}

void Data::check(Data *data) {
    if (data->cited == 0) {
        delete data;
    }
}

Data *Data::newData(const std::string &str) {
    if (str[0] == '-' || (str[0] <= '9' && str[0] >= '0')) {
        std::stringstream temp;
        long value;
        temp << str;
        temp >> value;
        return new Integer(value);
    } else return NULL;
}

Data *Data::plus(std::vector<Data *> *paraData) {
    Data* result = NULL;
    if ((dynamic_cast<Integer*>((*paraData)[0])) != NULL) {
        result = Integer::plus(*paraData);
    }
    for (auto i: *paraData) {
        Data::check(i);
    }
    delete paraData;
    return result;
}

Data::Data() {
    cited = 0;
}
