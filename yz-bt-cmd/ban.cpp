#pragma once
#include "ban.hpp"
#include "../yz-bt-tools/all_include.hpp"
#include "Command.hpp"

Command ban,wban;

void BANSETTING()
{
    ban.EDIT_HELP("用法：$ban [-help] *num1* *num2*。\n参数：-help 输出帮助信息；num1 QQ号；num2 时间（秒）。\n特殊：需管理员权限。");
    ban.ADD_GROUPS(1093911579);ban.ADD_GROUPS(1085366379);
    ban.ADD_PERSONS(2378975755);
    ban.SET_IS_ALLSEND(0,0);
    ban.CMD_NAME("$ban");
    ban.EDIT_DISABLE("未为 您/本群 开启此命令！");
    return;
}

void WBANSETTING()
{
    wban.EDIT_HELP("用法：$wban [-help] *num(bool)*。\n参数：-help 输出帮助信息；num 是(1)否(0)开启。\n特殊：需管理员权限。");
    wban.ADD_GROUPS(1093911579);wban.ADD_GROUPS(1085366379);
    wban.ADD_PERSONS(2378975755);
    wban.SET_IS_ALLSEND(0,0);
    wban.CMD_NAME("$wban");
    wban.EDIT_DISABLE("未为 您/本群 开启此命令！");
    return;
}

//*************************************************************可以更改以上内容

string BANNAME()
{
    return ban.NAME;
}

string WBANNAME()
{
    return wban.NAME;
}

void BANMAIN(const PrivateMessageEvent &event)
{
    BANSETTING();
    if(ban.IS_ALLPERSONS==0&&ban.ENABLED_PERSONS.count(event.user_id)==0)
    {
        send_message(event.target,ban.DISABLE);
        return;
    }
    if(ban.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,ban.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,ban.HELP);
    send_message(event.target,"私聊不支持此功能！");
    return;
}

void WBANMAIN(const PrivateMessageEvent &event)
{
    WBANSETTING();
    if(wban.IS_ALLPERSONS==0&&wban.ENABLED_PERSONS.count(event.user_id)==0)
    {
        send_message(event.target,wban.DISABLE);
        return;
    }
    if(wban.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,wban.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,wban.HELP);
    send_message(event.target,"私聊不支持此功能！");
    return;
}

void BANMAIN(const GroupMessageEvent &event)
{
    BANSETTING();
    if(ban.IS_ALLGROUPS==0&&ban.ENABLED_GROUPS.count(event.group_id)==0)
    {
        send_message(event.target,ban.DISABLE);
        return;
    }
    if(ban.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,ban.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,ban.HELP);
    try{
        int64_t QQnum=getncmd(event.message,1);
        int64_t fortime=getncmd(event.message,2);
        set_group_ban(event.group_id,QQnum,fortime);
    } catch (ApiError &) {
        send_message(event.target,"请输入正确的参数！");
    }
    return;
}

void WBANMAIN(const GroupMessageEvent &event)
{
    WBANSETTING();
    if(wban.IS_ALLGROUPS==0&&wban.ENABLED_GROUPS.count(event.group_id)==0)
    {
        send_message(event.target,wban.DISABLE);
        return;
    }
    if(wban.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,wban.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,wban.HELP);
    try{
        int64_t ifenable=getncmd(event.message,1);
        set_group_whole_ban(event.group_id,ifenable);
    } catch (ApiError &) {
        send_message(event.target,"请输入正确的参数！");
    }
    return;
}