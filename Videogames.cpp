//
// Created by andrea on 11/23/18.
//

#include "Videogames.h"

Videogames::Videogames(const string &name, double weight, bool fragile, const string &developer) : Electronics(name,
                                                                                                               weight,
                                                                                                               fragile),
                                                                                                   developer(
                                                                                                           developer) {}

const string &Videogames::getDeveloper() const {
    return developer;
}

void Videogames::setDeveloper(const string &developer) {
    Videogames::developer = developer;
}
