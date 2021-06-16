#ifndef BOW_H
#define BOW_H

#include "Weapon.hpp"

class Bow : public Weapon
{
    protected:
        identify code = BOW;
    public:
<<<<<<< HEAD
        Bow( int dmg );
=======
        Bow() = default;
        Bow( int, int );
>>>>>>> dd93c1afa9a3d9414c520b274104dbc1dff15c8b
        ~Bow();
};

#endif