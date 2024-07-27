#ifndef __CDecal_H__
#define __CDecal_H__

#include "CSprite.h"

class CDecal : public CSprite
{
public :

    int lifetime;
    int alpha;
    int layer;

    CDecal();

    virtual ~CDecal();

    virtual void thinking();

    virtual void draw(int offset);


};



#endif
