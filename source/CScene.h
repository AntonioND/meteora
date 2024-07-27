#ifndef __CScene_H__
#define __CScene_H__

#include "CSprite.h"

#include "debuglogger.h"


//void ulSetAlphaDecal(UL_SPECIAL_EFFECT effect, int coeff, int polygroup);


string timeToString(int time);

class CScene
{

protected:


public :



    static unsigned short int _run;

    CScene * nextScene;

    CScene();

    virtual ~CScene();

    virtual void render();

    static void stopScene() {_run=0;}

    static void resetScene() {
        ulStartDrawing2D();
        ulDrawFillRect(0, 0, 256, 192, RGB15(0,0,0));
        ulEndDrawing();

        ulSyncFrame();

        ulStartDrawing2D();
        ulDrawFillRect(0, 0, 256, 192, RGB15(0,0,0));
        ulEndDrawing();
        ulSyncFrame();
        _run=1;

        //DEBUG
        DebugLogger::write("reset scene ");
       //END DEBUG


    }

    int exitcode;


};



#endif
