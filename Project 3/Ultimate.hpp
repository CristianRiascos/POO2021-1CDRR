#ifndef ULTIMATE_H
#define ULTIMATE_H

#include "AttackType.hpp"

class Ultimate : public AttackType
{
    public:
        Ultimate() = default;
        ~Ultimate( ) {}; 

        int getDmg( int );
};

#endif