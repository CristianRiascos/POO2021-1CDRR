#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "Potion.hpp"

class HealthPotion : public Potion
{
    protected:
        int hpHeal;
    public:
        HealthPotion() = default;
        HealthPotion( int );   //  Segundo int: resistencia    
        ~HealthPotion() {};

        void potionEffect( Herz *, Character * );   // Usa poción de vida

};

#endif