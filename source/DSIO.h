#ifndef __DSIO_H__
#define __DSIO_H__

#include "fat.h"

#include <map>
#include <string>
#include <sstream>

using namespace std;

class DSIO
{
public :

    static DSIO* ent();

    virtual ~DSIO();




    int hasDSIO;
    
    int rumbleCount;
    int ledCount;


    void rumbleOn();
    void rumbleOff();
    
    void ledOn();
    void ledOff();
    
private:
    DSIO();
    static DSIO* pinstance;

};



#endif
