#ifndef __CMeteor_H__
#define __CMeteor_H__

#include "CSprite.h"
#include "CBullet.h"

class CMeteor : public CBullet
{
public :
    CMeteor();

    virtual ~CMeteor();
//    CMeteor() {};
//    virtual void thinking();

    //float size;

    //virtual void draw(int offset);

    virtual void dead();

    virtual void setSize(double pSize, int forced) { size = pSize;}

//private:
//    int angle;

};



#endif
