//
// Created by andrea on 11/23/18.
//

#ifndef LAB6_ANDREAMENDOZA_CLOTHES_H
#define LAB6_ANDREAMENDOZA_CLOTHES_H

#include <string>
#include "Product.h"

using std::string;

class Clothes : public Product {
public:
    Clothes(const string &name, double weight, bool fragile, const string &type);

    const string &getType() const;

    void setType(const string &type);

private:
    string type;

};


#endif //LAB6_ANDREAMENDOZA_CLOTHES_H
