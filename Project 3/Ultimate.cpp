#include "Ultimate.hpp"

int Ultimate::getDmg( int dmgDone )
{
    // El daño del ataque débil se define por el 100% de su capacidad de ataque basico del atacante
    this->dmg = dmgDone;
    return dmg;
}