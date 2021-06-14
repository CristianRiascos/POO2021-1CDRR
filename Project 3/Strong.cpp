#include "Strong.hpp"


int Strong::getDmg( Character * character )
{
    // El daño del ataque débil se define por el 60% de su capacidad de ataque basico del atacante
    dmg = ( 60 * character->getDmg() ) / 100;
    return dmg;
}