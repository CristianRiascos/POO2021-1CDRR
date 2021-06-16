#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "Potion.hpp"

class HealthPotion : public Potion
{
    protected:
        identify code = HEALTH;

    public:
        HealthPotion() = default;
        HealthPotion( int hpheal );   //  Segundo int: resistencia    
        ~HealthPotion() {};

};

#endif