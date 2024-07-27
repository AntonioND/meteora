#ifndef __CLineDecal_H__
#define __CLineDecal_H__

#include "CSprite.h"

class CLineDecal : public CSprite
{
public :

    int lifetime;
    int alpha;
    int layer;
    int border;
    int height;
    
    int x1, y1, x2, y2;

    u16 color;

    CLineDecal();

    virtual ~CLineDecal();

    virtual void thinking();

    virtual void draw(int offset);


};



#endif
