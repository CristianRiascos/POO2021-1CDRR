#ifndef BOSS_H
#define BOSS_H

#include "Character.hpp"

class Boss : public Character
{
    public:
    Boss( int );
    Boss( float );
    ~Boss();
};

#endif