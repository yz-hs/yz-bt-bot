#pragma once
#include "runcode.hpp"
#include "../yz-bt-tools/all_include.hpp"
#include "Command.hpp"
#include <iostream>
#include <fstream>

Command runcode;

void RUNCODESETTING()
{
    runcode.EDIT_HELP("用法：$runcode [-cache] [-help] [-read] #str# [#read#]。运行dongbei代码并缓存。\n参数：-help 显示此命令的帮助；str 你的代码；read 读入数据 ；-cache 运行缓存代码，请保留#str#参数。");
    runcode.ADD_GROUPS(1093911579);runcode.ADD_GROUPS(790890146);runcode.ADD_GROUPS(1085366379);
    runcode.ADD_PERSONS(2378975755);
    runcode.SET_IS_ALLSEND(0,0);
    runcode.CMD_NAME("$runcode");
    runcode.EDIT_DISABLE("未为 您/本群 开启此命令！");
    return;
}

//*************************************************************可以更改以上内容

string RUNCODENAME()
{
    return runcode.NAME;
}

void SaveRead(string code)
{
    string tmp,ans;
    ofstream fout;

    fout.open("./yz-bt-run/read.txt");
    fout.imbue(std::locale("chs"));
    fout<<code.c_str();fout.close();
}

void SaveCode(string code)
{
    string tmp,ans;
    ofstream fout2;

    fout2.open("./yz-bt-run/code.txt");
    fout2.imbue(std::locale("chs"));
    fout2<<code.c_str();fout2.close();
}

string RunCode()
{
    system("yz-bt-run\\dongbei.py .\\yz-bt-run\\code.txt < .\\yz-bt-run\\read.txt > .\\yz-bt-run\\ans.txt");
    filebuf fin;
    fin.open("./yz-bt-run/ans.txt", ios::in);
    istream isInput(&fin);
    istreambuf_iterator<char> bit(isInput), eit;
    string ans(bit, eit);
    fin.close();
    return ans;
}

void RUNCODEMAIN(const PrivateMessageEvent &event)
{
    RUNCODESETTING();
    if(runcode.IS_ALLPERSONS==0&&runcode.ENABLED_PERSONS.count(event.user_id)==0)
    {
        send_message(event.target,runcode.DISABLE);
        return;
    }
    if(runcode.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,runcode.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,runcode.HELP);
    string code=getscmd(event.message,1),read;
    if(ifgetstrp(event.message,"-read"))
        read=getscmd(event.message,2),SaveRead(read);
    if(ifgetstrp(event.message,"-cache"))
    {
        send_message(event.target,"运行结果：\n"+RunCode());
        return;
    }
    SaveCode(code);
    send_message(event.target,"运行结果：\n"+RunCode());
    return;
}

void RUNCODEMAIN(const GroupMessageEvent &event)
{
    RUNCODESETTING();
    if(runcode.IS_ALLGROUPS==0&&runcode.ENABLED_GROUPS.count(event.group_id)==0)
    {
        send_message(event.target,runcode.DISABLE);
        return;
    }
    if(runcode.BLACK_PERSONS.count(event.user_id)>=1)
    {
        send_message(event.target,runcode.DISABLE);
        return;
    }
    if(ifgetstrp(event.message,"-help"))
        send_message(event.target,runcode.HELP);
    string code=getscmd(event.message,1),read;
    if(ifgetstrp(event.message,"-read"))
        read=getscmd(event.message,2),SaveRead(read);
    if(ifgetstrp(event.message,"-cache"))
    {
        send_message(event.target,"运行结果：\n"+RunCode());
        return;
    }
    SaveCode(code);
    send_message(event.target,"运行结果：\n"+RunCode());
    return;
}