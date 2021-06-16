#ifndef INSTANTDMGPOTION_H
#define INSTANTDMGPOTION_H

#include "Potion.hpp"

class InstantDmgPotion : public Potion
{
    public:
        InstantDmgPotion() = default;
        ~InstantDmgPotion() {};

        void potionEffect( class Herz *, class Character * );  // Sobreescritura
};

#endif