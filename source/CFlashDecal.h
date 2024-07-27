#ifndef __CFlashDecal_H__
#define __CFlashDecal_H__

#include "CSprite.h"

class CFlashDecal : public CSprite
{
public :

    int lifetime;
    int alpha;
    int layer;
    int border;
    int height;

    u16 color;

    CFlashDecal();

    virtual ~CFlashDecal();

    virtual void thinking();

    virtual void draw(int offset);


};



#endif
