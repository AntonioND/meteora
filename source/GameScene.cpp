/*

    Sprite class for player ship

*/

#include "GameScene.h"

#include <cstdlib>
#include <time.h>
#include "explosion.h"
#include "small_explosion.h"

#include "explode.h"

#include "beavis2_music.h"

#include "error_sound.h"

#include "SpellItems/SpellItem.h"
#include "SpellItems/MultipleShot.h"
#include "SpellItems/MultipleShotLvl2.h"
#include "SpellItems/ChargeShot.h"
#include "SpellItems/BlastShield.h"
#include "SpellItems/SacrificeSpell.h"
#include "SpellItems/SingleShot.h"
#include "SpellItems/ChangeSideSpell.h"
#include "SpellItems/RaiseManaRateSpell.h"
#include "SpellItems/RaiseMaxManaSpell.h"
#include "SpellItems/ChargeShotLvl2.h"
#include "SpellItems/ChargeShotLvl3.h"
#include "SpellItems/ShrapnelShot.h"

#include "GameCtrl.h"

#include "ScoreScene.h"
#include "icyplanet.h"
#include "redplanet.h"

#include "spacebas_hires.h"

#include "player_hud_pic.h"
#include "player_hud_jam_pic.h"

#include "ennemy_hud_pic.h"
#include "ennemy_hud_jam_pic.h"

#include "bullet_small.h"

#include "protect.h"

#include "CFlashDecal.h"
#include "FadingDecal.h"

#include "CDeconcentrate.h"

#include "invoc_final_sound.h"

#include "meteor.h"


CFixed GameScene::mana;
CFixed GameScene::shield;
CFixed GameScene::life;

CFixed GameScene::ennemy_mana;
CFixed GameScene::ennemy_shield;

CFixed GameScene::total_mana_earn;

CFixed GameScene::ennemy_life;

CSimpleAI * GameScene::ennemy_ai = NULL;

GameScene * GameScene::_instance = NULL;


int GameScene::player_id =1;
int GameScene::ennemy_id =2;



GameScene::GameScene(): CScene()  {

    paused = 0;
    started = 1;

    //CScene::CScene();
    mana = CFixed(300);
    life = CFixed(500);
    shield = CFixed(100);

    ennemy_mana = CFixed(300);
    //ennemy_life = CFixed(500);
    ennemy_shield = CFixed(100);

    //total_mana_spend = CFixed(0);
    total_mana_earn = CFixed(0);

    max_mana = CFixed(1000);
    mana_gain = CFixed(0.4);

    _instance = this;

    shield_spawn = 0;

    isMarathon = 0;

    GameScene::player_id =PA_Rand()%5+1;

    GameScene::ennemy_id = GameScene::player_id;

    while (GameScene::ennemy_id == GameScene::player_id) {
        GameScene::ennemy_id =PA_Rand()%5+1;
    }

    quake = 0;

    background_basHQ = NULL;
    background_haut = NULL;
    background_bas = NULL;

    player_name = string((char *)PA_UserInfo.Name);

    enemy_name = "Enemy";
}

GameScene::~GameScene() {
        ennemy_ai = NULL;
}

void GameScene::damage(CFixed dmg, CSprite * s) {
    if ((int)shield > (int)dmg) {


           ulSetImageTint(player_hud->spriteTex, RGB15(0,255,0));
	       ulSetImageTint(player_hud_jam->spriteTex, RGB15(0,255,0));

                shield = shield - dmg;

                CDeconcentrate * cc;
                cc = new CDeconcentrate();
                cc->setX(s->x);
                cc->setY(s->y);
                GameCtrl::getSharedObject()->addDecoSprite(cc);
                //addDecals();

                if (GameCtrl::getSharedObject()->getPassedTime() - shield_spawn  > 30 ) {

                shield_spawn = GameCtrl::getSharedObject()->getPassedTime();

                CDecal * bulletY= new CDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
                bulletY->setX(128);
                bulletY->setY(SCREEN_HEIGHT*2+BORDER_HEIGHT-40);
                bulletY->setVel(0,0);
                bulletY->nextThink =1;
                bulletY->layer = 6;
                loadTex16col(bulletY,protect)

                GameCtrl::getSharedObject()->addDecoSprite(bulletY);






                }


            return;


    }

    ulSetImageTint(player_hud->spriteTex, RGB15(255,0,0));
    ulSetImageTint(player_hud_jam->spriteTex, RGB15(255,0,0));

    life = life - (dmg - shield);
    shield = CFixed(0);

}

