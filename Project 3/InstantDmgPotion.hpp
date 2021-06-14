#ifndef INSTANTDMGPOTION_H
#define INSTANTDMGPOTION_H

#include "Potion.hpp"

class InstantDmgPotion : public Potion
{
    protected:
        int dmg;
        string code = "ff8000";     // Código hexadecimal naranja
    public:
        InstantDmgPotion() = default;
        InstantDmgPotion( int, int ); //  Primer int: daño instantaneo que hace a los enemigos. Segundo int: resistencia
        ~InstantDmgPotion() {};
};

#endif