/**
 * Save manager
 */

#include "DSIO.h"

#include <string>
#include <sstream>

#include "DebugLogger.h"

#include "DSIOdevice.h"

#include <ulib/ulib.h>


using namespace std;

DSIO* DSIO::pinstance = 0;// initialize pointer

DSIO* DSIO::ent ()
{
    if (pinstance == 0)  // is it the first call?
    {
      pinstance = new DSIO(); // create sole instance
    }
    return pinstance; // address of sole instance
}

DSIO::DSIO() {
    DSIO_Init();
    hasDSIO = DSIO_Connect();
    
    rumbleCount = 0;
    ledCount =0;
}

DSIO::~DSIO() {
}

void DSIO::rumbleOn() {
    if (!hasDSIO)
        return;
    if (rumbleCount==0) {
        DSIO_Rumble_On();
    }
    rumbleCount++;
}

void DSIO::ledOn() {
    if (!hasDSIO)
        return;
    if (ledCount==0) {
        DSIO_LedOn();
    }
    ledCount++;
}

void DSIO::ledOff() {
    if (!hasDSIO)
        return;
    ledCount--;
    if (ledCount==0) {
        DSIO_LedOff();
    }  
}

void DSIO::rumbleOff() {
    if (!hasDSIO)
        return;
    rumbleCount--;
    if (rumbleCount==0) {
        DSIO_Rumble_Off();
    }  
}