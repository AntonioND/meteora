/*

    Sprite class for player ship

*/

#include "CScene.h"

#include <cstdlib>
#include <time.h>
#include "explosion.h"
#include "small_explosion.h"


#include "explode.h"

#include "debuglogger.h"

string timeToString(int time) {
    ostringstream timeshow;
    timeshow << ((int)time/60)<<":";


    if ((int)time%60<10) {
        timeshow << "0";
    }
    timeshow << time%60;

    return timeshow.str();
}

unsigned short int CScene::_run=1;





CScene::CScene() {
    //CScene::_run=1;
    nextScene = NULL;
    exitcode = 0;

        //DEBUG
        DebugLogger::write("new CScene construction");
       //END DEBUG
}

CScene::~CScene() {
        //DEBUG
        DebugLogger::write("CScene removal");
       //END DEBUG
}


void CScene::render() {


}
