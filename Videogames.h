//
// Created by andrea on 11/23/18.
//

#ifndef LAB6_ANDREAMENDOZA_VIDEOGAMES_H
#define LAB6_ANDREAMENDOZA_VIDEOGAMES_H


#include "Electronics.h"

class Videogames : public Electronics {
public:
    Videogames(const string &name, double weight, bool fragile, const string &developer);

    const string &getDeveloper() const;

    void setDeveloper(const string &developer);

protected:
    string developer;
};


#endif //LAB6_ANDREAMENDOZA_VIDEOGAMES_H
