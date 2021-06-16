#ifndef INSTANTDMGPOTION_H
#define INSTANTDMGPOTION_H

#include "Potion.hpp"

class InstantDmgPotion : public Potion
{
    protected:
        identify code = INSTANT_DMG;
    public:
        InstantDmgPotion() = default;
        InstantDmgPotion( int ); //   int: resistencia
        ~InstantDmgPotion() {};

};

#endif