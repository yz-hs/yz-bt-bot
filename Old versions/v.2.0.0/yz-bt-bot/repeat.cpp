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
extern bool therecmd(string str,string sub);
extern bool REPEATMODE;
extern string REPEATFLAG;
extern int REPEAT_P;
extern int REPEAT_FTIME;
extern string NOT_FOUND;

int64_t spmelistcnt=7;
class SPECIALMESSAGE
{
    public:
      string readlist[100];
      string reply;
      int64_t readcnt;
}spmelist[1000];

void spmelistwork()
{
    spmelist[1].readcnt=2;
    spmelist[1].readlist[1]="IOI";spmelist[1].readlist[2]="AK";
    spmelist[1].reply="orz！太强了！%%%！";

    spmelist[2].readcnt=1;
    spmelist[2].readlist[1]="嘤";
    spmelist[2].reply="(*≧▽≦)o☆";

    spmelist[3].readcnt=1;
    spmelist[3].readlist[1]="[CQ:face,id=187]";
    spmelist[3].reply="(*≧▽≦)o☆";

    spmelist[4].readcnt=1;
    spmelist[4].readlist[1]="yz-hs";
    spmelist[4].reply="谁叫她？叫她干吗？[CQ:face,id=187]";

    spmelist[5].readcnt=1;
    spmelist[5].readlist[1]="yz-bt";
    spmelist[5].reply="谁叫我？叫我干吗？[CQ:face,id=187]";

    spmelist[6].readcnt=1;
    spmelist[6].readlist[1]="图灵测试";
    spmelist[6].reply="图灵测试？那玩意我早过了！";

    spmelist[7].readcnt=1;
    spmelist[7].readlist[1]="orz";
    spmelist[7].reply="orz！太强了！%%%！";
}
string AIrepeat(string tmp)
{
    string cmp=tmp;
    srand(time(0));spmelistwork();
    for(int i=1;i<=spmelistcnt;i++)
    {
        bool flag=1;
        for(int j=1;j<=spmelist[i].readcnt;j++)
            if(!therecmd(tmp,spmelist[i].readlist[j]))
            {
                flag=0;
                break;
            }
        if(flag)
            return spmelist[i].reply;
    }
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
    }
    else
    {
        rplace(tmp,"是不是" , "不是");
        rplace(tmp,"能不能" , "不能");
        rplace(tmp,"会不会" , "不会");
        rplace(tmp,"可以不可以" , "不可以");
        rplace(tmp,"要不要" , "不要");
        rplace(tmp,"有没有" , "没有");
    }
    if(rand()%2)
    {
        rplace(tmp,"？" , "。");
        rplace(tmp,"?" , ".");
    }
    else
    {
        rplace(tmp,"？" , "！");
        rplace(tmp,"?" , "!");
    }
    rplace(tmp,"吗" , "");
    rplace(tmp,"吧" , "");
    rplace(tmp,"嘛" , "");
    rplace(tmp,"么" , "");
    rplace(tmp,"你" , "我");
    rplace(tmp,"yz-hs好可爱","是的呢");
    rplace(tmp,"好强"," orz");
    rplace(tmp,"太强了"," %%%");
    if(REPEATMODE==0)
    {
        if(!therecmd(tmp,REPEATFLAG))
            return NOT_FOUND;
        else
            rplace(tmp,REPEATFLAG,"");
    }
    else
    {
        if(tmp==cmp)
            return NOT_FOUND;
    }
    if(rand()%100>REPEAT_P)
        return NOT_FOUND;
    return tmp;
}
