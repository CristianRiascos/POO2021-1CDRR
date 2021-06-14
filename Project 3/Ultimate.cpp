#include "Ultimate.hpp"

int Ultimate::getDmg( Character * character )
{
    // El daño del ataque débil se define por el 100% de su capacidad de ataque basico del atacante
    dmg = character->getDmg();
    return dmg;
}