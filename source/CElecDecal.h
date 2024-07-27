#ifndef __CElecDecal_H__
#define __CElecDecal_H__

#include "CSprite.h"

class CElecDecal : public CSprite
{
public :
    CElecDecal();

    virtual ~CElecDecal();
//    CElecDecal() {};
    virtual void thinking();

    virtual void draw(int offset);
    
    int count;

//    virtual void draw(int offset);

};



#endif
