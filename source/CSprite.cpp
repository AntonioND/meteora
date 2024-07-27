//Our main file
#include "main.h"
//Class definition
#include "CSprite.h"
//Our ball PNG data
//#include "ball.h"

#include <math.h>
#include "GameCtrl.h"

#include "crap_small.h"

#include "fat.h"

#include <sstream>

#include "DebugLogger.h"


using namespace std;


map<string, int> CSprite::_resourcesNbMap;
map<string, UL_IMAGE *> CSprite::_resourcesMap;


void drawFillRect (s16 x0, s16 y0, s16 x1, s16 y1, UL_COLOR color) {
/*
    if (y0 < 1) {
           y0 =1;
    } else if (y0> 192){
        y0= 192;
    }

    if (y1 < 1) {
           y1 =1;
    } else if (y1> 192){
        y1= 192;
    }
*/


    ulDrawFillRect (x0, y0, x1, y1, color);
}



void ulSetAlphaDecal(UL_SPECIAL_EFFECT effect, int coeff, int polygroup)		{
	//Active l'alpha blending
	if (effect != UL_FX_ALPHA)
		coeff = 31;
	glPolyFmt(POLY_DECAL_SHADING | POLY_ALPHA(coeff) | POLY_CULL_NONE | POLY_ID(polygroup));
}



u32 CSprite::_uniq_id = 0;
u32 CSprite::_sprite_in_mem = 0;

//Constructor
CSprite::CSprite(int x, int y, int angle, int frameNumber)		{
   type = 0;
   initVar();
   this->x = x;
   this->y = y;
   this->angle = angle;
   //this->color = 0x7fff;
   this->mFrameNumber = frameNumber;

   _modifier = NULL;

   _sprite_in_mem++;


      //DEBUG SPRITE
/*
   _uniq_id++;
   _sprite_id = _uniq_id;

   FILE* file = fopen ("memory.log", "a+");

        ostringstream logstream;
        logstream << "+++ "<< _sprite_id  << "\n";
        fputs(logstream.str().c_str(),file);

   fclose(file);
*/
   //END DEBUG SPRITE


   loadTex16col(this,crap_small)


}

CSprite::~CSprite()		{
    if (_modifier != NULL) {
            delete(_modifier);
    }

    _sprite_in_mem--;

   //DEBUG SPRITE
 //  FILE* file = fopen ("sprites.txt", "a+");
/*
        ostringstream logstream;
        logstream << "--- "<< _sprite_id  << "\n";
        fputs(logstream.str().c_str(),file);
*/
/*
    ostringstream logstream;
    logstream << "--- "<< _sprite_in_mem  << "\n";
    fputs(logstream.str().c_str(),file);
    fclose(file);*/
    //END DEBUG SPRITE
}

void CSprite::handle()			{
}

//Draw our ball
void CSprite::draw(int offset)			{

    /*if (offset>(this->x +this->spriteTex->sizeX/2)) {
            return;
    }

    if (offset+192+32<(this->x - this->spriteTex->sizeX/2)) {
            return;
    }*/


   //if (UNFIX((int)this->y + (int)this->height) >= offset && UNFIX((int)y) <= offset + SCREEN_HEIGHT)			{
        //ulDrawImageXY(this->spriteTex, UNFIX((int)this->x), UNFIX((int)this->y) - offset);
   if (mFrameNumber != 1) {
   		ulSetImageTileSizeNoStretch(this->spriteTex,
			0,														//Image frames are aligned vertically, so we always begin to the left
			(this->spriteTex->sizeY * frame) / mFrameNumber ,	//Top position: animPositions defines the frame numbers in the image for each animation step (0, 1, 2, 1). Each frame is FRAME_HEIGHT tall, so we just have to multiply to get the actual position of the frame on the image!
			this->spriteTex->sizeX,									//Every frame takes the entire image width
			this->spriteTex->sizeY/(mFrameNumber));

			this->spriteTex->stretchY = (this->spriteTex->sizeY/(mFrameNumber))*this->spriteTex->stretchX/this->spriteTex->sizeX;
   }
        ulDrawImageXY(this->spriteTex, (int)this->x, (int)this->y - offset);
	//}
}


void CSprite::initTex(string texName, const u8 * texRef, const u32 * texSize, int pixelformat = UL_PF_PAL8) {




    map<string,int>::const_iterator iter = _resourcesNbMap.find(texName);

    if( iter != _resourcesNbMap.end() ) {
        if (_resourcesNbMap[texName] < 250) { //prevent overflow
            _resourcesNbMap[texName]++;
        }
        this->spriteTex = _resourcesMap[texName];
    } else {

        //DEBUG
#ifdef DEBUGSAVE
        ostringstream logstream5;
        logstream5 << "-> try loading tex " << texName;
        DebugLogger::write(logstream5.str());
#endif
        //END DEBUG

        this->spriteTex = ulLoadImageFilePNG((const char*)texRef, (int)texSize, UL_IN_VRAM, pixelformat);

        //DEBUG TEXTURES
#ifdef DEBUGSAVE
        ostringstream logstream2;
        logstream2 << "--> tex " << texName << "| new Free memory : " << ulGetTexVramAvailMemory() << " Used : "<< ulGetTexVramUsedMemory()<< "|Free palette " <<  ulGetTexPalAvailMemory();

        if (this->spriteTex == NULL) {
            logstream2 << "\n+--> ERROR DURING LOADING :/    this->spriteTex == NULL";
        }

        DebugLogger::write(logstream2.str());
#endif
        //END DEBUG TEXTURE

        //if load ok
        if (this->spriteTex != NULL) {
            this->spriteTex->centerX = this->spriteTex->sizeX / 2;
            this->spriteTex->centerY = this->spriteTex->sizeY /mFrameNumber/ 2;

            _resourcesMap[texName] = this->spriteTex;
            _resourcesNbMap[texName]=1;

        } else { //if error during loading
            if (pixelformat != UL_PF_PAL4) {
                    initTex(texName, texRef, texSize, UL_PF_PAL4);
            }
        }
    }

   //debug tex loader
   /*
   FILE* file = fopen ("memory.log", "a+");

        ostringstream logstream2;
        logstream2 << "   --> tex " << texName <<" "<< _sprite_id << "\n";
        fputs(logstream2.str().c_str(),file);

   fclose(file);
   */
   //end tex loader
}

