//
// Created by andrea on 11/23/18.
//

#include "Box.h"
#include <iostream>
using std::endl;
using std::cout;
#include <vector>
using std::vector;

Box::Box(vector<Product> &Stuff, bool fragile, double weight) : Stuff(Stuff), fragile(fragile), weight(weight) {}

Box::Box() {}

const vector<Product> &Box::getStuff() const {
    return Stuff;
}

void Box::setStuff(const vector<Product> &Stuff) {
    Box::Stuff = Stuff;
}

bool Box::isFragile() const {
    return fragile;
}

void Box::setFragile(bool fragile) {
    Box::fragile = fragile;
}

double Box::getWeight() const {
    return weight;
}

double Box::setWeightT() {
    double weightT = 0;
    for (auto &item : Stuff) {
        weightT += item.getWeight();
    }
    return weightT;
}

void Box::addStuff(Product p)  {
    Stuff.push_back(p);
    weight = Box::setWeightT();
    cout<<endl<<"¡Producto agregado exitósamente!";
}

Box::~Box() {

}


