#include "GameCtrl.h"

#include "CSprite.h"
#include "CExplosion.h"

#include <cstdlib>
#include <time.h>

#include "FastMath.h"

#include "CDecal.h"

#include "power_font_min_png.h"
#include "power_font_maj_png.h"
#include "power_font_num_png.h"

  GameCtrl* GameCtrl::pinstance = 0;// initialize pointer

  int GameCtrl::curr_channel = 0;

  GameCtrl* GameCtrl::getSharedObject ()
  {
    if (pinstance == 0)  // is it the first call?
    {
      pinstance = new GameCtrl; // create sole instance
    }
    return pinstance; // address of sole instance
  }
  GameCtrl::GameCtrl()
  {


        mPassedTime = 0;

        _spriteNumber = 0;
        _spriteDecoNumber = 0;

        micMiddle = CFixed(0);

  }

  void GameCtrl::addCollisionMap(CSprite *c,  int rangeDown) {
        //_collisionList[rangeUp].push_front(c);
        _collisionList[rangeDown].push_front(c);
  }

   void GameCtrl::delCollisionMap(CSprite *c,  int rangeDown) {
        //_collisionList[rangeUp].remove(c);
        _collisionList[rangeDown].remove(c);
  }

  /**
      * add a sprite to sprite list
      */
  void GameCtrl::addSprite(CSprite * c) {
     //mSpriteList.push_back (c);
     _spriteList[_spriteNumber] = c;
     _spriteNumber++;
  }

  void GameCtrl::delSprite(CSprite * c) {
    //mSpriteList.remove(c);
    for (int i =0; i < _spriteNumber; i++) {
            if (_spriteList[i] == c) {
                    if (_spriteNumber != 0) { //if not last sprite
                        _spriteList[i] = _spriteList[_spriteNumber-1];
                    }
            }
    }
    _spriteNumber--;
  }

  void GameCtrl::drawOnScreen(int x, int y, string s) {
        CDecal * dec;

        for (int i = 0; i< s.length(); i++) {
                if (s[i]!=32) {

                  if ((s[i] >= 58) &&(s[i] < 91)) {
                    dec=new CDecal();

                    dec->mFrameNumber = 33;
                    loadTex16col(dec,power_font_maj_png);
                    //dec->frame = s[i]-48;
                    dec->frame = s[i]-59;

                    dec->y = CFixed(y);
                    dec->lifetime = i*20;
                    dec->nextThink = 1;
                    dec->x = CFixed(x+i*10)-CFixed((int)s.length()/2*10);

                    dec->velY = CFixed(0) - CFixed(0.3);
                    //dec->size = 2;

                    addDecoSprite(dec);
                  }


                  else if (s[i]>=91) {
                    dec=new CDecal();

                    dec->mFrameNumber = 31;
                    loadTex16col(dec,power_font_min_png);
                    //dec->frame = s[i]-48;
                    dec->frame = s[i]-92;
                    dec->lifetime = i*1;

                    dec->y = CFixed(y);
                    dec->velY = CFixed(0) - CFixed(0.2);
                    dec->x = CFixed(x+i*10)-CFixed((int)s.length()/2*10);
                    //dec->size = 2;

                    addDecoSprite(dec);
                 }
               }
        }
  }

    void GameCtrl::drawPersistentOnScreen(int x, int y, string s) {
        CSprite * dec;

        for (int i = 0; i< s.length(); i++) {
                if (s[i]!=32) {

                  if ((s[i] >= 58) &&(s[i] < 91)) {
                    dec=new CSprite();
                    dec->mFrameNumber = 33;
                    loadTex16col(dec,power_font_maj_png);

                    //dec->frame = s[i]-48;
                    dec->frame = s[i]-58;

                    dec->y = CFixed(y);
                    dec->x = CFixed(x+i*10)-CFixed((int)s.length()/2*10);

                    //dec->velY = CFixed(0) - CFixed(0.3);
                    //dec->size = 2;

                    addDecoSprite(dec);
                  }


                  else if (s[i]>=91) {
                    dec=new CSprite();
                    dec->mFrameNumber = 31;

                    loadTex16col(dec,power_font_min_png);
                    //dec->frame = s[i]-48;
                    dec->frame = s[i]-92;
                    dec->y = CFixed(y);
                    //dec->velY = CFixed(0) - CFixed(0.2);
                    dec->x = CFixed(x+i*10)-CFixed((int)s.length()/2*10);
                    //dec->size = 2;

                    addDecoSprite(dec);
                 }

                 else if (s[i]>=33 && (s[i]<43)) {
                    dec=new CSprite();
                    dec->mFrameNumber = 10;

                    loadTex16col(dec,power_font_num_png);
                    //dec->frame = s[i]-48;
                    dec->frame = s[i]-33;
                    dec->y = CFixed(y);
                    //dec->velY = CFixed(0) - CFixed(0.2);
                    dec->x = CFixed(x+i*10)-CFixed((int)s.length()/2*10);
                    //dec->size = 2;

                    addDecoSprite(dec);
                 }
               }
        }
  }


