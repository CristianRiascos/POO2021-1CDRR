#ifndef BOW_H
#define BOW_H

#include "Weapon.hpp"

class Bow : public Weapon
{
    protected:

    public:
        Bow() = default;
        Bow( int );
        ~Bow();

};

#endif