//
// Created by fugoes on 12/2/16.
//

#include "Integer.h"

Integer::Integer(const std::string &str) {
    std::stringstream temp;
    if (str[0] == '-') {
        isPositive = false;
        temp << str.substr(1, str.length() - 1);
    } else {
        isPositive = true;
        temp << str;
    }
    temp >> abs;
}

Integer::~Integer() {}

void Integer::print() {
    if (!isPositive) {
        std::cout << "-";
    }
    std::cout << abs;
}

void Integer::plus(Integer *b) {
    if (this->isPositive) {
        if (b->isPositive) {
            this->abs += b->abs;
        } else {
            if (this->abs >= b->abs) {
                this->abs -= b->abs;
            } else {
                this->isPositive = false;
                this->abs = b->abs - this->abs;
            }
        }
    } else {
        if (b->isPositive) {
            if (this->abs <= b->abs) {
                this->isPositive = true;
                this->abs = b->abs - this->abs;
            } else {
                this->abs -= b->abs;
            }
        } else {
            this->abs += b->abs;
        }
    }
}

void Integer::times(Integer *b) {
    this->abs *= b->abs;
    if (!b->isPositive) this->isPositive = !this->isPositive;
}

bool Integer::bigger(Integer *b) {
    if (this->isPositive) {
        if (b->isPositive) {
            return this->abs > b->abs;
        } else {
            return true;
        }
    } else {
        if (b->isPositive) {
            return false;
        } else {
            return this->abs < b->abs;
        }
    }
}

bool Integer::equal(Integer *b) {
    return this->isPositive == b->isPositive && this->abs == b->abs;
}

void Integer::minus(Integer *b) {
    b->isPositive = !b->isPositive;
    return plus(b);
}
