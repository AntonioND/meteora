#ifndef __FadingDecal_H__
#define __FadingDecal_H__

#include "CSprite.h"

class FadingDecal : public CSprite
{
public :

    int lifetime;
    int alpha;
    int layer;
    int border;
    int height;

    u16 color;

    FadingDecal();

    virtual ~FadingDecal();

    virtual void thinking();

    virtual void draw(int offset);


};



#endif
