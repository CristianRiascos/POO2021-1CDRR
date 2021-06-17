#include "Strong.hpp"


int Strong::getDmg( int dmgDone )
{
    // El daño del ataque débil se define por el 60% de su capacidad de ataque basico del atacante
    this->dmg = ( 60 * dmgDone ) / 100;
    return dmg;
}