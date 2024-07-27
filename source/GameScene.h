#ifndef __GameScene_H__
#define __GameScene_H__

#include "CScene.h"
#include "GameCtrl.h"


#include "CBullet.h"
#include "CExplosion.h"

#include "bullet_png.h"
#include "meteor_png.h"
#include "spacebas_png.h"
#include "spacehaut_png.h"


#include <sstream>

#include "CSimpleAI.h"
#include "CDecal.h"

class GameScene : public CScene
{
public :
    GameScene();

    int isMarathon;

    int quake;

    virtual ~GameScene();

    virtual void render();

    static CFixed mana;
    static CFixed life;
    static CFixed shield;

    static CFixed ennemy_mana;
    static CFixed ennemy_life;
    static CFixed ennemy_shield;

    CFixed max_mana;
    CFixed mana_gain;

    static GameScene * _instance;


    static CFixed total_mana_earn;

    static int player_id;
    static int ennemy_id;

    void displayHUD();

    static CSimpleAI * ennemy_ai;

    void damage(CFixed dmg, CSprite * s);
    void damage_ennemy(CFixed dmg);

    string player_name;
    string enemy_name;



    //HUD DEFINITION
    CSprite * player_hud;
    CSprite * player_hud_jam;

    CSprite * ennemy_hud;
    CSprite * ennemy_hud_jam;

    int paused;
    int started;

    //END HUD DEFINITION

    //background sprite
    CSprite * background_haut;
    CSprite * background_basHQ;
    CSprite * background_bas;


    void preInit();


  static GameScene * getInstance ()
  {
    return _instance; // address of instance
  }

  void setEarthQuake( int equake) {
      if (equake > quake) {
      quake = equake;
      }
  }


  private:
    int shield_spawn;

};



#endif
