#ifndef __CVreemdAI_H__
#define __CVreemdAI_H__

#include "CSimpleAI.h"

class CVreemdAI : public CSimpleAI
{
public :
    CVreemdAI();

    virtual ~CVreemdAI();
    
    virtual void thinking();
    
    int lastPassedTime;
};



#endif
