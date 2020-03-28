/*the begin of getcmd.cpp.*/
/*写于2020-03-27*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include"getcmd.hpp"

using namespace std;

//******

/*
2020=03-27 写此三个函数
*/

int min(int a,int b)//否则找不到标识符
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
            pl=((pl==-1)?(tmp):(min(pl,tmp)));
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
            pl=((pl==-1)?(tmp):(min(pl,tmp)));
            if(pl==tmp)
                re=scmdlist[i];
        }
    }
    return re;
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
    cout<<getscmd(tmp);
}
*/

//*****

/*the end of getcmd.cpp.*/