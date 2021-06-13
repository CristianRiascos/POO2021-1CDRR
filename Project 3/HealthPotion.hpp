#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "Potion.hpp"

class HealthPotion : public Potion
{
    protected:
        int hpRecover;
    public:
        HealthPotion() = default;
        HealthPotion( int, int );   //  Primer int: vida que recupera. Segundo int: resistencia    
        ~HealthPotion() {};

};

#endif