void CSprite::flushTex() {

      //ulDeleteImage

      //UL_IMAGE * tex;

      map<string, UL_IMAGE *>::const_iterator ulIMG_iter;
                for (ulIMG_iter=_resourcesMap.begin(); ulIMG_iter != _resourcesMap.end(); ulIMG_iter++) {

                    ulDeleteImage((* ulIMG_iter).second);

                            //DEBUG TEXTURES
#ifdef DEBUGSAVE
                            ostringstream logstream2;
                            logstream2 << "   <-- unload tex " << (* ulIMG_iter).first << "| new Free memory : " << ulGetTexVramAvailMemory() << "Used : "<< ulGetTexVramUsedMemory()<< "|Free palette " <<  ulGetTexPalAvailMemory();
                            DebugLogger::write(logstream2.str());
#endif
                            //END DEBUG TEXTURE


                    //ulDeleteImage(_resourcesMap[texname]);
                }

     _resourcesMap.clear();
     _resourcesNbMap.clear();

//     ulInitGfx();

//DEBUG TEXTURES
#ifdef DEBUGSAVE
        ostringstream logstream3;
        logstream3 << " <-- unload tex finished | new Free memory : " << ulGetTexVramAvailMemory() << " Used : "<< ulGetTexVramUsedMemory()<< "| Free palette " <<  ulGetTexPalAvailMemory();
        DebugLogger::write(logstream3.str());
#endif
//END DEBUG TEXTURE

     //ulSetTexVramParameters(UL_BANK_A_B, VRAM_A, 256 << 10); //flush bank

     //ulSetTexPalVramParameters(UL_BANK_F, VRAM_F, 16 << 10);

//DEBUG TEXTURES
#ifdef DEBUGSAVE
        ostringstream logstream4;
        logstream4 << " <-- end memory init | new Free memory : " << ulGetTexVramAvailMemory() << " Used : "<< ulGetTexVramUsedMemory()<< "| Free palette " <<  ulGetTexPalAvailMemory();
        DebugLogger::write(logstream4.str());
        DebugLogger::write("\n******************\n\n");
#endif
//END DEBUG TEXTURE



}

void CSprite::preLoadTex(string texName, const u8 * texRef, const u32 * texSize, int pixelformat = UL_PF_PAL8) {

    map<string,int>::const_iterator iter = _resourcesNbMap.find(texName);

    if( iter != _resourcesNbMap.end() ) {
        return;
    } else {
        _resourcesMap[texName] =ulLoadImageFilePNG((const char*)texRef, (int)texSize, UL_IN_VRAM, pixelformat);
        _resourcesNbMap[texName]++;
    }
}



void CSprite::dead(CSprite * parent)
{
    mStatus=S_DIED;
    mType = 0;
}

void CSprite::dead()
{
    mStatus=S_DIED;
    mType = 0;
}

void CSprite::hit(CSprite * parent)
{

}


short int CSprite::collide(CSprite * object1)
{

    if (this->getStatus()==S_DIED||object1->getStatus()==S_DIED) {
        return 0;
    }

  //int rad = mRadius + object1->getRadius();
  int rad = (size*this->getRadius()/2 + object1->size*object1->getRadius()/2)*0.95;

  //int rad = 1;

  if (abs((int)object1->gety() - (int)gety()) > rad) {
        return 0;
  }

  if (abs((int)object1->getx() - (int)getx()) > rad) {
        return 0;
  }


  if (PA_Distance((int)x, (int)y, (int)object1->getx(), (int)object1->gety()) < (rad * rad)) {
	   return 1;
  } else {
       return 0;
  }
}


//met a jour les variables et l'affichage du sprite
void CSprite::update()
{
      /*if((unsigned int)mLastThinkupdate+nextThink<SDL_GetTicks())
      {
        thinking();
        mLastThinkupdate = SDL_GetTicks();
      }*/

  updatePos();
  if(mLastThinkupdate+nextThink<GameCtrl::getSharedObject()->getPassedTime())
      {
        thinking();
        mLastThinkupdate = GameCtrl::getSharedObject()->getPassedTime();
      }

  if(_modifier) {
        _modifier->update();
  }
  //draw();
}

void CSprite::thinking() {
}

void CSprite::updatePos()
{
   xadd(velX);
   yadd(velY);
}

void CSprite::initVar()
{
    //init var
  size =1;
  mFrame=0;
  x=0;
  y=0;
  mOldX=0;
  mOldY=0;
  velX=0;
  velY=0;
  /*mAnimating=0;
  mDrawn=0;
  nextThink=10;
  mSpeed=1;*/
  nextThink=10;
  mLastupdate=0;
  mLastThinkupdate=0;
  mStatus=S_ACTIVE;
  life=100;
  mRadius= 16;
  mType = 0;
  frame =0;


  this->rangeUp = 12;
  this->rangeDown = 7;


  gc = GameCtrl::getSharedObject();

}


