//
// Created by andrea on 11/23/18.
//

#ifndef LAB6_ANDREAMENDOZA_COMPUTER_H
#define LAB6_ANDREAMENDOZA_COMPUTER_H


#include "Electronics.h"

class Computer : public Electronics {
public:
    Computer(const string &name, double weight, bool fragile, const string &OS);

    const string &getOS() const;

    void setOS(const string &OS);

private:
    string OS;


};


#endif //LAB6_ANDREAMENDOZA_COMPUTER_H
