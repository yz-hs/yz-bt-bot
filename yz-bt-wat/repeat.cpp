#pragma once
#include "repeat.hpp"
#include "../yz-bt-tools/all_include.hpp"
#include "../yz-bt-cmd/Command.hpp"

Command AI_Repeat;//和命令类似

void Repeat_SETTING()
{
    AI_Repeat.ADD_GROUPS(1093911579);AI_Repeat.ADD_GROUPS(1085366379);AI_Repeat.ADD_GROUPS(790890146);
    AI_Repeat.ADD_PERSONS(2378975755);
    AI_Repeat.SET_IS_ALLSEND(1,0);
}

string AI_replace(string tmp)
{
    srand(time(0));
    re_place(tmp,"我" , "您",0);
    re_place(tmp,"是吗" , "是的",0);
    re_place(tmp,"是吧" , "是的",0);
    if(rand()%2)
    {
        re_place(tmp,"是不是" , "是",0);
        re_place(tmp,"能不能" , "能",0);
        re_place(tmp,"会不会" , "会",0);
        re_place(tmp,"可以不可以" , "可以",0);
        re_place(tmp,"要不要" , "要",0);
        re_place(tmp,"有没有" , "有",0);
    }
    else
    {
        re_place(tmp,"是不是" , "不是",0);
        re_place(tmp,"能不能" , "不能",0);
        re_place(tmp,"会不会" , "不会",0);
        re_place(tmp,"可以不可以" , "不可以",0);
        re_place(tmp,"要不要" , "不要",0);
        re_place(tmp,"有没有" , "没有",0);
    }
    if(rand()%2)
    {
        re_place(tmp,"？" , "。",0);
        re_place(tmp,"?" , ".",0);
    }
    else
    {
        re_place(tmp,"？" , "！",0);
        re_place(tmp,"?" , "!",0);
    }
    re_place(tmp,"吗" , "",0);
    re_place(tmp,"吧" , "",0);
    re_place(tmp,"嘛" , "",0);
    re_place(tmp,"么" , "",0);
    re_place(tmp,"你" , "我",0);
    re_place(tmp,"yz-hs好可爱","是的呢",0);
    return tmp;
}

//私聊
bool P_REPEATMODE=1;//AI复读模式。0为无需触发标志（不建议），1为需触发标志。
string P_REPEATFLAG="$";//触发标志
int P_REPEAT_P=100;//复读概率（百分比）

//群聊
bool G_REPEATMODE=1;//AI复读模式。0为无需触发标志（不建议），1为需触发标志。
string G_REPEATFLAG="$";//触发标志
int G_REPEAT_P=100;//复读概率（百分比）

//*************************************************************可以更改以上内容

void AIrepeat(const PrivateMessageEvent &event)
{
    Repeat_SETTING();
    if(AI_Repeat.IS_ALLPERSONS==0&&AI_Repeat.ENABLED_PERSONS.count(event.user_id)==0)
        return;
    if(AI_Repeat.BLACK_PERSONS.count(event.user_id)>=1)
        return;
    string tmp=AI_replace(event.message);

    if(P_REPEATMODE)
    {
        if(!ifgetstrp(tmp,P_REPEATFLAG))
            return;
        re_place(tmp,P_REPEATFLAG,"",0);
    }
    else
    {
        if(tmp==event.message)
            return;
    }
    if(rand()%100<P_REPEAT_P)
        ex_send_message(event.target,tmp,0);
}

void AIrepeat(const GroupMessageEvent &event)
{
    Repeat_SETTING();
    if(AI_Repeat.IS_ALLGROUPS==0&&AI_Repeat.ENABLED_GROUPS.count(event.group_id)==0)
        return;
    if(AI_Repeat.BLACK_PERSONS.count(event.user_id)>=1)
        return;
    string tmp=AI_replace(event.message);

    if(G_REPEATMODE)
    {
        if(!ifgetstrp(tmp,G_REPEATFLAG))
            return;
        re_place(tmp,G_REPEATFLAG,"",0);
    }
    else
    {
        if(tmp==event.message)
            return;
    }
    if(rand()%100<G_REPEAT_P)
        ex_send_message(event.target,tmp,0);
}
