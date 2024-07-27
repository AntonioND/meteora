/*

    Sprite class for player ship

*/

#include "CBullet.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include <cstdlib>
#include <time.h>
#include <math.h>

#include "bullet_png.h"
#include "bullet_small_png.h"

#include "bullet_red_png.h"
#include "bullet_small_red_png.h"
#include "bullet_small_green_png.h"
#include "bullet_small_yellow_png.h"
#include "bullet_small_purple_png.h"

#include "bullet_green_png.h"
#include "bullet_yellow_png.h"
#include "bullet_purple_png.h"

#include "CPixelDecal.h"

#include "crap_small_png.h"

#include "GameScene.h"

#include "CDeconcentrate.h"

#include "CScoreDecal.h"

#include "pop_raw.h"

#include "Modifier.h"
#include "ModifierAddElec.h"

#include "CSuperNovaDecal.h"
#include "CImpactDecal.h"
#include "CFlashDecal.h"


CBullet::CBullet(int owner) :CSpriteCollidable(0,0,0) {
    size =0.4;
    mType =1;
    weight = 1;
    color = RGB15(255,255,255);

    if (owner == 0) {
        owner = GameScene::player_id;
    }

    type = owner | MERGEABLE ;

    if (owner == GameScene::player_id) { //if player_id == bullet_owner => attractible
        type |= ATTRACTIBLE;
    }

    if (owner == 1) { //load tex in fucntion of player
            loadTex16col(this,bullet_small_png)
    } else if (owner == 2 ){
            loadTex16col(this,bullet_small_red_png)
    } else if (owner == 3 ){
            loadTex16col(this,bullet_small_green_png)
    } else if (owner == 4 ){
            loadTex16col(this,bullet_small_yellow_png)
    } else if (owner == 5 ){
            loadTex16col(this,bullet_small_purple_png)
    } else {
            loadTex16col(this,bullet_small_png)
    }

    electrified = 0;
}

CBullet::~CBullet() {
}

void CBullet::changeOwner(int id) {
    type = (type & (MERGEABLE|ATTRACTIBLE|STICKY_SPRT))|id|ATTRACTIBLE;
    //type = 1 | MERGEABLE|ATTRACTIBLE;
    this->setSize(size,1);
}

void CBullet::thinking()
{
        if (electrified==0) {
            if (weight > 1000) {
                //add electricity on sprite
                new ModifierAddElec(this);
                electrified = 1;
            }
        } else {

            if (weight > 5000) {

                    //Add a super nova effect;
                    CSuperNovaDecal * snova = new CSuperNovaDecal();
                    snova->y = this->y;

                    //die the sprite
                    GameCtrl::getSharedObject()->addDecoSprite(snova);

                    GameCtrl::getSharedObject()->addDecoSprite(new CFlashDecal());

                    GameCtrl::getSharedObject()->removeSprites((int)y-110, (int)y+110);

                    GameCtrl::getSharedObject()->drawOnScreen(128,this->y,"unstable mana explosion");

                    this->dead();
            }
        }


        if(((int)x < -size*this->spriteTex->sizeY-50)||((int)x>size*this->spriteTex->sizeY+255+50)) {
            //setVel(CFixed(0)-getVelX(),getVelY());
            this->dead();
        }

        if((int)y < -100) {
            //setVel(getVelX(),CFixed(0)-getVelY());
            if ((type&OWNER_MASK)==GameScene::player_id) {
                GameScene::ennemy_ai->manageBullet(this->weight,this);
                //GameScene::ennemy_life = GameScene::ennemy_life - CFixed(this->weight);
            }
            this->dead();

        }

        if ((type&OWNER_MASK)==GameScene::player_id) {
            if ((int)y>490-32) { //bullet OK
                this->dead();

                GameScene::mana = GameScene::mana + CFixed(this->weight);
                GC_playSound(pop_raw);
            }
        } else {
            if((int)y > ((int)GameScene::shield<10?416:376)) {//if ennemy bullet


////////////////////////////// DIRT FIX

                if ((int)velY > 150) {
        //DEBUG //LOG ERROR ANYWAY
#ifdef DEBUGSAVE
        ostringstream logstream5;
        logstream5 << "sprite destruc weight" << this->weight <<"\nx: " << (int)this->x << "\ny: "<< (int)this->y; ;
        logstream5 << "\nvelX: "<< (int)velX;
        logstream5 << "\nvelY: "<< (int)velY;
        logstream5 << "\ntype: "<< (int)type;
        logstream5 << "\nowner: "<< (int)(type&OWNER_MASK);
        DebugLogger::write(logstream5.str());
#endif
        //END DEBUG

                    velY = CFixed(0.5);
                    y = CFixed(0)-CFixed(70);
                    return;

                }

//*************************** END DIRT FIX

                GameScene::getInstance()->damage(CFixed(this->weight),this);

                if ((int)GameScene::shield < 10) {




                    CImpactDecal * snova = new CImpactDecal(this->weight);
                    snova->x = this->x;
                    GameCtrl::getSharedObject()->addDecoSprite(snova);
                }

                CExplosion * exp = new CExplosion(size*(this->spriteTex->sizeX));
                exp->x = this->x;
                exp->y = this->y;
                //exp->setVel(0,0);
                //exp->size = 1;
                GameCtrl::getSharedObject()->addDecoSprite(exp);
                this->dead();
            }
        }

            //GC_playSound(pop);


        //this->spriteTex->angle+=1;
        this->setVelX(getVelX()*CFixed(0.990));
        this->setVelY(getVelY()*CFixed(0.990));
}

