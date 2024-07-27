#ifndef __CPulseDecal_H__
#define __CPulseDecal_H__

#include "CDecal.h"

class CPulseDecal : public CDecal
{
public :

    int lifetime;
    int alpha;
    int layer;

    int alphaPulse;

    CPulseDecal();

    virtual ~CPulseDecal();

    virtual void thinking();

    virtual void draw(int offset);


};



#endif
