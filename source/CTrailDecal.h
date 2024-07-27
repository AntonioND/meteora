#ifndef __CTrailDecal_H__
#define __CTrailDecal_H__

#include "CSprite.h"

class CTrailDecal : public CSprite
{
public :

    int lifetime;
    int alpha;
    int layer;
    int border;
    int height;

    u16 color;

    CTrailDecal();

    virtual ~CTrailDecal();

    virtual void thinking();

    virtual void draw(int offset);


};



#endif