void CBullet::draw(int offset) {
    angle = angle+1;
    this->spriteTex->stretchX =  (size*this->spriteTex->sizeX);
    this->spriteTex->stretchY =  (size*this->spriteTex->sizeY);
    this->spriteTex->angle = angle;
    ulSetImageTint(this->spriteTex, this->color);
    CSprite::draw(offset);

    //DEBUG WEIGHT
/*
    if (weight > 10) {
        ulSetTextColor(RGB15(0,0,0));
        ostringstream elifeshow;
        elifeshow << (int)weight << "/ size " << size;
        ulDrawString((int)x, (int)y-offset, elifeshow.str().c_str());
    }
*/
    //END DEBUG WEIGHT


}

void CBullet::clicked(int x, int y) {
    if ((type&OWNER_MASK) != GameScene::player_id) {

        this->setVelX(this->getVelX()/CFixed(2));
        this->setVelY(this->getVelY()/CFixed(2));
        this->weight -=1;

        if (this->weight <= 0) {
                this->dead();
        }

        CDeconcentrate * cc;
        cc = new CDeconcentrate();
        cc->setX(x);
        cc->setY(y);
        GameCtrl::getSharedObject()->addDecoSprite(cc);
        //addDecals();

        this->setSize (sqrt(this->weight)*0.1); //pow(weight,1);
    }
}

void CBullet::setSize(double pSize, int forced) {

    if ((type&MERGEABLE)||forced) {

        if (pSize < 0.25) {
            this->size = pSize*4;
            if ((type&OWNER_MASK)==1) {
                loadTex16col(this,bullet_small_png);
            } else if ((type&OWNER_MASK)==2) {
                loadTex16col(this,bullet_small_red_png);
            } else if ((type&OWNER_MASK)==3) {
                loadTex16col(this,bullet_small_green_png);
            } else if ((type&OWNER_MASK)==4) {
                loadTex16col(this,bullet_small_yellow_png);
            } else if ((type&OWNER_MASK)==5) {
                loadTex16col(this,bullet_small_purple_png);

            }
        } else   {
            this->size = pSize;
            if ((type&OWNER_MASK)==1) {
                loadTex16col(this,bullet_png);
            } else if ((type&OWNER_MASK)==2) {
                loadTex16col(this,bullet_red_png);
            } else if ((type&OWNER_MASK)==3) {
                loadTex16col(this,bullet_green_png);
            } else if ((type&OWNER_MASK)==4) {
                loadTex16col(this,bullet_yellow_png);
            } else if ((type&OWNER_MASK)==5) {
                loadTex16col(this,bullet_purple_png);
            }
        }
    }
}

void CBullet::merge(CBullet *s) {
    Modifier * curr = (Modifier *) s->_modifier;

    while (curr) {
            curr->duplicateAndAttachTo(this);
            curr = (Modifier *) curr->_modifier;
    }
}

