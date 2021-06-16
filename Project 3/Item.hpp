#ifndef ITEM_H
#define ITEM_H

#include <string>

enum identify
{
    HEALTH,
    POWER,
    ESCAPE,
    INSTANT_DMG,
    BOW,
    GREATSWORD,
    SCIMITAR
};

class Item
{
    protected:
        int endurance = 10;  // Uses of the item
        identify code ;    // Código para identificar cada item

    public:
        Item();
        Item( int );
        ~Item() {}; 

        void reduceEndurance( Item * );
        int getEndurance();
        identify getCode();
};

#endif