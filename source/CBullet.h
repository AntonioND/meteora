#ifndef __CBULLET_H__
#define __CBULLET_H__

#include "CSpriteCollidable.h"

#define float_HAS_LONG




class CBullet : public CSpriteCollidable
{
public :
    u16 color;

    CBullet(int owner = 0);

    double weight;

    virtual ~CBullet();
//    CBullet() {};
    virtual void thinking();



    virtual void draw(int offset);

    virtual void dead();

    virtual void hit (CSprite *);

    virtual void setSize(double pSize, int forced = 0);

    void addDecals();

    virtual void clicked(int x, int y);

    void changeOwner(int id);

    void merge(CBullet *s);

    int electrified;

};



#endif
