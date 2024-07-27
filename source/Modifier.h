#ifndef __Modifier_H__
#define __Modifier_H__

#include "CSprite.h"


class Modifier : public CSprite
{

protected:
    CSprite * _parent;

public :

    Modifier(CSprite * _parent);

    virtual ~Modifier();

    virtual void thinking();

    virtual void draw(int offset);

    virtual void duplicateAndAttachTo(CSprite *);

};



#endif
