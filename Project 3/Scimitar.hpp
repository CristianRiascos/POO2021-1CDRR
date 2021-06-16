#ifndef SCIMITAR_H
#define SCIMITAR_H

#include "Weapon.hpp"

class Scimitar : public Weapon
{
    protected:
        identify code = SCIMITAR;
    public:
        Scimitar() = default;
        Scimitar( int, int );
        ~Scimitar();

};

#endif