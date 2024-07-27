#ifndef __SaveManager_H__
#define __SaveManager_H__

#include "fat.h"

#include <map>
#include <string>
#include <sstream>

using namespace std;

class SaveManager
{
public :

    static SaveManager* ent();

    string get(string s) {
        map<string,string>::const_iterator iter = data.find(s);

        if( iter == data.end() ) {
            return "";
        } else {
            return data[s];
        }
    }

    int getInt(string s) {

        map<string,string>::const_iterator iter = data.find(s);

        if( iter == data.end() ) {
            return 0;
        } else {
            //return data[s];

            std::string text = data[s];
            int number;
            std::istringstream ss( text );
            ss >> number;

            return number;
        }



    }

    void set(string key, string dat) {
        data[key] = dat;
    }

    void set(string key, int dat) {
        ostringstream datstream;
        datstream << dat;
        //ulDrawString(155, 25, manashow.str().c_str());
        data[key] = datstream.str();
    }




    virtual ~SaveManager();
    void load();
    void save();

    map<string, string> data;

    void interpret(string s);

    int isDLDI;



private:
    SaveManager();
    static SaveManager* pinstance;

    string XOR(string value);


};



#endif
