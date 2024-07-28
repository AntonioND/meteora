/*

    Sprite class for player ship

*/

#include "IntroScene.h"

#include <cstdlib>
#include <time.h>
#include "explosion_png.h"
#include "small_explosion_png.h"
#include "CDecal.h"
#include "CPixelDecal.h"

#include "MenuScene.h"

#include "title_png.h"

#include "crap_small_png.h"

#include "spacebas_title_png.h"

#include "explode_raw.h"
#include "CPulseDecal.h"

#include "touch_the_screen_png.h"

#include "img_evolution_tag_png.h"

#include "menu_ambiant_raw.h"

#include "GameScene.h"

#include "DSIO.h"
#include "DSIO_tag_png.h"

IntroScene::IntroScene(): CScene()  {
    //CScene::CScene();
    nextScene = new MenuScene();
    //nextScene = new GameScene();
}

IntroScene::~IntroScene() {

}

void IntroScene::render() {

    GameCtrl * gc = GameCtrl::getSharedObject();
    CSprite::flushTex();
    gc->flushSprites();


    //CSprite * background_haut = new CSprite(128,96,0);
     //loadTex16col(background_haut,spacehaut)
    gc->curr_channel_loop_1 = GC_playSoundLoop(menu_ambiant_raw);

    CSprite * background_haut = new CSprite(128,96,0);
    //loadTex(background_haut,title)
    loadTex(background_haut,title_png);
    //loadTex16col(background_haut,title_png);

    /*CSprite * bg_haut = new CSprite(128,96,0);
    //loadTex(background_haut,title)
    loadTex16col(bg_haut,spacehaut);*/

    CSprite * background_bas = new CSprite(128,192+32+96,0);
    loadTex(background_bas,spacebas_title_png)

/*
    CDecal * black_screen_sprite = new CDecal();
    black_screen_sprite->setX(128);
    black_screen_sprite->setY(96);
    black_screen_sprite->alpha = 1;
    black_screen_sprite->layer = 2;
    loadTex16col(black_screen_sprite,black_screen_png);

*/

    CPulseDecal * evo = new CPulseDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
    evo->setX(191);
    evo->setY(89);
    evo->setVel(0,0);
    loadTex16col(evo,img_evolution_tag_png)

    gc->addDecoSprite(evo);

    if (DSIO::ent()->hasDSIO) {
        CPulseDecal * dsioim = new CPulseDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
        dsioim->setX(128);
        dsioim->setY(125);
        dsioim->setVel(0,0);
        loadTex16col(dsioim,DSIO_tag_png)

        gc->addDecoSprite(dsioim);


    }


    CPulseDecal * touch = new CPulseDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
    touch->setX(128);
    touch->setY(192+32+96);
    touch->setVel(0,0);
    loadTex16col(touch,touch_the_screen_png)

    gc->addDecoSprite(touch);






    //int release = 0;
    //int btnPress = 0;

    CDecal * bulletS;

    int i = 0;

	while(_run)
	{



	   //Update only one time of two, else the game will run too fast!
	   if (!ulGetMainLcd())			{


             gc->update();
	         i++;
	         //if (ul_keys.held.R||ul_keys.held.L) {


             if (i%1==0) {
                    bulletS = new CDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
                    bulletS->setX((int)(128+rand()%200-100));
                    bulletS->setY(192+32+192);
                    bulletS->setVel(0,-2);
                    bulletS->size=((double)(rand()%8))/8;
                    loadTex16col(bulletS,crap_small_png)

                    gc->addDecoSprite(bulletS);

                    bulletS = new CDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
                    bulletS->setX((int)(128+rand()%200-100));
                    bulletS->setY(192+32+192);
                    bulletS->setVel(0,-1);
                    bulletS->size=((double)(rand()%8))/16;
                    loadTex16col(bulletS,crap_small_png)

                    gc->addDecoSprite(bulletS);

                    CPixelDecal * bulletS2;
                    bulletS2 = new CPixelDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
                    bulletS2->setX((int)(128+rand()%200-100));
                    bulletS2->setY(192+32+192);
                    bulletS2->setVel(0,-1);
                    bulletS2->size=((double)(rand()%8))/16;
                    //loadTex16col(bulletS,crap_small_png)

                    gc->addDecoSprite(bulletS2);

                    bulletS2 = new CPixelDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
                    bulletS2->setX((int)(128+rand()%200-100));
                    bulletS2->setY(192+32+192);
                    bulletS2->setVel(0,-1);
                    bulletS2->size=((double)(rand()%8))/16;
                    //loadTex16col(bulletS,crap_small_png)

                    gc->addDecoSprite(bulletS2);

                    if (i>28000) {
                        i=0;
                    }
                }
	         //}

             if (ul_keys.held.B||ul_keys.held.A) {
                CScene::stopScene();
             }


		   //Read keys
		   ulReadKeys(0);
           //if (ul_keys.touch.doubleClick) {
           if (ul_keys.held.touch) {
             CScene::stopScene();

           } else {
                //btnPress = 0;
           }

		}

	   //Start our drawing
		ulStartDrawing2D();

		if (!ulGetMainLcd())		{
		    //bg_haut->draw(0);
            background_haut->draw(0);
            gc->draw(0);

		}
		else			{
            background_bas->draw(SCREEN_HEIGHT + BORDER_HEIGHT);
            gc->draw(SCREEN_HEIGHT + BORDER_HEIGHT);
		}

		//End the drawing
		ulEndDrawing();

		//Wait the VBlank (synchronize at 60 fps)

		ulSyncFrame();
        //swiWaitForVBlank();

		//totalTime = TIMER1_DATA;
	}


    int offset = 0;
	while(offset <=200) {
	    gc->update();

	    ulStartDrawing2D();

	    if (!ulGetMainLcd())		{
		    //bg_haut->draw(0);
            background_haut->draw(0);
            gc->draw(0);
            //black_screen_sprite->draw(0);
            ulSetAlpha(UL_FX_ALPHA, 31, 2);
            ulDrawFillRect(0, 0, 256, offset, RGB15(0, 0, 0));
            ulSetAlpha(UL_FX_DEFAULT, 0, 0);

		}
		else			{
            background_bas->draw(SCREEN_HEIGHT + BORDER_HEIGHT);
            gc->draw(SCREEN_HEIGHT + BORDER_HEIGHT);
            //black_screen_sprite->draw(0);
            ulSetAlpha(UL_FX_ALPHA, 31, 2);
            ulDrawFillRect(0, 192-offset, 256, 192, RGB15(0, 0, 0));
            ulSetAlpha(UL_FX_DEFAULT, 0, 0);
		}
		//black_screen_sprite->alpha++;

        ulEndDrawing();
		ulSyncFrame();
        offset+=4;
	}



	delete(background_haut);
	delete(background_bas);
	//delete(black_screen_sprite);

	soundKill(gc->curr_channel_loop_1);
	//delete(bg_haut);

}
