#ifndef __CVreemdSprite_H__
#define __CVreemdSprite_H__

#include "CSprite.h"
#include "CBullet.h"

class CVreemdSprite : public CBullet
{
public :
    CVreemdSprite();

    virtual ~CVreemdSprite();
//    CVreemdSprite() {};
//    virtual void thinking();

    //float size;

    //virtual void draw(int offset);

    virtual void dead();

    virtual void setSize(double pSize) { size = pSize;}

//private:
//    int angle;

};



#endif
