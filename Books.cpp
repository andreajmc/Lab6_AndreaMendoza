//
// Created by andrea on 11/23/18.
//

#include "Books.h"

Books::Books(const string &name, double weight, bool fragile, int code) : Product(name, weight, fragile), code(code) {}

int Books::getCode() const {
    return code;
}

void Books::setCode(int code) {
    Books::code = code;
}
