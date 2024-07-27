#ifndef __CMarathonAI_H__
#define __CMarathonAI_H__

#include "CSimpleAI.h"

class CMarathonAI : public CSimpleAI
{
public :
    CMarathonAI();

    virtual ~CMarathonAI();


    virtual void manageBullet(int, CBullet *);

    virtual void thinking();

    int lastPassedTime;
};



#endif
