#ifndef __CNetworkAI_H__
#define __CNetworkAI_H__

#include "CSimpleAI.h"

#include "CTextDecal.h"

class CNetworkAI : public CSimpleAI
{
public :
    CNetworkAI();

    virtual ~CNetworkAI();


    virtual void manageBullet(int, CBullet *);

    virtual void thinking();

    int lastPassedTime;

    int iter;

    int start;
    int gameid;

    int connected;

    void connect();

    CTextDecal * textDecal;

private:

    int sock;
    int userid;
    char _tmp_buffer[256];
    string buffer;

    void interpret(string s);
};



#endif
