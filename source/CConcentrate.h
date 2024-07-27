#ifndef __CConcentrate_H__
#define __CConcentrate_H__

#include "CSprite.h"

class CConcentrate : public CSprite
{
public :

    int lifetime;
    int alpha;
    int layer;

    float decSize;

    CConcentrate();

    virtual ~CConcentrate();

    virtual void thinking();

    virtual void draw(int offset);


};



#endif
