#ifndef BOW_H
#define BOW_H

#include "Weapon.hpp"

class Bow : public Weapon
{
    protected:
        identify code = BOW;
    public:
        Bow() = default;
        Bow( int, int );
        ~Bow();

};

#endif