//
// Created by andrea on 11/23/18.
//

#ifndef LAB6_ANDREAMENDOZA_ELECTRONICS_H
#define LAB6_ANDREAMENDOZA_ELECTRONICS_H


#include "Product.h"

class Electronics : public Product {
public:
    Electronics(const string &name, double weight, bool fragile);
};


#endif //LAB6_ANDREAMENDOZA_ELECTRONICS_H
