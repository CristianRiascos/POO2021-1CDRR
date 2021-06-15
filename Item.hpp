#ifndef ITEM_H
#define ITEM_H

class Item
{
    protected:
        int endurance;  // Uses of the item
    public:
        Item();
        Item( int );
        ~Item() {}; 

        void reduceEndurance( Item * );
        int getEndurance();
};

#endif