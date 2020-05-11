#pragma once
#include"findstr.hpp"
using namespace std;

void re_place(string &strBig,const string &strsrc,const string &strdst,bool type)//文本串，被替换串，替换串，类型（1为替换1次，0为全部替换）
{
    string::size_type pos=0;
    string::size_type srclen=strsrc.size();
    string::size_type dstlen=strdst.size();
    while((pos=strBig.find(strsrc,pos))!=string::npos)
    {
        strBig.replace(pos,srclen,strdst);
        pos+=dstlen;
        if(type==1)
            return;
    }
    return;
}

int getstrp(const string &str,const string &sub)//返回格式串在文本串中的位置（无则返回-1）
{
    string::size_type pos=0;
    string::size_type sublen=sub.size();
    pos=str.find(sub,pos);
    return pos;
}

bool ifgetstrp(const string &str,const string &sub)//返回格式串是否在文本串中
{
    if(getstrp(str,sub)==-1)
        return 0;
    return 1;
}

int64_t mymin(int64_t a,int64_t b)
{
    if(a<b)
        return a;
    return b;
}

int64_t mymax(int64_t a,int64_t b)
{
    if(a>b)
        return a;
    return b;
}
