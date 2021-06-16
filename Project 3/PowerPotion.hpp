#ifndef POWERPOTION_H
#define POWERPOTION_H

#include "Potion.hpp"

class PowerPotion : public Potion
{
    public:
        PowerPotion() = default;
        ~PowerPotion() {};

        void potionEffect( class Herz *, class Character * );  // Sobreescritura

};  

#endif