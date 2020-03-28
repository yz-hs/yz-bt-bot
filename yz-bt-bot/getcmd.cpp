/*the begin of getcmd.cpp.*/
/*写于2020-03-27*/
#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#define int64_t long long

using namespace std;

//******变量声明区

string NOT_FOUND="notfound";//404找不到

const char mcmdlist[100][100]={
    "$run",
    "$runcode",
    "$qwq",
    "$ban",
    "$set_admin",
    "$whole_ban",
    "$peo",
    "$name",
    "$about",
    "$help",
    "$rep"
};
const int mcmdnum=11;

/*
存放所有的参数
*/

const char scmdlist[100][100]={
    "-pause-",/*shit昨天忘记加逗号','导致bug一堆 —— 2020-03-28*/
    "-read-",
    "-help-"
};
const int scmdnum=3;

//******

/*
2020=03-27 写此三个函数
*/

int mymin(int a,int b)//否则找不到标识符
{
    if(a>b)
        return b;
    return a;
}

void rplace(std::string &strBig,const std::string &strsrc,const std::string &strdst)//把一个字符串中一个特定串替换为另一个特定串
{
    std::string::size_type pos=0;
    std::string::size_type srclen=strsrc.size();
    std::string::size_type dstlen=strdst.size();
    while((pos=strBig.find(strsrc,pos))!=std::string::npos)
    {
        strBig.replace(pos,srclen,strdst);
        pos+=dstlen;
    }
}

int getstrp(const std::string &str,const std::string &sub)//获取一个子串的位置
{
    std::string::size_type pos=0;
    std::string::size_type sublen=sub.size();
    pos=str.find(sub,pos);
    return pos;
}

//******

/*
2020=03-27 写此两个函数
2020-03-28 删除无用变量
           数组下标从0开始，修复此bug
           增加函数getncmd用于获取数字参数
           增加函数therescmd用于检测某个参数的存在
           增加函数getstrcmd用于获取字符串参数
*/

string getmcmd(string str)//获取主命令
{
    string re=NOT_FOUND;
    int pl=-1;
    for(int i=0;i<mcmdnum;i++)
    {
        int tmp=getstrp(str,mcmdlist[i]);
        if(tmp!=-1)
        {
            pl=((pl==-1)?(tmp):(mymin(pl,tmp)));
            if(pl==tmp)
                re=mcmdlist[i];
        }
    }
    return re;
}

string getscmd(string str)//获取参数
{
    string re=NOT_FOUND;
    int pl=-1;
    for(int i=0;i<scmdnum;i++)
    {
        int tmp=getstrp(str,scmdlist[i]);
        if(tmp!=-1)
        {
            pl=((pl==-1)?(tmp):(mymin(pl,tmp)));
            if(pl==tmp)
                re=scmdlist[i];
        }
    }
    return re;
}

int64_t getncmd(string str,int fortimes)//获取数字参数
{
    int64_t num=0,tal=0,ans=0;
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        if(str[i]=='*')
        {
            num=0,tal++;
            for(int j=i+1;str[j]>='0'&&str[j]<='9';j++)
                num=num*10+(str[j]-'0'),i=j;
            ans=num,i++;
        }
        if(tal>=fortimes) break;
    }
    return ans;
}

string getstrcmd(string str,int fortimes)//获取字符串参数
{
    int64_t tal=0;
    string ans;
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        if(str[i]=='#')
        {
            i++;int tend=i;tal++;
            for(;tend<len&&str[tend]!='#';tend++);
            if(tend<len) ans=str.substr(i,tend-i);
            i=tend+1;
        }
        if(tal>=fortimes) break;
    }
    return ans;
}

bool therecmd(string str,string sub)
{
    return getstrp(str,sub)==-1?0:1;
}

//******

/*
debug专用
*/

/*
int main()
{
    string tmp;
    cin>>tmp;
    cout<<getstrcmd(tmp,1);
}
*/

//*****

/*the end of getcmd.cpp.*/
