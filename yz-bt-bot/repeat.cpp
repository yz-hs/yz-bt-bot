/*
欢迎大家让 一亿核心AI代码 变得更值钱！（误
*/

#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<time.h>

using namespace std;

extern void rplace(std::string &strBig,const std::string &strsrc,const std::string &strdst);

string AIrepeat(string tmp)
{
    srand(time(0));
    rplace(tmp,"$" , "");
    rplace(tmp,"我" , "您");
    rplace(tmp,"是吗" , "是的");
    rplace(tmp,"是吧" , "是的");
    if(rand()%2)
    {
        rplace(tmp,"是不是" , "是");
        rplace(tmp,"能不能" , "能");
        rplace(tmp,"会不会" , "会");
        rplace(tmp,"可以不可以" , "可以");
        rplace(tmp,"要不要" , "要");
        rplace(tmp,"有没有" , "有");
        rplace(tmp,"？" , "。");
        rplace(tmp,"?" , ".");
    }
    else
    {
        rplace(tmp,"是不是" , "不是");
        rplace(tmp,"能不能" , "不能");
        rplace(tmp,"会不会" , "不会");
        rplace(tmp,"可以不可以" , "不可以");
        rplace(tmp,"要不要" , "不要");
        rplace(tmp,"有没有" , "没有");
        rplace(tmp,"？" , "！");
        rplace(tmp,"?" , "!");
    }
    rplace(tmp,"吗" , "");
    rplace(tmp,"吧" , "");
    rplace(tmp,"嘛" , "");
    rplace(tmp,"么" , "");
    rplace(tmp,"你" , "我");
    rplace(tmp,"stop" , "不可能的");
    rplace(tmp,"yz-hs好可爱","是的呢");
    rplace(tmp,"好强"," orz");
    rplace(tmp,"太强了"," %%%");
    return tmp;
}