void GameScene::damage_ennemy(CFixed dmg) {
    if ((int)ennemy_shield > (int)dmg) {

           ulSetImageTint(ennemy_hud->spriteTex, RGB15(0,255,0));
	       ulSetImageTint(ennemy_hud_jam->spriteTex, RGB15(0,255,0));

            ennemy_shield = ennemy_shield - dmg;
            return;
    }


    ulSetImageTint(ennemy_hud->spriteTex, RGB15(255,0,0));
    ulSetImageTint(ennemy_hud_jam->spriteTex, RGB15(255,0,0));

    ennemy_life = ennemy_life - (dmg - ennemy_shield);
    ennemy_shield = CFixed(0);


}


//local function for displayHUD
u16 getColorForLife(int life) {
    int r;
    int g;
    int b = 0;


    if (life > 400 ) {
            return RGB15(0,255,b);
    }

    if (life > 200) {
            life = (life-300)*255/200;
            r = life;
            g = 255;
            return  RGB15(r,g,b);
    }

    if (life <= 200) {
            life = (life)*255/200;
            r = 255;
            g = 255-life;
            return  RGB15(r,g,b);
    }

    if (life < 0 ) {
        return RGB15(255,0,b);
    }



}

void GameScene::displayHUD() {



            ulSetAlpha(UL_FX_ALPHA, 15+PA_Rand()%5, 5);
            player_hud_jam->frame = GameCtrl::getSharedObject()->getPassedTime()%3;
            player_hud_jam->draw(0);

            ennemy_hud_jam->frame = GameCtrl::getSharedObject()->getPassedTime()%2;
            ennemy_hud_jam->draw(0);

            ulSetAlpha(UL_FX_DEFAULT, 0, 0);




            player_hud->draw(0);
            ennemy_hud->draw(0);


            /*ulSetAlpha(UL_FX_ALPHA, 12, 5);
            ulDrawFillRect(0, 0, 80, 40, RGB15(180,0,0));
            ulDrawFillRect(176, 0, 256, 40, RGB15(0,0,180));



            ulSetAlpha(UL_FX_DEFAULT, 0, 0);

            ulDrawFillRect(80, 0, 81, 40, RGB15(255,0,0));
            ulDrawFillRect(0, 39, 81, 40, RGB15(255,0,0));


            ulDrawFillRect(175, 0, 176, 40, RGB15(0,0,255));
            ulDrawFillRect(175, 39, 256, 40, RGB15(0,0,255));
            */


            ulSetTextColor((unsigned)RGB15(80,80,255));
            ulDrawString(155, 15, player_name.c_str());

            ulSetTextColor((unsigned)RGB15(80,80,255));
            ostringstream manashow;
            manashow << ""<< (int)GameScene::mana <<"/"<< (int)max_mana;
            ulDrawString(155, 25, manashow.str().c_str());

            ulSetTextColor((unsigned)RGB15(0,255,0));
            ostringstream shieldshow;
            shieldshow << ""<< (int)GameScene::shield<< "/100";
            ulDrawString(155, 35, shieldshow.str().c_str());

            ulSetTextColor((unsigned)RGB15(255,255,255));
            ostringstream lifeshow;
            lifeshow << ""<< (int)GameScene::life << "/500";
            ulDrawString(210, 35, lifeshow.str().c_str());

            ulDrawFillRect(155, 45, 155+80,47 , RGB15(50,50,50));
            ulDrawFillRect(155, 45, 155+80*((int) life+(int)shield)/600,47 , RGB15(0,0,255));
            ulDrawFillRect(155, 45, 155+80*((int) life)/600,47 , RGB15(40,40,255));

            if (!isMarathon) {

                ostringstream emanashow;
                ulSetTextColor(RGB15(255,0,0));
                ulDrawString(15, 15, enemy_name.c_str());


                ulSetTextColor(RGB15(0,255,0));
                ostringstream eshieldshow;
                eshieldshow << ""<< (int)GameScene::ennemy_shield<< "/100";
                ulDrawString(15, 25, eshieldshow.str().c_str());

                ulSetTextColor(RGB15(80,80,255));
                emanashow << ""<< (int)GameScene::ennemy_mana;
                ulDrawString(65, 25, emanashow.str().c_str());

                ulSetTextColor(RGB15(255,255,255));
                ostringstream elifeshow;
                if ((int)GameScene::ennemy_life > 0) {
                    elifeshow << ""<< (int)GameScene::ennemy_life<< "/500";
                } else {
                    elifeshow << ""<< "0"<< "/500";
                }
                ulDrawString(15, 35, elifeshow.str().c_str());

                ulDrawFillRect(15, 45, 15+80,47 , RGB15(50,50,50));
                ulDrawFillRect(15, 45, 15+80*((int)ennemy_life+(int)ennemy_shield)/600,47 , RGB15(255,0,0));
                ulDrawFillRect(15, 45, 15+80*((int)ennemy_life)/600,47 , RGB15(255,40,40));
            } else {
                ulSetTextColor(RGB15(255,0,0));
                ulDrawString(15, 25, "Time elapsed:");
                ulSetTextColor(RGB15(200,200,200));
                ostringstream elap_time;
                elap_time << "    "<< GameCtrl::getSharedObject()->getPassedTime() / 30 << "s";
                ulDrawString(15, 35, elap_time.str().c_str());

/*
                        ennemy_ai = new CSimpleAI();
                    ennemy_ai->probaTotalStop = 25;
                    ennemy_ai->probaPartialDmg = 75;
                    ennemy_ai->reactivity= 0.1;
                    ennemy_ai->extraPower = 1;
                    ennemy_ai->probaAbsorb = 30;
                    ennemy_ai->mana_gain = CFixed(3);
  */

                    //ennemy_ai->probaShrapnelAttack = 20;


                if (GameCtrl::getSharedObject()->getPassedTime()%700 == 699 ) {
                    ennemy_ai->mana_gain = ennemy_ai->mana_gain * CFixed(1.3);
                }

                if ((GameCtrl::getSharedObject()->getPassedTime()%1000 == 999 )&&(ennemy_ai->reactivity > 0)) {
                    ennemy_ai->reactivity = ennemy_ai->reactivity / 1.2;
                }

                if ((GameCtrl::getSharedObject()->getPassedTime()%1800 == 1799 )&&(ennemy_ai->extraPower < 5)) {
                    ennemy_ai->extraPower = ennemy_ai->extraPower + 1;
                }

                if ((GameCtrl::getSharedObject()->getPassedTime()%700 == 699 )) {
                        GameScene::ennemy_id = GameScene::player_id;
                        while (GameScene::ennemy_id == GameScene::player_id) {
                            GameScene::ennemy_id =PA_Rand()%5+1;
                        }
                }




                ulSetTextColor(RGB15(255,255,255));

            }
            //ulSetImageTint(planet_player->spriteTex, getColorForLife(life));
            //planet_player->draw(0);
            //ulSetImageTint(planet_ennemy->spriteTex, getColorForLife(ennemy_life));
            //planet_ennemy->draw(0);
/*
            planet_player_shield->alpha = (int)shield*29/100+1;
            planet_player_shield->draw(0);
            planet_ennemy_shield->alpha = (int)ennemy_shield*29/100+1;
            planet_ennemy_shield->draw(0);*/

}

