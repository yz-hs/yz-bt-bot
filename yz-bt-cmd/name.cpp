//仅作为模板，不作为代码的一部分！
#pragma name
#include "模板.hpp"
#include "../yz-bt-tools/all_include.hpp"
#include "Command.hpp"

Command name;

void NAMESETTING()
{
    name.EDIT_HELP("用法：$name [-help] *num* #str#。设置群名片。\n参数：-help 显示此命令的帮助；num QQ号；str 群名片。\n特殊：需管理员权限。");
    name.ADD_GROUPS(1093911579);name.ADD_GROUPS(1085366379);
    name.ADD_PERSONS(2378975755);
    name.SET_IS_ALLSEND(0,0);
    name.CMD_NAME("$name");
    name.EDIT_DISABLE("未为 您/本群 开启此命令！");
    return;
}

//*************************************************************可以更改以上内容

string NAMENAME()
{
    return name.NAME;
}

void NAMEMAIN(const PrivateMessageEvent &event)
{
    NAMESETTING();
    if(name.IS_ALLPERSONS==0&&name.ENABLED_PERSONS.count(event.user_id)==0)
    {
        send_message(event.target,name.DISABLE);
        return;
    }
    if(name.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,name.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,name.HELP);
    send_message(event.target,"私聊不支持此功能！");
    return;
}

void NAMEMAIN(const GroupMessageEvent &event)
{
    NAMESETTING();
    if(name.IS_ALLGROUPS==0&&name.ENABLED_GROUPS.count(event.group_id)==0)
    {
        send_message(event.target,name.DISABLE);
        return;
    }
    if(name.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,name.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,name.HELP);
    try{
        int64_t num=getncmd(event.message,1);
        string str=getscmd(event.message,1);
        set_group_card(event.group_id,num,str);
    } catch (ApiError &) {
        send_message(event.target,"请输入正确的参数！");
    }
    return;
}