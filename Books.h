//
// Created by andrea on 11/23/18.
//

#ifndef LAB6_ANDREAMENDOZA_BOOKS_H
#define LAB6_ANDREAMENDOZA_BOOKS_H

#include "Product.h"

class Books : public Product {
public:
    Books(const string &name, double weight, bool fragile, int code);

    int getCode() const;

    void setCode(int code);

private:
    int code;
};


#endif //LAB6_ANDREAMENDOZA_BOOKS_H
