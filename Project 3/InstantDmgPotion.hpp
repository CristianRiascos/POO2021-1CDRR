#ifndef INSTANTDMGPOTION_H
#define INSTANTDMGPOTION_H

#include "Potion.hpp"

class InstantDmgPotion : public Potion
{
    public:
        InstantDmgPotion() = default;
        InstantDmgPotion( int ); //   int: resistencia
        ~InstantDmgPotion() {};

        void potionEffect( class Herz *, class Character * );  // Sobreescritura
};

#endif