//
// Created by fugoes on 12/4/16.
//

#include <sstream>
#include "Data.h"

Data *Data::trueData = new Bool(true, 1);
Data *Data::falseData = new Bool(false, 1);

void Data::uncite() {
    cited--;
}

void Data::cite() {
    cited++;
}

void Data::check(Data *data) {
    if (data->cited == 0) {
        if (data != NULL) delete data;
    }
}

Data *Data::newData(const std::string &str) {
    if (str[0] == '-' || (str[0] <= '9' && str[0] >= '0')) {
        std::stringstream temp;
        long value;
        temp << str;
        temp >> value;
        return new Integer(value);
    } else if (str == "true") {
        return Data::trueData;
    } else if (str == "false") {
        return Data::falseData;
    } else return NULL;
}

Data *Data::plus(std::vector<Data *> *dataPara) {
    Data *result = NULL;
    if ((dynamic_cast<Integer *>((*dataPara)[0])) != NULL) {
        result = Integer::plus(dataPara);
    }
    for (auto i: *dataPara) {
        Data::check(i);
    }
    delete dataPara;
    return result;
}

Data *Data::times(std::vector<Data *> *dataPara) {
    Data *result = NULL;
    if ((dynamic_cast<Integer *>((*dataPara)[0])) != NULL) {
        result = Integer::times(dataPara);
    }
    for (auto i: *dataPara) {
        Data::check(i);
    }
    delete dataPara;
    return result;
}

Data::Data() {
    cited = 0;
}

Data *Data::minus(std::vector<Data *> *dataPara) {
    Data *result = NULL;
    if ((dynamic_cast<Integer *>((*dataPara)[0])) != NULL) {
        result = Integer::minus(dataPara);
    }
    for (auto i: *dataPara) {
        Data::check(i);
    }
    delete dataPara;
    return result;
}

Data *Data::divide(std::vector<Data *> *dataPara) {
    Data *result = NULL;
    if ((dynamic_cast<Integer *>((*dataPara)[0])) != NULL) {
        result = Integer::divide(dataPara);
    }
    for (auto i: *dataPara) {
        Data::check(i);
    }
    delete dataPara;
    return result;
}

Data *Data::equal(std::vector<Data *> *dataPara) {
    Data *result = NULL;
    Data *a = (*dataPara)[0];
    Data *b = (*dataPara)[1];
    if (dynamic_cast<Integer *>(a) != NULL) {
        if (dynamic_cast<Integer *>(b) != NULL) {
            if (((Integer *) a)->value == ((Integer *) b)->value) {
                result = Data::trueData;
            } else {
                result = Data::falseData;
            }
        } else {
            result = Data::falseData;
        }
    } else {
        if (((Bool *) a)->value == ((Bool *) b)->value) {
            result = Data::trueData;
        } else {
            result = Data::falseData;
        }
    }
    for (auto i: *dataPara) {
        Data::check(i);
    }
    delete dataPara;
    return result;
}

Data *Data::bigger(std::vector<Data *> *dataPara) {
    Data *result = NULL;
    if ((dynamic_cast<Integer *>((*dataPara)[0]))->value
        > (dynamic_cast<Integer *>((*dataPara)[1]))->value) {
        result = Data::trueData;
    } else {
        result = Data::falseData;
    }
    for (auto i: *dataPara) {
        Data::check(i);
    }
    delete dataPara;
    return result;
}

Data *Data::smaller(std::vector<Data *> *dataPara) {
    Data *result = NULL;
    if ((dynamic_cast<Integer *>((*dataPara)[0]))->value
        < (dynamic_cast<Integer *>((*dataPara)[1]))->value) {
        result = Data::trueData;
    } else {
        result = Data::falseData;
    }
    for (auto i: *dataPara) {
        Data::check(i);
    }
    delete dataPara;
    return result;
}

Data *Data::mod(std::vector<Data *> *dataPara) {
    Data *result = NULL;
    result = new Integer(
            (dynamic_cast<Integer *>((*dataPara)[0]))->value
            % (dynamic_cast<Integer *>((*dataPara)[1]))->value
    );
    for (auto i: *dataPara) {
        Data::check(i);
    }
    delete dataPara;
    return result;
}

Data::Data(int) {
    cited = 1;
}

Data *Data::print(std::vector<Data *> *dataPara) {
    for (auto i: *dataPara) {
        i->print();
        std::cout << std::endl;
        Data::check(i);
    }
    delete dataPara;
    return Data::trueData;
}

Data *Data::display(std::vector<Data *> *dataPara) {
    for (auto i: *dataPara) {
        i->display();
        Data::check(i);
    }
    delete dataPara;
    return Data::trueData;
}

