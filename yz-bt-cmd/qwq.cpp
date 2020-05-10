#pragma once
#include "qwq.hpp"
#include "../yz-bt-tools/all_include.hpp"
#include "Command.hpp"

Command qwq;

string QWQLIST[]={
    "(๑•̀ㅂ•́)و✧","w(ﾟДﾟ)w","(ノへ￣、)","(￣_,￣ )","ヽ(✿ﾟ▽ﾟ)ノ","(￣ε(#￣)☆╰╮o(￣皿￣///)",
    "（づ￣3￣）づ╭❤～","Σ( ° △ °|||)︴","(～￣(OO)￣)ブ","凸(艹皿艹 )","(* ￣3)(ε￣ *)",
    "(*￣rǒ￣)","┗|｀O′|┛ 嗷~~","φ(≧ω≦*)♪","︿(￣︶￣)︿","(u‿ฺu✿ฺ)","Hi~ o(*￣▽￣*)ブ",
    "♪(^∇^*)","o(*≧▽≦)ツ┏━┓","╰(*°▽°*)╯"
};

int QWQCNT=20;

void QWQSETTING()
{
    qwq.EDIT_HELP("用法：$qwq [-help]。随机卖萌。参数：-help 显示此命令的帮助。");
    qwq.ADD_GROUPS(1093911579);
    qwq.ADD_PERSONS(2378975755);
    qwq.SET_IS_ALLSEND(0,0);
    qwq.CMD_NAME("$qwq");
    qwq.EDIT_DISABLE("未为 您/本群 开启此命令！");
    return;
}

//*************************************************************可以更改以上内容

string QWQNAME()
{
    return qwq.NAME;
}

void QWQMAIN(const PrivateMessageEvent &event)
{
    QWQSETTING();
    srand(time(0));
    if(qwq.IS_ALLPERSONS==0&&qwq.ENABLED_PERSONS.count(event.user_id)==0)
    {
        send_message(event.target,qwq.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,qwq.HELP);
    send_message(event.target,QWQLIST[rand()%20+1]);
    return;
}

void QWQMAIN(const GroupMessageEvent &event)
{
    QWQSETTING();
    srand(time(0));
    if(qwq.IS_ALLGROUPS==0&&qwq.ENABLED_GROUPS.count(event.group_id)==0)
    {
        send_message(event.target,qwq.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,qwq.HELP);
    send_message(event.target,QWQLIST[rand()%20+1]);
    return;
}