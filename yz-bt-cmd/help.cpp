#pragma once
#include "help.hpp"
#include "../yz-bt-tools/all_include.hpp"
#include "Command.hpp"

Command help;

string HELPMEG="\
\
帮助信息：\n\
- 目前有以下命令：\n\
   qwq,help,ban。\n\
- 目前可监测事件：\n\
   加入/离开群，文件上传。\
\
";//请酌情修改。

void HELPSETTING()
{
    help.EDIT_HELP("用法：$help [-help]。显示帮助信息。参数：-help 显示此命令的帮助。");
    help.ADD_GROUPS(1093911579);
    help.ADD_PERSONS(2378975755);
    help.SET_IS_ALLSEND(0,0);
    help.CMD_NAME("$help");
    help.EDIT_DISABLE("未为 您/本群 开启此命令！");
    return;
}

//*************************************************************可以更改以上内容

string HELPNAME()
{
    return help.NAME;
}

void HELPMAIN(const PrivateMessageEvent &event)
{
    HELPSETTING();
    if(help.IS_ALLPERSONS==0&&help.ENABLED_PERSONS.count(event.user_id)==0)
    {
        send_message(event.target,help.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,help.HELP);
    send_message(event.target,HELPMEG);
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
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,help.HELP);
    send_message(event.target,HELPMEG);
    return;
}