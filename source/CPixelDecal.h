#ifndef __CPixelDecal_H__
#define __CPixelDecal_H__

#include "CSprite.h"

class CPixelDecal : public CSprite
{
public :

    int lifetime;
    int alpha;
    int layer;

    CPixelDecal();

    virtual ~CPixelDecal();

    virtual void thinking();

    virtual void draw(int offset);


};



#endif
