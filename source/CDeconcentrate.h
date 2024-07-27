#ifndef __CDeconcentrate_H__
#define __CDeconcentrate_H__

#include "CSprite.h"

class CDeconcentrate : public CSprite
{
public :

    int lifetime;
    int alpha;
    int layer;
    
    float decSize;
    
    CDeconcentrate();

    virtual ~CDeconcentrate();

    virtual void thinking();

    virtual void draw(int offset);


};



#endif
