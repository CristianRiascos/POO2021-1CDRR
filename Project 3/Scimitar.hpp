#ifndef SCIMITAR_H
#define SCIMITAR_H

#include "Weapon.hpp"

class Scimitar : public Weapon
{
    protected:

    public:
        Scimitar() = default;
        Scimitar( int );
        ~Scimitar();

};

#endif