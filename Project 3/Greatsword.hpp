#ifndef GREATSWORD_H
#define GREATSWORD_H

#include "Weapon.hpp"

class Greatsword : public Weapon
{
    protected:

    public:
        Greatsword() = default;
        Greatsword( int );
        ~Greatsword();

};

#endif