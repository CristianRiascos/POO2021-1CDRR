#ifndef ITEM_H
#define ITEM_H

class Item
{
    protected:
        int endurance;  // Uses of the item
    public:
        Item();
        Item( int );

        int reduceEndurance( Item );
};

#endif