void CBullet::hit(CSprite * parent2) {

        if (((parent2->type&OWNER_MASK) ==( type&OWNER_MASK))&&(parent2->type&MERGEABLE&type)) { //merge same bullet
            //this->weight -=0.1;
                CBullet * parent = (CBullet *) parent2;
                if (parent->weight <= weight) {
                weight += parent->weight;

                /*if (weight > 3050) {
                    weight = 3010; //fix max size to 3010
                }*/

                this->setVelX((CFixed(weight)*getVelX()+CFixed(parent->weight)*parent->getVelX())/(CFixed(weight)+CFixed(parent->weight)));
                this->setVelY((CFixed(weight)*getVelY()+CFixed(parent->weight)*parent->getVelY())/(CFixed(weight)+CFixed(parent->weight)));
                this->setSize (sqrt(this->weight)*0.1); //pow(weight,1);

/*
                   FILE* file = fopen ("merge.log", "a+");

                    ostringstream logstream2;
                    logstream2 << "   --> merge " << (int)parent <<" "<< (int)this << "\n";
                    fputs(logstream2.str().c_str(),file);
*/

                this->merge(parent);


/*
                    ostringstream logstream;
                    logstream << "   --> end merge " << (int)parent <<" "<< (int)this << "\n";
                    fputs(logstream.str().c_str(),file);

               fclose(file);
*/
                parent->dead();





            /*} else {
                parent->weight+=weight;
                parent->setVelX((CFixed(weight)*getVelX()+CFixed(parent->weight)*parent->getVelX())/(CFixed(weight)+CFixed(parent->weight)));
                parent->setVelY((CFixed(weight)*getVelY()+CFixed(parent->weight)*parent->getVelY())/(CFixed(weight)+CFixed(parent->weight)));
                parent->setSize (sqrt(parent->weight)*0.1); //pow(weight,1);//log(parent->weight)/10;
                this->dead();




*/
            }


        }
        else {
        if ((parent2->type&OWNER_MASK) != (type&OWNER_MASK)) {
            //this->weight -=0.1;
                CBullet * parent = (CBullet *) parent2;
                if (parent->weight < weight) {
                weight -= parent->weight;
                this->setVelX((CFixed(weight)*getVelX()+CFixed(parent->weight)*parent->getVelX())/(CFixed(weight)+CFixed(parent->weight)));
                this->setVelY((CFixed(weight)*getVelY()+CFixed(parent->weight)*parent->getVelY())/(CFixed(weight)+CFixed(parent->weight)));
                this->size = sqrt(this->weight)*0.1; //pow(weight,1);

                            parent->addDecals();

                if ((int)parent->weight >= 7&&((int)parent->weight <= 1199)) {
                            CExplosion * exp = new CExplosion(1);
                            exp->x = parent->x;
                            exp->y = parent->y;
                            //exp->setSize ( size);
                            exp->setVel(parent->getVelX()/CFixed(10),parent->getVelY()/CFixed(10));
                            GameCtrl::getSharedObject()->addDecoSprite(exp);
                } else if ((int)parent->weight >= 1200){

                    CSuperNovaDecal * snova = new CSuperNovaDecal(parent->weight);
                    snova->y = parent->y;


                    GameCtrl::getSharedObject()->addDecoSprite(snova);
                    GameCtrl::getSharedObject()->addDecoSprite(new CFlashDecal());


                }

                parent->dead();

                    if ((type&OWNER_MASK)==GameScene::player_id) {
                        if (parent->weight>30) {
                            CScoreDecal * sd = new CScoreDecal(parent->weight);
                            sd->x = CFixed(x) - CFixed(6);
                            sd->y = CFixed(y);

                            gc->addDecoSprite(sd);
                        }
                    }

            } /*else {
                parent->weight-=weight;
                parent->setVelX((CFixed(weight)*getVelX()+CFixed(parent->weight)*parent->getVelX())/(CFixed(weight)+CFixed(parent->weight)));
                parent->setVelY((CFixed(weight)*getVelY()+CFixed(parent->weight)*parent->getVelY())/(CFixed(weight)+CFixed(parent->weight)));
                parent->size = sqrt(parent->weight)*0.1; //pow(weight,1);//log(parent->weight)/10;

                this->addDecals();


                if ((int)this->weight > 10) {
                            CExplosion * exp = new CExplosion(1);
                            exp->x = this->x;
                            exp->y = this->y;
                            //exp->size = size;
                            exp->setVel(this->getVelX()/CFixed(10),this->getVelY()/CFixed(10));
                            GameCtrl::getSharedObject()->addDecoSprite(exp);
                }

                this->dead();
            }*/


        }
        }

        if (this->weight <= 0) {
            this->dead();
        }

}

void CBullet::addDecals() {
         int sprite_size = (int)(size*(this->spriteTex->sizeX));

     if (gc->getTotalSpriteCount() > 300) {
         sprite_size = sprite_size / 3;
     }

     if (gc->getTotalSpriteCount() > 650) {
         sprite_size = 0;
     }

     for (int i = 0; i < sprite_size; i++) {

        CPixelDecal * bulletS;

        bulletS = new CPixelDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);

        bulletS->setX(this->x);
        bulletS->setY(this->y);
        bulletS->setVel(CFixed((int)PA_Rand()%64-32)/CFixed(32),CFixed((int)PA_Rand()%64-32)/CFixed(32));

        //loadTex16col(bulletS,crap_small)
                bulletS->size=0.4;
        bulletS->nextThink = 2;

        gc->addDecoSprite(bulletS);

    }

}

void CBullet::dead() {
    CSpriteCollidable::dead();



}
