//
// Created by andrea on 11/23/18.
//

#ifndef LAB6_ANDREAMENDOZA_BOX_H
#define LAB6_ANDREAMENDOZA_BOX_H

#include <vector>
using std::vector;

#include "Product.h"

class Box {
public:
    Box(vector<Product> &Stuff, bool fragile, double weight);

    Box();

    const vector<Product> &getStuff() const;

    void setStuff(const vector<Product> &Stuff);

    bool isFragile() const;

    void setFragile(bool fragile);

    double getWeight() const;

    void addStuff(Product);

    double setWeightT();

    virtual ~Box();

private:
    vector <Product> Stuff;
    bool fragile;
    double weight;

};


#endif //LAB6_ANDREAMENDOZA_BOX_H
