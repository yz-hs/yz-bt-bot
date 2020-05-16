#pragma once
#include "help.hpp"
#include "../yz-bt-tools/all_include.hpp"
#include "Command.hpp"

Command help,about;

string HELPMEG="\
\
帮助 - yz-bt：\n\
- 目前有以下命令：\n\
   qwq,help,ban,wban,about,rep,name,runcode。\n\
- 目前可监测事件：\n\
   加入/离开群，文件上传。\n\
- 其他：\n\
   彩蛋、AI复读。\
\
";//请酌情修改。

string ABOUTMEG="\
\
关于 - yz-bt：\n\
 本bot由 [CQ:at,qq=2378975755] 编写。\n\
 github：https://github.com/yz-hs/yz-bt-bot。\n\
 版本：3.0.0。\
\
";//请酌情修改。不要修改版权信息。

void HELPSETTING()
{
    help.EDIT_HELP("用法：$help [-help]。显示帮助信息。参数：-help 显示此命令的帮助。");
    help.ADD_GROUPS(1093911579);help.ADD_GROUPS(790890146);help.ADD_GROUPS(1085366379);
    help.ADD_PERSONS(2378975755);
    help.SET_IS_ALLSEND(0,0);
    help.CMD_NAME("$help");
    help.EDIT_DISABLE("未为 您/本群 开启此命令！");
    return;
}

void ABOUTSETTING()
{
    about.EDIT_HELP("用法：$about [-help]。显示关于信息。参数：-help 显示此命令的帮助。");
    about.ADD_GROUPS(1093911579);about.ADD_GROUPS(790890146);about.ADD_GROUPS(1085366379);
    about.ADD_PERSONS(2378975755);
    about.SET_IS_ALLSEND(1,1);//这个都打开吧
    about.CMD_NAME("$about");
    about.EDIT_DISABLE("未为 您/本群 开启此命令！");
    return;
}

//*************************************************************可以更改以上内容

string HELPNAME()
{
    return help.NAME;
}

string ABOUTNAME()
{
    return about.NAME;
}

void HELPMAIN(const PrivateMessageEvent &event)
{
    HELPSETTING();
    if(help.IS_ALLPERSONS==0&&help.ENABLED_PERSONS.count(event.user_id)==0)
    {
        send_message(event.target,help.DISABLE);
        return;
    }
    if(help.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,help.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,help.HELP);
    send_message(event.target,HELPMEG);
    return;
}

void ABOUTMAIN(const PrivateMessageEvent &event)
{
    ABOUTSETTING();
    if(about.IS_ALLPERSONS==0&&about.ENABLED_PERSONS.count(event.user_id)==0)
    {
        send_message(event.target,about.DISABLE);
        return;
    }
    if(about.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,about.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,about.HELP);
    send_message(event.target,ABOUTMEG);
    return;
}

void HELPMAIN(const GroupMessageEvent &event)
{
    HELPSETTING();
    if(help.IS_ALLGROUPS==0&&help.ENABLED_GROUPS.count(event.group_id)==0)
    {
        send_message(event.target,help.DISABLE);
        return;
    }
    if(help.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,help.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,help.HELP);
    send_message(event.target,HELPMEG);
    return;
}

void ABOUTMAIN(const GroupMessageEvent &event)
{
    ABOUTSETTING();
    if(about.IS_ALLGROUPS==0&&about.ENABLED_GROUPS.count(event.group_id)==0)
    {
        send_message(event.target,about.DISABLE);
        return;
    }
    if(about.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,about.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,about.HELP);
    send_message(event.target,ABOUTMEG);
    return;
}