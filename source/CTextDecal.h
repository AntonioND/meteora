#ifndef __CTextDecal_H__
#define __CTextDecal_H__

#include "CSprite.h"

class CTextDecal : public CSprite
{
public :


    CTextDecal(string);

    virtual ~CTextDecal();

    virtual void thinking();

    virtual void draw(int offset);
    
    u16 color;
    
    string text;


};



#endif