void GameCtrl::addDecoSprite(CSprite * c) {
     //mSpriteList.push_back (c);
     _spriteDecoList[_spriteDecoNumber] = c;
     _spriteDecoNumber++;
}

  void GameCtrl::delDecoSprite(CSprite * c) {
    //mSpriteList.remove(c);
    for (int i =0; i < _spriteDecoNumber; i++) {
            if (_spriteDecoList[i] == c) {
                    if (_spriteDecoNumber != 0) { //if not last sprite
                        _spriteDecoList[i] = _spriteDecoList[_spriteDecoNumber-1];

                        //memmove (_spriteDecoList+i,_spriteDecoList+i+1,_spriteDecoNumber);

                    }
            }
    }
    _spriteDecoNumber--;
  }

  /**
      * update all sprite list
      */

  void GameCtrl::draw(int offset) {
   //vector<CSprite *>::iterator sprite_iter;
    /*for (sprite_iter=mSpriteList.begin(); sprite_iter != mSpriteList.end(); sprite_iter++) {*/
    for (int i =0; i < _spriteNumber; i++) {
        CSprite * tmpSprite = _spriteList[i];
        tmpSprite->draw(offset);
    }

    for (int i =0; i < _spriteDecoNumber; i++) {
        CSprite * tmpSprite = _spriteDecoList[i];
        tmpSprite->draw(offset);
    }
    //}

  }

  void GameCtrl::attract(int x,int y) {
    //vector<CSprite *>::iterator sprite_iter;
    //for (sprite_iter=mSpriteList.begin(); sprite_iter != mSpriteList.end(); sprite_iter++) {
    for (int i =0; i < _spriteNumber; i++) {
        CSprite * tmpSprite = _spriteList[i];
        //CSprite * tmpSprite = *sprite_iter;

        if (tmpSprite->type&ATTRACTIBLE ){

                /*if (tmpSprite->x > x) {
                    tmpSprite->setVelX(tmpSprite->getVelX()-0.2);
                }

                if (tmpSprite->y > y) {
                    tmpSprite->setVelY(tmpSprite->getVelY()-0.2);
                } */
                int dist =  PA_Distance(x, y, (int)tmpSprite->getx(), (int)tmpSprite->gety())*0.8;
                if (dist < 10) {
                        dist = 20000;
                }
                tmpSprite->setVelX(CFixed(tmpSprite->getVelX())-(CFixed(tmpSprite->x) - CFixed(x))/(CFixed(dist)*CFixed(0.5)));
                tmpSprite->setVelY(CFixed(tmpSprite->getVelY())-(CFixed(tmpSprite->y) - CFixed(y))/(CFixed(dist)*CFixed(0.5)));

        }
    }
  }



