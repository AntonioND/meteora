#ifndef __CChargesShotSpell1_H__
#define __CChargesShotSpell1_H__

#include "CSprite.h"
#include "CSpriteCollidable.h"

class CChargesShotSpell2 : public CSpriteCollidable
{
public :

    int lifetime;
    int alpha;
    int layer;

    int nbclicked;

    CChargesShotSpell2();

    virtual ~CChargesShotSpell2();

    virtual void thinking();

    virtual void draw(int offset);

    virtual void clicked(int x, int y);

};



#endif
