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

