#pragma once
#include <string>
#include "ex_sendmsg.hpp"
#include "findstr.hpp"

using namespace std;

string MSGCUT="(cut)";//消息分隔符
string RP_MSGCUT=")tuc(";//请保证这个和MSGCUT长度相同，内容可以任意改，只要不冲突无影响。

const int MAXCUT=4;//最大分割次数

const int MAXLEN=60;//消息长度限制

//*************************************************************可以更改以上内容

string sendmsg[1000];
int num=0;

void EX_SMSG_INIT()
{
    num=0;
}

void cut_message(Target target,string msg)
{
    int posp=0,posn=0;
    re_place(msg,MSGCUT,RP_MSGCUT,0);
    while(true)
    {
        int tmp=getstrp(msg,RP_MSGCUT);
        re_place(msg,RP_MSGCUT,MSGCUT,1);
        if(num>=MAXCUT-1)
        {
            send_message(target,"消息最多被分割"+to_string(MAXCUT)+"次，之后以纯文本复读。");
            break;
        }
        if(posp==-1||tmp==-1)
            break;
        posn=tmp;
        sendmsg[++num]=msg.substr(posp,posn-posp);
        posp=posn+MSGCUT.size();
    }
    re_place(msg,RP_MSGCUT,MSGCUT,0);
    if(posn==-1) posn=0-MSGCUT.size();
    sendmsg[++num]=msg.substr(posn+MSGCUT.size(),msg.size()-(posn+MSGCUT.size()));
}

void ex_send_message(Target target,string msg,bool at_user)
{
    EX_SMSG_INIT();
    if(msg.size()>=MAXLEN)
    {
        msg=msg.substr(0,MAXLEN);
        msg=msg+"\n(消息过长，已被截断)";
    }
    if(ifgetstrp(msg,MSGCUT))
        cut_message(target,msg);
    else
        sendmsg[++num]=msg;
    for(int i=1;i<=num;i++)
        send_message(target,sendmsg[i],at_user);
}