void GameCtrl::flushSprites() {

    for (int i =0; i < _spriteNumber; i++) {
        CSprite * tmpSprite = _spriteList[i];
        delete (tmpSprite);
    }
    _spriteNumber = 0;

    for (int i =0; i < _spriteDecoNumber; i++) {
        CSprite * tmpSprite = _spriteDecoList[i];
        delete(tmpSprite);
    }
    _spriteDecoNumber = 0;
}

  void GameCtrl::testCollision() {

    list<CSprite *> sprtList;

    list<CSprite *>::const_iterator sprite_iter_sprtList;

       //for (int j= prangeDown; j <= prangeUp; j++) {
       for (int j= 0; j <= 599; j++) {
           if (_collisionList[j].size()!=0) {

                list<CSprite *>::const_iterator sprite_iter;
                for (sprite_iter=_collisionList[j].begin(); sprite_iter != _collisionList[j].end(); sprite_iter++) {


                    list<CSprite *> removeList;




                    CSprite* tmpSprite = *sprite_iter;

                    if (tmpSprite->getStatus()==S_DIED) {
                        //return;
                    } else {


                        for (sprite_iter_sprtList = sprtList.begin(); sprite_iter_sprtList != sprtList.end(); sprite_iter_sprtList++) {

                            CSprite* c = *sprite_iter_sprtList;
                            if (c != tmpSprite) {

                                 if (c->collide(tmpSprite)) {

                                            tmpSprite->hit(c);
                                            c->hit(tmpSprite);


                                 }

                            }


                                if (c->rangeUp < j) {
                                //sprite_iter++;
                                //sprtList.remove(c);
                                    //sprtList.erase(sprite_iter_sprtList,sprite_iter_sprtList++);
                                    removeList.push_front(c);
                                }


                        }

                        for (sprite_iter_sprtList = removeList.begin(); sprite_iter_sprtList != removeList.end(); sprite_iter_sprtList++) {
                            CSprite* c = *sprite_iter_sprtList;
                            sprtList.remove(c);
                        }

                        sprtList.push_back(tmpSprite);


                   }
                }
           }
       }

       sprtList.clear();

}

void GameCtrl::testClicked(CSprite * cursor, int rangeDown, int rangeUp) {
    if (rangeDown < 0) {
        rangeDown = 0;
    }

    if (rangeUp > 599) {
        rangeUp = 599;
    }


       //for (int j= prangeDown; j <= prangeUp; j++) {
       for (int j= rangeDown; j <= rangeUp; j++) {
           if (_collisionList[j].size()!=0) {

                list<CSprite *>::const_iterator sprite_iter;
                for (sprite_iter=_collisionList[j].begin(); sprite_iter != _collisionList[j].end(); sprite_iter++) {

                    CSprite* tmpSprite = *sprite_iter;

                    if (tmpSprite->getStatus()==S_DIED) {
                        //return;
                    } else {


                                 //if (cursor->collide(tmpSprite)) {
                                 if (tmpSprite->collide(cursor)) {
                                            //tmpSprite->clicked((int)cursor->x,(int)cursor->y);
                                            tmpSprite->clicked((int)tmpSprite->x,(int)tmpSprite->y);
                                 }


                   }
                }
           }
       }


}

/**
 * remove all collidable sprites in a range
 */
