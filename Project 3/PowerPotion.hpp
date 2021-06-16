#ifndef POWERPOTION_H
#define POWERPOTION_H

#include "Potion.hpp"

class PowerPotion : public Potion
{
    protected:
        identify code = POWER;
    public:
        PowerPotion() = default;
        PowerPotion( int );     //  Int: resistencia
        ~PowerPotion() {};

};  

#endif