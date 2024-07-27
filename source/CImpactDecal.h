#ifndef __CImpactDecal_H__
#define __CImpactDecal_H__

#include "CSprite.h"

class CImpactDecal : public CSprite
{
public :

    int lifetime;
    int alpha;
    int layer;
    int border;
    int height;

    u16 color;

    CImpactDecal(int weight = 5000);

    virtual ~CImpactDecal();

    virtual void thinking();

    virtual void draw(int offset);


};



#endif
