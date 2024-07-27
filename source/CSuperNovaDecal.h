#ifndef __CSuperNovaDecal_H__
#define __CSuperNovaDecal_H__

#include "CSprite.h"

class CSuperNovaDecal : public CSprite
{
public :

    int lifetime;
    int alpha;
    int layer;
    int border;
    int height;

    u16 color;

    CSuperNovaDecal(int weight = 5000);

    virtual ~CSuperNovaDecal();

    virtual void thinking();

    virtual void draw(int offset);


};



#endif
