#include "Potion.hpp"

Potion::Potion( int endurance )
{
    this->endurance = endurance;
}

string Potion::getCode()
{
    return code;
}