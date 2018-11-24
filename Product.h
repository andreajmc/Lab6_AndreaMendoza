//
// Created by andrea on 11/23/18.
//

#ifndef LAB6_ANDREAMENDOZA_PRODUCT_H
#define LAB6_ANDREAMENDOZA_PRODUCT_H


#include <string>
using std::string;

class Product {

protected:
    string name;
    double weight;
    bool fragile;

public:
    Product();

    Product(const string &name, double weight, bool fragile);

    const string &getName() const;

    void setName(const string &name);

    double getWeight() const;

    void setWeight(double weight);

    bool isFragile() const;

    void setFragile(bool fragile);

};


#endif //LAB6_ANDREAMENDOZA_PRODUCT_H
