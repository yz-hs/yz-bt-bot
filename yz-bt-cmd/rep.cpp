#pragma once
#include "rep.hpp"
#include "../yz-bt-tools/all_include.hpp"
#include "Command.hpp"

Command rep;

void REPSETTING()
{
    rep.EDIT_HELP("用法：$rep [-help] *num* #str#。复读您的消息（最多5次）。\n参数：-help 显示此命令的帮助；num 复读次数；str 复读内容。\n特殊：可以使用特殊识别符");
    rep.ADD_GROUPS(1093911579);rep.ADD_GROUPS(790890146);rep.ADD_GROUPS(1085366379);
    rep.ADD_PERSONS(2378975755);
    rep.SET_IS_ALLSEND(0,0);
    rep.CMD_NAME("$rep");
    rep.EDIT_DISABLE("未为 您/本群 开启此命令！");
    return;
}

int REPMAXNUM=5;//最多复读次数

//*************************************************************可以更改以上内容

string REPNAME()
{
    return rep.NAME;
}

void REPMAIN(const PrivateMessageEvent &event)
{
    REPSETTING();
    if(rep.IS_ALLPERSONS==0&&rep.ENABLED_PERSONS.count(event.user_id)==0)
    {
        send_message(event.target,rep.DISABLE);
        return;
    }
    if(rep.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,rep.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,rep.HELP);
    try{
        int64_t num=getncmd(event.message,1);
        string str=getscmd(event.message,1);
        if(num>=REPMAXNUM) num=REPMAXNUM;
        for(int i=1;i<=num;i++)
            ex_send_message(event.target,str,0);
    } catch (ApiError &) {
        send_message(event.target,"请输入正确的参数！");
    }
    return;
}

void REPMAIN(const GroupMessageEvent &event)
{
    REPSETTING();
    if(rep.IS_ALLGROUPS==0&&rep.ENABLED_GROUPS.count(event.group_id)==0)
    {
        send_message(event.target,rep.DISABLE);
        return;
    }
    if(rep.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,rep.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,rep.HELP);
    try{
        int64_t num=getncmd(event.message,1);
        string str=getscmd(event.message,1);
        if(num>=REPMAXNUM) num=REPMAXNUM;
        for(int i=1;i<=num;i++)
            ex_send_message(event.target,str,0);
    } catch (ApiError &) {
        send_message(event.target,"请输入正确的参数！");
    }
    return;
}