void GameCtrl::removeSprites(int rangeDown, int rangeUp) {

if (rangeDown < 0) {
        rangeDown = 0;
    }

if (rangeUp > 599) {
        rangeUp = 599;
}

       //for (int j= prangeDown; j <= prangeUp; j++) {
       for (int j= rangeDown; j <= rangeUp; j++) {
           if (_collisionList[j].size()!=0) {

                list<CSprite *>::const_iterator sprite_iter;
                for (sprite_iter=_collisionList[j].begin(); sprite_iter != _collisionList[j].end(); sprite_iter++) {

                    CSprite* tmpSprite = *sprite_iter;

                    if ((int)tmpSprite->y+tmpSprite->size*(tmpSprite->spriteTex->sizeY/2) < rangeUp) {
                            tmpSprite->dead();
                    }
                }
           }
       }


}




  void GameCtrl::update() {
    mPassedTime += 1;

    if (mPassedTime %2 ==1) {
        testCollision();
    }

    for (int i =0; i < _spriteDecoNumber; i++) {
        CSprite * tmpSprite = _spriteDecoList[i];
        tmpSprite->update();

            if (tmpSprite->getStatus()==S_DIED) {
            //sprite_iter++;
            delDecoSprite(tmpSprite);
            delete(tmpSprite);
          }
    }


     for (int i =0; i < _spriteNumber; i++)
      {

       CSprite * tmpSprite = _spriteList[i];
        tmpSprite->update();


        if (tmpSprite->getStatus()==S_DIED) {
            delSprite(tmpSprite);
            delete(tmpSprite);
        }



      }


  }

  void GameCtrl::playSound (const void *data, s32 length, u8 volume, int freq, s16 format) {
        curr_channel +=1;
        if (curr_channel > 14) {
            curr_channel = 0;
        }
        PA_StopSound(curr_channel);
        PA_PlaySoundEx (curr_channel, data, length, volume, freq, format);
  }


void GC_drawButton(int x0, int y0, int x1, int y1, const char *text, int highlight)		{
   u32 xSpace = (x1 - x0) - ulGetStringWidth(text);
   u32 ySpace = ((y1 - y0) - ul_curFont->charHeight) >> 1;

	ulDrawRect(x0, y0, x1, y1, 0);
	if (highlight)
		ulDrawGradientRect(x0 + 1, y0 + 1, x1 - 1, y1 - 1, RGB15(18, 9, 9), RGB15(15, 7, 7), RGB15(15, 7, 7), RGB15(12, 6, 6));
	else
		ulDrawGradientRect(x0 + 1, y0 + 1, x1 - 1, y1 - 1, RGB15(18, 18, 18), RGB15(15, 15, 15), RGB15(15, 15, 15), RGB15(12, 12, 12));
	ulDrawString(x0 + xSpace / 2, y0 + ySpace, text);
}