void GameScene::preInit() {
    CSprite::flushTex();
    GameCtrl::getSharedObject()->flushSprites();
}

void GameScene::render() {

    //DEBUG
#ifdef DEBUGSAVE
    DebugLogger::write("begin render game scene");
#endif
    //END DEBUG


    int fading = 0;





    if (player_name == "") {
            player_name = "NDS player name";
    }

    int debug = 0;







    //PreLoadTex(meteor)

   // if ((PA_Rand()%2)==1) {
        PA_StopSound(15);

        PA_PlaySoundRepeat(15, beavis2_music);
    //} else {
      //  PA_PlaySoundRepeat(15, suckers_music);
    //}

        //cursor definition
    CSprite * cursor = new CSprite(); //cursor
    loadTex16col(cursor,bullet_small);
    cursor->size = 4;



    //HUD DEFINITION

    player_hud = new CSprite(128,90,0);
    loadTex16col(player_hud,player_hud_pic);
    player_hud->x=256-60;
    player_hud->y=32;

    ennemy_hud = new CSprite(128,90,0);
    loadTex16col(ennemy_hud,ennemy_hud_pic);
    ennemy_hud->x=55;
    ennemy_hud->y=32;


    player_hud_jam = new CSprite();
    player_hud_jam->mFrameNumber = 3;
    loadTex16col(player_hud_jam,player_hud_jam_pic);
    player_hud_jam->x=256-60;
    player_hud_jam->y=29;

    //player_hud_jam->layer = 4;

    ennemy_hud_jam = new CSprite();
    ennemy_hud_jam->mFrameNumber = 2;
    loadTex16col(ennemy_hud_jam,ennemy_hud_jam_pic);
    ennemy_hud_jam->x=55;
    ennemy_hud_jam->y=29;
    //ennemy_hud_jam->layer = 4;

    //END HUD DEFINITION



    GameCtrl * gc = GameCtrl::getSharedObject();
    gc->flushSprites();

    if (background_haut == NULL) {
        background_haut = new CSprite(128,96,0);
        loadTex16col(background_haut,spacehaut)
    }

    if (background_bas == NULL) {
        background_basHQ = new CSprite(128,192+32+148,0);
        loadTex(background_basHQ,spacebas_hires)

        background_bas = new CSprite(128,192+32+96,0);
        loadTex16col(background_bas,spacebas)
    } else {
        //make it invisible
        background_basHQ = new CSprite(128,192+32+148+100,0);
    }

    	//Use bright pink as a transparent color
	ulSetTransparentColor(RGB15(31, 0, 31));


    /*CSprite * bulletSprt = new CSprite(80,222+32,0);
    bulletSprt->setVel(40,1);
    loadTex16col(bulletSprt,bullet)

    gc->addSprite(bulletSprt);*/

    if (ennemy_ai==NULL) {
        ennemy_ai = new CSimpleAI();
    }

    gc->addDecoSprite(ennemy_ai);


        //INIT SPELL LIST

    int itemsNumber = 12;

    SpellItem * _spellitems[15];

    _spellitems[0] = new MultipleShot();
    _spellitems[0]-> x = 40;
    _spellitems[0]-> y = SCREEN_HEIGHT + BORDER_HEIGHT+ 40 +(32+26)*1;

    _spellitems[1] = new ChargeShot();
    _spellitems[1]-> x = 40+32+16;
    _spellitems[1]-> y = SCREEN_HEIGHT + BORDER_HEIGHT+ 40;


    _spellitems[2] = new BlastShield();
    _spellitems[2]-> x = 40+(32+16)*2;
    _spellitems[2]-> y = SCREEN_HEIGHT + BORDER_HEIGHT+ 40;

    _spellitems[3] = new SacrificeSpell();
    _spellitems[3]-> x = 40+(32+16)*4;
    _spellitems[3]-> y = SCREEN_HEIGHT + BORDER_HEIGHT+ 40;

    _spellitems[4] = new SingleShot();
    _spellitems[4]-> x = 40+(32+16)*0;
    _spellitems[4]-> y = SCREEN_HEIGHT + BORDER_HEIGHT+ 40;

    _spellitems[5] = new ChangeSideSpell();
    _spellitems[5]-> x = 40+(32+16)*2;
    _spellitems[5]-> y = SCREEN_HEIGHT + BORDER_HEIGHT+ 40 +(32+26)*1;

    _spellitems[6] = new RaiseManaRateSpell();
    _spellitems[6]-> x = 40+(32+16)*3;
    _spellitems[6]-> y = SCREEN_HEIGHT + BORDER_HEIGHT+ 40 +(32+26)*0;

    _spellitems[7] = new RaiseMaxManaSpell();
    _spellitems[7]-> x = 40+(32+16)*3;
    _spellitems[7]-> y = SCREEN_HEIGHT + BORDER_HEIGHT+ 40 +(32+26)*1;


    _spellitems[8] = new ChargeShotLvl2();
    _spellitems[8]-> x = 40+(32+16)*1;
    _spellitems[8]-> y = SCREEN_HEIGHT + BORDER_HEIGHT+ 40 +(32+26)*1;

    _spellitems[9] = new ShrapnelShot();
    _spellitems[9]-> x = 40+(32+16)*2;
    _spellitems[9]-> y = SCREEN_HEIGHT + BORDER_HEIGHT+ 40 +(32+26)*2;


    _spellitems[10] = new ChargeShotLvl3();
    _spellitems[10]-> x = 40+(32+16)*1;
    _spellitems[10]-> y = SCREEN_HEIGHT + BORDER_HEIGHT+ 40 +(32+26)*2;

    _spellitems[11] = new MultipleShotLvl2();
    _spellitems[11]-> x = 40+(32+16)*0;
    _spellitems[11]-> y = SCREEN_HEIGHT + BORDER_HEIGHT+ 40 +(32+26)*2;

    //gc->addDecoSprite(_spellitems[0]);

    //END INIT SPELL LIST


    int release = 0;
    int btnPress = 0;

    CBullet * bulletS;

    long int i = 0;

	while(_run)
	{


        if (((int)GameScene::ennemy_life< 0)) {
            GameScene::ennemy_life = CFixed(0); //fix space
            if (!fading) {
                GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
                fading = 1;

                ScoreScene * sc = new ScoreScene();
                sc->win = 1;
                sc->totalMana = total_mana_earn;
                sc->totalTime = i/30;
                nextScene = sc;
            }


        }

        if (((int)GameScene::life< 0)) {
            if (!fading) {
                GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
                fading = 1;

                ScoreScene * sc = new ScoreScene();
                sc->win = 0;
                sc->totalMana = total_mana_earn;
                sc->totalTime = i/30;
                nextScene = sc;
            }


        }

        short int inMenu = 0;

        //Read keys
       ulReadKeys(0);

       if ((ul_keys.held.R||ul_keys.held.L)&&(!paused)&&started) {

                inMenu = 1;
                for (int i = 0; i < itemsNumber; i++) {
                    _spellitems[i]->show();
                }
           } else {
                inMenu = 0;
                for (int i = 0; i < itemsNumber; i++) {
                    _spellitems[i]->hide();
                }
           }


	   //Update only one time of two, else the game will run too fast!
	   if (!ulGetMainLcd())			{


	       ulSetImageTint(player_hud->spriteTex, RGB15(255,255,255));
	       ulSetImageTint(player_hud_jam->spriteTex, RGB15(255,255,255));
	       ulSetImageTint(ennemy_hud->spriteTex, RGB15(255,255,255));
	       ulSetImageTint(ennemy_hud_jam->spriteTex, RGB15(255,255,255));


                for (int i = 0; i < itemsNumber; i++) {
                    _spellitems[i]->update();
                }


            if (!paused) {
                gc->update();
                i++;



             if (i%60 == 0) {
                 if (quake !=0) {
                    quake --;
                 }
             }

             //update mana
             if (started) {
                 if (i%480==0) {
                    GameScene::mana = GameScene::mana * CFixed(1.1);
                    GameScene::ennemy_mana = GameScene::ennemy_mana * CFixed(1.1);

                    total_mana_earn = total_mana_earn + GameScene::mana * CFixed(1.1);
                 }

                 GameScene::mana = GameScene::mana + mana_gain;
                 total_mana_earn = total_mana_earn + mana_gain;
                 if ((int)shield < 100) {
                    GameScene::shield = GameScene::shield + CFixed(0.03);
                }
             }


	         GameScene::ennemy_mana = GameScene::ennemy_mana + ennemy_ai->mana_gain;//*(CFixed(1)+CFixed((int)(i))/CFixed(64000)));
             if ((int)ennemy_shield < 100) {
                GameScene::ennemy_shield = GameScene::ennemy_shield + CFixed(0.03);
	         }

	         if ((int)GameScene::mana >  (int)max_mana) { //if you raise your max limit
                mana = max_mana;
	         }




	         if ((ul_keys.held.down||ul_keys.held.up||ul_keys.held.B||ul_keys.held.X)&&started) {
                    if ((i%1==0)&&((int)GameScene::mana>0)) {
                    bulletS = new CBullet();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
                    bulletS->setX((int)(128+PA_Rand()%90-45));
                    bulletS->setY(192+32+192);
                    bulletS->setVel(0,-1);
                    //loadTex16col(bulletS,bullet)

                    gc->addSprite(bulletS);

                    if (i>990000) {
                        i=0;
                    }

                    GameScene::mana = GameScene::mana - CFixed(1);
                }
	         }




           }





            //PA_CloseLidSound  	(  1,  invoc_final_sound )


		   if (ul_keys.held.start) {
               GC_playSound(invoc_final_sound);

               UL_MSGBOX_BUTTON buttons[2] = {
			    {UL_KEY_A, "A: Continue"},
			    {UL_KEY_B, "B: quit"},
			   };
            //Note the Render argument: this function will be called from within ulMessageBoxEx to render the background image!
		   	int res = gc->messageBox("Do you want to resume the game ?", "Pause", 2, buttons);

		   	if (res==1) {
		   	    if (!fading) {
		   	    exitcode = 27;
                GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
                fading = 1;

                ScoreScene * sc = new ScoreScene();
                sc->win = 0;
                sc->totalMana = total_mana_earn;
                sc->totalTime = i/30;
                nextScene = sc;
		   	    }

		   	} else {
                GC_playSound(invoc_final_sound);


                GameCtrl::getSharedObject()->addDecoSprite(new CFlashDecal());
		   	}

                //paused = !paused;

		   }

           //if (ul_keys.touch.doubleClick) {
           if ((ul_keys.held.touch&&(!(ul_keys.held.R||ul_keys.held.L)))&&started) {
            gc->attract(ul_keys.touch.x,ul_keys.touch.y+192+32);
                if (btnPress ==0) {
                    //event on press
                    cursor->x = CFixed(ul_keys.touch.x);
                    cursor->y = CFixed(ul_keys.touch.y+192+32);

                    cursor->size = 2;

                    gc->testClicked(cursor, (int)cursor->y-60, (int)cursor->y+60);
                    //GC_playSound(error_sound);

                    //end event on pressed
                    btnPress = 1;
                    release = 0;
                }
           } else {
               if (release == 0) {
                    //event on release
                    //end event on release
                    release = 1;
                    btnPress = 0;
               }
           }

           //handle debug
           if (ul_keys.held.select) {
               if (debug) {
                debug = 0;
               } else {
                debug = 1;
               }
           }



		}

        int quakeRnd = 0;

        if (quake!=0) {
            quakeRnd = PA_Rand()%quake-quake/2;
        }

	   //Start our drawing
		ulStartDrawing2D();

		if (!ulGetMainLcd())		{
            background_haut->draw(0);
            gc->draw(0+quakeRnd);
            if (debug) {
            ulPrintf_xy(0, 184, "GPU load: %i%%", (GFX_VERTEX_RAM_USAGE * 100) / 6144);
            }


            //displayHUD
            this->displayHUD();



            if (inMenu) {
                ulSetAlpha(UL_FX_ALPHA, 15, 2);
                ulDrawFillRect(0, 0, 256, 192, RGB15(0, 0, 0));
                ulSetAlpha(UL_FX_DEFAULT, 0, 0);
            }

		}
		else			{
            background_bas->draw(SCREEN_HEIGHT + BORDER_HEIGHT);
            background_basHQ->draw(SCREEN_HEIGHT + BORDER_HEIGHT);
            gc->draw(SCREEN_HEIGHT + BORDER_HEIGHT+quakeRnd);

            if (inMenu) {
                ulSetAlpha(UL_FX_ALPHA, 15, 2);
                ulDrawFillRect(0, 0, 256, 192, RGB15(0, 0, 0));
                ulSetAlpha(UL_FX_DEFAULT, 0, 0);

                ulDrawString(20+(32+16)*0, 10, "Instant");
                ulDrawString(20+(32+16)*1, 10, "Charged");
                ulDrawString(20+(32+16)*2, 10, "Defense");
                ulDrawString(20+(32+16)*3, 10, "Power Up");

                for (int i = 0; i < itemsNumber; i++) {
                    _spellitems[i]->draw(SCREEN_HEIGHT + BORDER_HEIGHT);


                    if (ul_keys.held.touch) {
                        if (_spellitems[i]->testCollision(ul_keys.touch.x,ul_keys.touch.y+192+32)) {
                                _spellitems[i]->isPressed();
                        }
                    }
                }
            }


            if (debug) {
                ostringstream oss;

                oss << "Avail TexMem :"<<	ulGetTexVramAvailMemory()<< "  AvailPalMem " << ulGetTexPalAvailMemory();

                ulDrawString(1, 184, oss.str().c_str());

                ostringstream oss2;


                //oss2 << "        Mic: " << (int)gc->getMicVolume() << "collidabe sprites: " << gc->getSpriteCount() << "/total sprites <<" <<(gc->getTotalSpriteCount()+2);
                //oss2 << "Cursor" << (int)cursor->x<<"/"<< (int) cursor->y << ":" << (int) cursor->getRealSize();
                oss2 << "c: " << gc->getSpriteCount() << "/t " <<(gc->getTotalSpriteCount()+2) << "e: "<< CSprite::_sprite_in_mem;


                ulDrawString(1, 174, oss2.str().c_str());

                ulPrintf_xy(0, 164, "GPU load: %i%%", (GFX_VERTEX_RAM_USAGE * 100) / 6144);
            }




		}

		//End the drawing
		ulEndDrawing();

		//Wait the VBlank (synchronize at 60 fps)

		ulSyncFrame();
        //PA_WaitForVBL();

		//totalTime = TIMER1_DATA;
	}



    delete(background_haut);
	delete(background_bas);
	delete(background_basHQ);

    delete(player_hud);
    delete(player_hud_jam);
    delete(ennemy_hud);
    delete(ennemy_hud_jam);

    PA_StopSound(15);

	delete(cursor);

    CSprite::flushTex();
    gc->flushSprites();


}
