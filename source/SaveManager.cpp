/**
 * Save manager
 */

#include "SaveManager.h"

#include <string>
#include <sstream>

#include "DebugLogger.h"

#include <ulib/ulib.h>


using namespace std;

SaveManager* SaveManager::pinstance = 0;// initialize pointer

SaveManager* SaveManager::ent ()
{
    if (pinstance == 0)  // is it the first call?
    {
      pinstance = new SaveManager(); // create sole instance
    }
    return pinstance; // address of sole instance
}

SaveManager::SaveManager() {

  //init fatlib
  isDLDI = fatInitDefault();
  ulSyncFrame();
  ulSyncFrame();
  ulSyncFrame();

#ifdef SAVE

if (isDLDI) {
    load();
}
#endif
}

SaveManager::~SaveManager() {
}


string SaveManager::XOR(string value)
{

    string key = "155z9ezrcssffzA((ytù%^,;sldfeszeresqQQ<wx,,:mù4846464Wp^¨!§:..,;ù^^\(^o^)/";

    int klen=key.length();
    int vlen=value.length();
    //unsigned int v=0;
    int v;

    string val2 = value;

    for(v = 0; v < vlen ; v++)
    {
        if (val2[v]!= key[v%klen]) {
            val2[v]=value[v]^key[v%klen];
        }
        //k=(++k<klen?k:0);
    }

    return val2;
}


void SaveManager::load() {
  FILE * pFile;
  long lSize;
  char * buffer;
  size_t result;

  string savedata;

  pFile = fopen ( "meteora_save.bin" , "rb" );

  if (pFile==NULL) { //if can't open
    pFile = fopen ( "meteora_save.bin" , "wb" );  //create the savegame
    fclose(pFile);

    pFile = fopen ( "meteora_save.bin" , "rb" );
  }

  if (pFile!=NULL) { //file error

  // obtain file size:
  fseek (pFile , 0 , SEEK_END);
  lSize = ftell (pFile);
  rewind (pFile);

  // allocate memory to contain the whole file:
  buffer = (char*) malloc (sizeof(char)*lSize);
  //if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  // copy the file into the buffer:
  result = fread (buffer,1,lSize,pFile);
  //if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

  savedata = string(buffer);

  ostringstream logstream4;
  logstream4 << "original loaded savedata :\n" << savedata << "\n" ;

  savedata = this->XOR(savedata);

  logstream4 << "decrypted savedata :\n" << savedata << "\n" ;
  DebugLogger::write(logstream4.str());

  interpret(savedata);

  /* the whole file is now loaded in the memory buffer. */

  // terminate
  fclose (pFile);
  free (buffer);
  }
}


void SaveManager::interpret(string s) {
 string e = string("¬");

 int iPos = s.find(e, 0);
 int iPit = e.length();

 int i = 0;

 string key;

 while(iPos>-1) {
   if(iPos!=0) {
     i++;

     if (i%2==1) {
        key = s.substr(0,iPos);
     } else {
        data[key] = s.substr(0,iPos);
     }

     //ret.push_back(s.substr(0,iPos));
   }
   s.erase(0,iPos+iPit);   // poistetaan stringistä ylimääräiset scheißet
   iPos = s.find(e, 0);    // haetaan erottimen sijainti
 }
 i++;
  // end while
 if(s!="") //handle last entity
   if (i%2==0)
        data[key] = s;


}

void SaveManager::save() {
#ifdef SAVE

if (isDLDI) {
      ostringstream strout;

      //ulDrawString(155, 25, manashow.str().c_str());


      map<string, string>::const_iterator data_iter;
                for (data_iter=data.begin(); data_iter != data.end(); data_iter++) {

                    strout << data_iter->first << "¬" << data_iter->second << "¬";

                    //ulDeleteImage(_resourcesMap[texname]);
                }

        FILE * pFile;
        pFile = fopen ( "meteora_save.bin" , "wb" );  //create the savegame
        string finaldat = strout.str().c_str();

        ostringstream logstream4;
        logstream4 << "original finaldat :\n" << finaldat << "\n" ;


        finaldat = this->XOR(finaldat);
        logstream4 << "encrypted finaldat :\n" << finaldat << "\n" ;
        DebugLogger::write(logstream4.str());

        fputs(finaldat.c_str(), pFile);
        fclose(pFile);
}
#endif
}