int GameCtrl::messageBox(const char *text, const char *title, int nbButtons, UL_MSGBOX_BUTTON *buttons)
{

   u32 reserved = 0;
   s32 x0, y0, x1, y1, width, height, textWidth, textHeight, titleHeight = ul_curFont->charHeight + 4;
   const UL_COLOR backColor0 = RGB15(103 >> 3, 107 >> 3, 115 >> 3), backColor1 = RGB15(73 >> 3, 77 >> 3, 85 >> 3), backColor2 = RGB15(43 >> 3, 47 >> 3, 55 >> 3);
   const UL_COLOR title1 = RGB15(0 >> 3, 0 >> 3, 128 >> 3), title2 = RGB15(16 >> 3, 132 >> 3, 208 >> 3);
   u32 i;
	s32 buttonMaxWidth = 0, totalButtonsWidth;
	const u32 buttonSpace = 4, buttonHeight = ulMax(ul_curFont->charHeight + 4, 14);

	textWidth = ulGetStringWidth(title);
   width = ulMax(140, textWidth + 4);

	for (i=0;i<nbButtons;i++)		{
	   buttonMaxWidth = ulMax(buttonMaxWidth, ulGetStringWidth(buttons[i].text) + 5);
	}
	totalButtonsWidth = (buttonSpace + buttonMaxWidth) * nbButtons;
	width = ulMax(totalButtonsWidth + 4, width);

   textHeight = ulGetTextBoxHeight(width - 4, 150, text, 0);
	height = titleHeight + 4 + textHeight + 4 + buttonHeight + 4;

	x0 = (SCREEN_WIDTH - width) >> 1;
	x1 = (SCREEN_WIDTH + width) >> 1;
	y0 = (SCREEN_HEIGHT - height) >> 1;
	y1 = (SCREEN_HEIGHT + height) >> 1;

	#ifdef UL_MSGBOX_TOUCHPAD_SUPPORT
		int titleMoving = 0, buttonSelected = -1, buttonActive = -1;
	#endif
	int returnButton = -1;



	while (returnButton == -1)			{
		ulReadKeys(0);

        //Les boutons à présent
		s32 buttonX = (x0 + x1 - totalButtonsWidth) >> 1, buttonY = y0 + titleHeight + 4 + textHeight + 4;
		s32 x = buttonX + (buttonSpace >> 1);

	   ulStartDrawing2D();

       if (!ulGetMainLcd())		{
            //draw(0);
        } else {
            //draw(SCREEN_HEIGHT + BORDER_HEIGHT);


		//Le tour
		ulDrawRect(x0, y0, x1, y1, RGB15(0, 0, 0));
		//Le dégradé du titre
		ulDrawGradientRect(x0 + 1, y0 + 1, x1 - 1, y0 + titleHeight, title1, title2, title1, title2);
		//Le dégradé du centre (texte)
		ulDrawGradientRect(x0 + 1, y0 + titleHeight, x1 - 1, y1 - 1, backColor0, backColor1, backColor1, backColor2);
		//La ligne séparatrice du titre
		ulDrawLine(x0, y0 + titleHeight, x1, y0 + titleHeight, RGB15(0, 0, 0));

		//Dessine le titre
		ulSetTextColor(RGB15(31, 31, 31));
		ulDrawTextBox((x0 + x1 - textWidth) >> 1, y0 + 3, x1 - 2, y0 + titleHeight, title, 0);
		//Le texte principal
		ulDrawTextBox(x0 + 2, y0 + titleHeight + 4, x1 - 2, y0 + titleHeight + 4 + textHeight, text, 0);


		for (i=0;i<nbButtons;i++)		{
		   //Highlight du bouton s'il est sélectionné et que le curseur est encore dessus
		   int highlight = (buttonSelected == buttonActive && buttonSelected == i);
			//Test si la touche associée au bouton est pressée
			if (ul_keys.pressed.value & buttons[i].key)		{
			   returnButton = i;
			   highlight = 1;
			}
		   GC_drawButton(x, buttonY, x + buttonMaxWidth, buttonY + buttonHeight, buttons[i].text, highlight);
		   x += buttonMaxWidth + buttonSpace;
		}
        }

		ulEndDrawing();
		ulSyncFrame();

		#ifdef UL_MSGBOX_TOUCHPAD_SUPPORT
		//Le code de gestion du touchpad ne fonctionne que si le touchpad est effectivement actif...
		if (ulGetMainLcd() == 0)			{
			//Essaie de trouver sur quel bouton le stylet est actuellement
			buttonActive = -1;
			x = buttonX + (buttonSpace >> 1);
			for (i=0;i<nbButtons;i++)		{
			   //On touche ce bouton?
			   if (ul_keys.touch.x >= x && ul_keys.touch.y >= buttonY
			   	&& ul_keys.touch.x <= x + buttonMaxWidth && ul_keys.touch.y <= buttonY + buttonHeight)			{
					buttonActive = i;
		   	}
			   x += buttonMaxWidth + buttonSpace;
			}

			//Déplacement de la fenêtre
			if (titleMoving)		{
			   x0 += ul_keys.touch.deltaX;
			   y0 += ul_keys.touch.deltaY;
			   x1 += ul_keys.touch.deltaX;
			   y1 += ul_keys.touch.deltaY;
			}

			if (ul_keys.touch.click)			{
			   //Aucun bouton? Alors on déplacera toute la boîte
			   if (buttonActive == -1)		{
			      if (ul_keys.touch.x >= x0 && ul_keys.touch.y >= y0
			      	&& ul_keys.touch.x <= x1 && ul_keys.touch.y <= y1)
						titleMoving = 1;
				}
				else
					buttonSelected = buttonActive;
			}
			//Stylet relâché
			if (ul_keys.touch.released)		{
			   //Ne bouge plus le titre
				titleMoving = 0;
				//On a choisi un bouton :)
				if (buttonSelected >= 0 && buttonActive == buttonSelected)
					returnButton = buttonSelected;
				//Plus de bouton sélectionné
				buttonSelected = -1;
			}
		}
		#endif
	}
	return returnButton;
}
