#ifndef __DebugLogger_H__
#define __DebugLogger_H__

#include "fat.h"

#include <map>
#include <string>
#include <sstream>

#define SAVE
//#define DEBUGSAVE

using namespace std;

class DebugLogger
{
public :

    static DebugLogger* ent();

    virtual ~DebugLogger();

    static void write(string s);

    int debug;




private:
    DebugLogger();
    static DebugLogger* pinstance;
};



#endif
