//
// Created by andrea on 11/23/18.
//

#include "Computer.h"

Computer::Computer(const string &name, double weight, bool fragile, const string &OS) : Electronics(name, weight,
                                                                                                    fragile), OS(OS) {}

const string &Computer::getOS() const {
    return OS;
}

void Computer::setOS(const string &OS) {
    Computer::OS = OS;
}


