#ifndef INSTANTDMGPOTION_H
#define INSTANTDMGPOTION_H

#include "Potion.hpp"

class InstantDmgPotion : public Potion
{
    protected:
        int dmg;
    public:
        InstantDmgPotion() = default;
        InstantDmgPotion( int, int ); //  Primer int: daño instantaneo que hace a los enemigos. Segundo int: resistencia
        ~InstantDmgPotion() {};
};

#endif