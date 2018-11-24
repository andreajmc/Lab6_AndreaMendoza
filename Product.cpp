//
// Created by andrea on 11/23/18.
//

#include "Product.h"

Product::Product(const string &name, double weight, bool fragile) : name(name), weight(weight), fragile(fragile) {}

const string &Product::getName() const {
    return name;
}

void Product::setName(const string &name) {
    Product::name = name;
}

double Product::getWeight() const {
    return weight;
}

void Product::setWeight(double weight) {
    Product::weight = weight;
}

bool Product::isFragile() const {
    return fragile;
}

void Product::setFragile(bool fragile) {
    Product::fragile = fragile;
}
