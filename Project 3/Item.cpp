#include "Item.hpp"

Item::Item()
{
}

void Item::reduceEndurance( Item * item )
{
    item->endurance--;
}

int Item::getEndurance()
{
    return endurance;
}

identify Item::getCode()
{
    return code;
}

int Item::getDmg()
{
    return dmg;
}

