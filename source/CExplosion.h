#ifndef __CExplosion_H__
#define __CExplosion_H__

#include "CSprite.h"

class CExplosion : public CSprite
{
public :
    CExplosion(int size);

    virtual ~CExplosion();
//    CExplosion() {};
    virtual void thinking();

    virtual void draw(int offset);

//    virtual void draw(int offset);

};



#endif
