#include "Weapon.hpp"

Weapon::Weapon( int dmg )
{
    this->dmg = dmg;
    endurance = 10;
}

int Weapon::getDmg()
{
    return dmg;
}