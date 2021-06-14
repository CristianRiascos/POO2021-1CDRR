#include "Weak.hpp"


int Weak::getDmg( Character * character )
{
    // El daño del ataque débil se define por el 40% de su capacidad de ataque basico del atacante
    dmg = ( 40 * character->getDmg() ) / 100;
    return dmg;
}