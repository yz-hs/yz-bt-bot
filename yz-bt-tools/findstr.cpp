#pragma once
#include"findstr.h"
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
    return getstrp(str,sub)==-1?0:1;
}
