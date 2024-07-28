#ifndef __GAMECTRL_H__
#define __GAMECTRL_H__
//#include <PA9.h>
#include "CSprite.h"

#include <vector>
#include <list>


#define GC_playSound(sound) GameCtrl::getSharedObject()->playSound((void*)sound, (u32)sound##_size)
#define GC_playSoundLoop(sound) GameCtrl::getSharedObject()->playSoundLoop((void*)sound, (u32)sound##_size)

#define UL_MSGBOX_TOUCHPAD_SUPPORT

using namespace std;

  class GameCtrl
  {
  public:



      static GameCtrl* getSharedObject();
      static int curr_channel_loop_1;
      static int curr_channel_loop_2;

      u8 getNewSpriteId();
      void addSprite(CSprite * c);
      void delSprite(CSprite * c);

      void addDecoSprite(CSprite * c);
      void delDecoSprite(CSprite * c);

      void flushSprites();


      CODE_IN_ITCM void addCollisionMap(CSprite *c, int rangeDown);
      CODE_IN_ITCM void delCollisionMap(CSprite *c, int rangeDown);

      CODE_IN_ITCM void update();
      CODE_IN_ITCM void draw(int offset);

      long int getPassedTime() { return mPassedTime;}
      void resetPassedTime() { mPassedTime=0;}

      int getSpriteCount() { return _spriteNumber; }
      int getTotalSpriteCount() { return (_spriteNumber+_spriteDecoNumber); }

      void attract(int x, int y);

      CODE_IN_ITCM void testCollision();
      void testClicked(CSprite * cursor, int rangeDown, int rangeUp);

      void removeSprites(int rangeDown, int rangeUp);

      list<CSprite *> _collisionList[600];

      void playSound (const void *data, s32 length);
      int playSoundLoop (const void *data, s32 length);

      CSprite * _spriteList[1024];

      u32 _spriteNumber;

      CSprite * _spriteDecoList[2048];
      u32 _spriteDecoNumber;

      int getMicVolume() {
            micMiddle = (CFixed((int)PA_MicGetVol())+micMiddle*CFixed(3))/CFixed(4);
            return (int)micMiddle;
      }

      void drawOnScreen(int x, int y, string s);
      void drawPersistentOnScreen(int x, int y, string s);

      int messageBox(const char *text, const char *title, int nbButtons, UL_MSGBOX_BUTTON *buttons);


  protected:
      GameCtrl();
      GameCtrl(const GameCtrl&);
      GameCtrl& operator= (const GameCtrl&);
  private:
      static GameCtrl* pinstance;
      u8 spriteMaxId;
      //vector<CSprite *> mSpriteList;

      CFixed micMiddle;



      long int mPassedTime;
  };

#endif
