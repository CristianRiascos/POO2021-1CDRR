#ifndef GREATSWORD_H
#define GREATSWORD_H

#include "Weapon.hpp"

class Greatsword : public Weapon
{
    protected:
        identify code = GREATSWORD;
    public:
        Greatsword() = default;
        Greatsword( int, int );     
        ~Greatsword();

};

#endif