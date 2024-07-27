#ifndef __ModifierBlast_H__
#define __ModifierBlast_H__

#include "Modifier.h"

class ModifierBlast : public Modifier
{
public :
    ModifierBlast(CSprite *);

    virtual ~ModifierBlast();
    void thinking();

    CFixed velY;
};



#endif
