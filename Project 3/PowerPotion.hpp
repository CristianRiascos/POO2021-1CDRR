#ifndef POWERPOTION_H
#define POWERPOTION_H

#include "Potion.hpp"

class PowerPotion : public Potion
{
    protected:
        int dmgIncrease;
        string code = "FF0000";     // Código hexadecimal rojo
    public:
        PowerPotion() = default;
        PowerPotion( int, int );     //  Primer int: daño que aumenta. Segundo int: resistencia
        ~PowerPotion() {};

};  

#endif