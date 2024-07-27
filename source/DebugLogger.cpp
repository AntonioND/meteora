/**
 * Save manager
 */

#include "DebugLogger.h"

#include <string>
#include <sstream>


using namespace std;

DebugLogger* DebugLogger::pinstance = 0;// initialize pointer

DebugLogger* DebugLogger::ent() {
    if (pinstance == 0)  // is it the first call?
    {
      pinstance = new DebugLogger(); // create sole instance
    }
    return pinstance; // address of sole instance


}

DebugLogger::DebugLogger() {

  //init fatlib
#ifdef SAVE
#ifdef DEBUGSAVE
  fatInitDefault();

  FILE* file = fopen ("meteora_debug.log", "w");
  fclose(file);

  debug = 1;
#endif
#endif
}

DebugLogger::~DebugLogger() {
}

void DebugLogger::write(string s) {
#ifdef SAVE
#ifdef DEBUGSAVE
   DebugLogger::ent();

   FILE* file = fopen ("meteora_debug.log", "a+");
        fputs(s.c_str(),file);
        fputs("\n",file);
   fclose(file);
#endif
#endif
}
