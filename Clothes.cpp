//
// Created by andrea on 11/23/18.
//

#include "Clothes.h"

Clothes::Clothes(const string &name, double weight, bool fragile, const string &type) : Product(name, weight, fragile),
                                                                                        type(type) {}

const string &Clothes::getType() const {
    return type;
}

void Clothes::setType(const string &type) {
    Clothes::type = type;
}

