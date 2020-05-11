#pragma once
#include <string>
#include "ex_sendmsg.hpp"
#include "findstr.hpp"

using namespace std;

string MSGCUT="(cut)";//消息分隔符
string RP_MSGCUT="(fuk)";//请保证这个和MSGCUT长度相同，内容可以任意改，只要不冲突无影响。

int MAXCUT=4;//最大分割次数

//*************************************************************可以更改以上内容

void ex_send_message(Target target,string msg,bool at_user)
{
    string sendmsg[1000];
    int num=0,posp=0,posn=0;
    re_place(msg,MSGCUT,RP_MSGCUT,0);
    while(true)
    {
        int tmp=getstrp(msg,RP_MSGCUT);
        re_place(msg,RP_MSGCUT,MSGCUT,1);
        if(num>=MAXCUT-1||posp==-1||tmp==-1)
            break;
        posn=tmp;
        sendmsg[++num]=msg.substr(posp,posn-posp);
        posp=posn+MSGCUT.size();
    }
    re_place(msg,RP_MSGCUT,MSGCUT,0);
    if(posn==-1) posn=0-MSGCUT.size();
    sendmsg[++num]=msg.substr(posn+MSGCUT.size(),msg.size()-(posn+MSGCUT.size()));
    for(int i=1;i<=num;i++)
        send_message(target,sendmsg[i],at_user);
}