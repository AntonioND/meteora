#ifndef __CSPRITE_H__
#define __CSPRITE_H__

#include <PA9.h>

#include <ulib/ulib.h>


#define BORDER_HEIGHT 32
#define TOTAL_SCREEN_HEIGHT (SCREEN_HEIGHT * 2 + BORDER_HEIGHT)

#include <string>
#include <map>


//Make it a FixedPoint point value (1 = 256, 0.5 = 128, etc.)
#define FIX(x)		((x) << 8)
//Return the real value of a FixedPoint point
#define UNFIX(x)	((x) >> 8)


#define PreLoadTex(tex) { \
                CSprite::preLoadTex(#tex,tex,tex##_size,UL_PF_PAL8);\
                }

#define loadTex(csprite,tex) { \
                csprite->initTex(#tex,tex,tex##_size,UL_PF_PAL8);\
                }

#define loadTex16col(csprite,tex) { \
                csprite->initTex(#tex,tex,tex##_size,UL_PF_PAL4);\
                }

#define loadTexAlphaPNG(csprite,tex) { \
                csprite->initTex(#tex,tex,tex##_size,UL_PF_PAL5_A3);\
                }

#define ulSetImageTileSizeNoStretch(img, x0, y0, x1, y1)   ({ (img)->offsetX0 = x0; (img)->offsetY0 = y0; (img)->offsetX1 = (x0) + (x1); (img)->offsetY1 = (y0) + (y1); })

#include "CFixed.h"

#define POLY_DECAL_SHADING (1<<4)

#define OWNER_MASK 15
#define MERGEABLE 16
#define ATTRACTIBLE 32
#define STICKY_SPRT 64


void drawFillRect (s16 x0, s16 y0, s16 x1, s16 y1, UL_COLOR color);
void ulSetAlphaDecal(UL_SPECIAL_EFFECT effect, int coeff, int polygroup);


class GameCtrl;


enum sprite_status
{
    S_ACTIVE,
    S_DYING,
    S_DIED,
    S_SPAWN

};

using namespace std;

//Class handling a ball
class CSprite	{
private:

	static int nbSprites;

	//u16 color;

protected:
	GameCtrl * gc;

public:
    CSprite * _modifier;
    static u32 _uniq_id;
    static u32 _sprite_in_mem;
    u32 _sprite_id;



    long angle;

    UL_IMAGE * spriteTex;

    u32 type;

    double size;
    CFixed x, y;

    //int realX, realY;

    int rangeUp, rangeDown;

   CSprite(int x=0, int y=0, int angle=0, int mFrameNumber = 1);
   virtual ~CSprite();

   void handle();
   virtual void draw(int offset);
   void setColor(u16 color);


    static map<string, int> _resourcesNbMap;
    static map<string, UL_IMAGE *> _resourcesMap;

    void initTex(string texName, const u8 * texRef, const u32 * texSize ,int pixelformat);

    static void preLoadTex(string texName, const u8 * texRef, const u32 * texSize ,int pixelformat);
    static void flushTex();

    void addModifier(CSprite * c) {
            if (_modifier != NULL) {
                    //delete(_modifier);
                    _modifier->addModifier(c);
            } else {
                _modifier = c;
            }
            /*
            _modifier = c;*/

    }


    /** old initializator */


      sprite_status getStatus() { return mStatus; }
  void setStatus(sprite_status S) { mStatus=S; mLastThinkupdate=0; }

  sprite_status mStatus;

    int mType;
    int getType() { return mType; }


  CFixed getx() {return x;}
  CFixed gety() {return y;}

  void setX(CFixed px) {
    x= px;
  }
  void setY(CFixed py) {
    y= py;
  }

  CFixed getX() {return x;}
  CFixed getY() {return y;}

  CFixed getVelX() {return velX;}
  CFixed getVelY() {return velY;}

  void xadd(CFixed nr) { x=x+nr; }
  void yadd(CFixed nr) { y=y+nr; }
  void xset(CFixed nr) { x=nr; }
  void yset(CFixed nr) { y=nr; }
      int mFrame;

      CFixed mOldX, mOldY;
      CFixed velX,velY;
      int nextThink;

        int getLife() { return life; }
  void setLife(int xx) { life =xx;}

   int life;
      int mRadius;
            long mLastupdate;
      long mLastThinkupdate;

          int getRadius() { return this->spriteTex->sizeX ; }
          int getRealSize() { return (int)(this->spriteTex->sizeX*size) ; }
  //virtual void setRadius(int);

  virtual void dead();
  virtual void dead(CSprite * parent);

        void initVar();

  virtual void hit(CSprite * parent);
  virtual void clicked(int x, int y) {};
  CODE_IN_ITCM  short int collide(CSprite * object1);

  virtual void update();
  virtual void updatePos();
  virtual void thinking();



  void setVel(CFixed xx, CFixed yy) { velX=xx; velY=yy; }
  void setVelX(CFixed xx) { velX=xx;  }
  void setVelY(CFixed yy) { velY=yy;  }

  int mFrameNumber;
  int frame;
};


#endif
