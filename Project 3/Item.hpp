#ifndef ITEM_H
#define ITEM_H

class Item
{
    protected:
        int endurance = 10;  // Uses of the item
    public:
        Item();
        Item( int );

        int reduceEndurance( Item );
};

#endif