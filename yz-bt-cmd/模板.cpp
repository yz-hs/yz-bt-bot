//仅作为模板，不作为代码的一部分！
#pragma once
#include "模板.hpp"
#include "../yz-bt-tools/all_include.hpp"
#include "Command.hpp"

Command _;

void _SETTING()
{
    _.EDIT_HELP("用法：$_ [-help]。模板。参数：-help 显示此命令的帮助。");
    _.ADD_GROUPS(1093911579);
    _.ADD_PERSONS(2378975755);
    _.SET_IS_ALLSEND(0,0);
    _.CMD_NAME("$_");
    _.EDIT_DISABLE("未为 您/本群 开启此命令！");
    return;
}

//*************************************************************可以更改以上内容

string _NAME()
{
    return _.NAME;
}

void _MAIN(const PrivateMessageEvent &event)
{
    _SETTING();
    if(_.IS_ALLPERSONS==0&&_.ENABLED_PERSONS.count(event.user_id)==0)
    {
        send_message(event.target,_.DISABLE);
        return;
    }
    if(_.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,_.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,_.HELP);
    send_message(event.target,"模板。");
    return;
}

void _MAIN(const GroupMessageEvent &event)
{
    _SETTING();
    if(_.IS_ALLGROUPS==0&&_.ENABLED_GROUPS.count(event.group_id)==0)
    {
        send_message(event.target,_.DISABLE);
        return;
    }
    if(_.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,_.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,_.HELP);
    send_message(event.target,"模板。");
    return;
}