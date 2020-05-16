/*#pragma once
#include "oier.hpp"
#include "../yz-bt-tools/all_include.hpp"
#include "Command.hpp"

Command oier;

void OIERSETTING()
{
    oier.EDIT_HELP("用法：$oier [-help] #str#。查询某个大佬OIer的记录。\n参数：-help 显示此命令的帮助；str 查询关键字。");
    oier.ADD_GROUPS(1093911579);oier.ADD_GROUPS(1085366379);oier.ADD_GROUPS(790890146);
    oier.ADD_PERSONS(2378975755);
    oier.SET_IS_ALLSEND(0,0);
    oier.CMD_NAME("$oier");
    oier.EDIT_DISABLE("未为 您/本群 开启此命令！");
    return;
}

//*************************************************************可以更改以上内容

string QueryAddress="http://bytew.net/OIer/search.php?method=normal&q=";

string OIERNAME()
{
    return oier.NAME;
}

void OIERMAIN(const PrivateMessageEvent &event)
{
    OIERSETTING();
    if(oier.IS_ALLPERSONS==0&&oier.ENABLED_PERSONS.count(event.user_id)==0)
    {
        send_message(event.target,oier.DISABLE);
        return;
    }
    if(oier.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,oier.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,oier.HELP);
    string QueryStr=getscmd(event.message,1);
    QueryAddress=QueryAddress+QueryStr;
    return;
}

void OIERMAIN(const GroupMessageEvent &event)
{
    OIERSETTING();
    if(oier.IS_ALLGROUPS==0&&oier.ENABLED_GROUPS.count(event.group_id)==0)
    {
        send_message(event.target,oier.DISABLE);
        return;
    }
    if(oier.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,oier.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,oier.HELP);
    string QueryStr=getscmd(event.message,1);
    QueryAddress=QueryAddress+QueryStr;
    return;
}*/
//待补充