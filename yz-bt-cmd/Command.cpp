#pragma once
#include <cqcppsdk/cqcppsdk.h>
#include "Command.hpp"
#include "../yz-bt-tools/all_include.hpp"
using namespace cq;
using namespace std;

void Command::EDIT_HELP(string tmp){HELP=tmp;return;}
void Command::EDIT_DISABLE(string tmp){DISABLE=tmp;return;}
void Command::ADD_GROUPS(int64_t num){ENABLED_GROUPS.insert(num);return;}
void Command::ADD_PERSONS(int64_t num){ENABLED_PERSONS.insert(num);return;}
void Command::SET_IS_ALLSEND(bool a,bool b){IS_ALLPERSONS=a;IS_ALLGROUPS=b;return;}
void Command::CMD_NAME(string tmp){NAME=tmp;return;}
void Command::ADD_BPERSONS(int64_t num){BLACK_PERSONS.insert(num);return;}

string NFLAG="*";//数字参数识别符
string SFLAG="#";//字符串参数识别符
string RP_SFLAG="@";//请保证这个和SFLAG长度相同，内容可以任意改，只要不冲突无影响。

int64_t getncmd(string str,int fortimes)
{
    int64_t num=0,tal=0,ans=0;
    for(int i=1;i<=fortimes;i++)
    {
        num=0;
        int posp=getstrp(str,NFLAG);
        re_place(str,NFLAG,"",1);
        int posn=getstrp(str,NFLAG);
        re_place(str,NFLAG,"",1);
        for(int j=posp;j<=posn-1&&j<str.size();j++)
            if(str[j]>='0'&&str[j]<='9')
                num=num*10+str[j]-'0';
        ans=num;
    }
    return ans;
}

string getscmd(string str,int fortimes)
{
    int64_t tal=0;
    string ans;
    re_place(str,SFLAG,RP_SFLAG,0);
    for(int i=1;i<=fortimes;i++)
    {
        int posp=getstrp(str,RP_SFLAG);
        re_place(str,RP_SFLAG,SFLAG,1);
        int posn=getstrp(str,RP_SFLAG);
        re_place(str,RP_SFLAG,SFLAG,1);
        ans=str.substr(posp+SFLAG.size(),posn-(posp+SFLAG.size()));
    }
    re_place(str,RP_SFLAG,SFLAG,0);
    return ans;
}