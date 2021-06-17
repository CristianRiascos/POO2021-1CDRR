#include "Weak.hpp"


int Weak::getDmg( int dmgDone )
{
    // El daño del ataque débil se define por el 40% de su capacidad de ataque basico del atacante
    this->dmg = ( 40 * dmgDone ) / 100;
    return dmg;
}