#ifndef ITEM_H
#define ITEM_H

class Item
{
    protected:
        int endurance;  // Uses of the item
    public:
        Item();
        
        int reduceEndurance( Item );
};

#endif