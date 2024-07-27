#ifndef __SpellItem_H__
#define __SpellItem_H__

#include "../CDecal.h"
#include "../GameCtrl.h"
#include "../GameScene.h"
#include "../CBullet.h"

class SpellItem : public CDecal
{
public :
    SpellItem();
    int status;

    CFixed mana;

    char str[10];

    int lastPressed;
    int interval;

    virtual ~SpellItem();
//    SpellItem() {};
    virtual void thinking();

    virtual short int testCollision(int, int);

    virtual void draw(int offset);

        void show() {
        status =1;
        nextThink = 1;

    }
    void hide() {
        status = -1;
        alpha = 1;
        nextThink = 4000;
    }

    virtual void isPressed() {

    }

//    virtual void draw(int offset);

};



#endif
