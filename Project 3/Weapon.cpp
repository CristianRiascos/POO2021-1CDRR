#include "Weapon.hpp"

Weapon::Weapon( int dmg, int endurance )
{
    this->dmg = dmg;
    this->endurance = endurance;
}

int Weapon::getDmg()
{
    return dmg;
}