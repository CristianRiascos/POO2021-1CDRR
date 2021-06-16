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
<<<<<<< HEAD
        int endurance = 10;  // Uses of the item
=======
        int endurance;  // Uses of the item
        identify code ;    // Código para identificar cada item

>>>>>>> dd93c1afa9a3d9414c520b274104dbc1dff15c8b
    public:
        Item();
        Item( int );
        ~Item() {}; 

        void reduceEndurance( Item * );
        int getEndurance();
        identify getCode();
};

#endif