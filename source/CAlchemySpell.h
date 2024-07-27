#ifndef __CAlchemySpell_H__
#define __CAlchemySpell_H__

#include "CSprite.h"
#include "CSpriteCollidable.h"

class CAlchemySpell : public CSpriteCollidable
{
public :

    int lifetime;
    int alpha;
    int layer;

    int nbclicked;

    CAlchemySpell();

    virtual ~CAlchemySpell();

    virtual void thinking();

    virtual void draw(int offset);

    virtual void clicked(int x, int y);

};



#endif
