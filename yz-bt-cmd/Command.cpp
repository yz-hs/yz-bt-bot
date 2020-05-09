#pragma once
#include <cqcppsdk/cqcppsdk.h>
#include "Command.h"
#include "../yz-bt-tools/all_include.h"
using namespace cq;
using namespace std;

void Command::EDIT_HELP(string tmp){HELP=tmp;return;}
void Command::ADD_GROUPS(int64_t num){ENABLED_GROUPS.insert(num);return;}
void Command::ADD_PERSONS(int64_t num){ENABLED_PERSONS.insert(num);return;}
void Command::SET_IS_ALLSEND(bool a,bool b){IS_ALLPERSONS=a;IS_ALLGROUPS=b;return;}
void Command::CMD_NAME(string tmp){NAME=tmp;return;}

string NFLAG="*";
string SFLAG="#";

int64_t getncmd(string str,int fortimes)
{
    int64_t num=0,tal=0,ans=0;
    for(int i=1;i<=fortimes;i++)
    {
        num=0;
        int posp=getstrp(str,NFLAG);
        re_place(str,NFLAG,"",1);
        int posn=getstrp(str,NFLAG);
        for(int j=posp;j<=posn;j++)
            num=num*10+str[j]-'0';
        ans=num;
    }
    return ans;
}

string getscmd(string str,int fortimes)
{
    int64_t tal=0;
    string ans;
    for(int i=1;i<=fortimes;i++)
    {
        int posp=getstrp(str,SFLAG);
        re_place(str,SFLAG,"",1);
        int posn=getstrp(str,SFLAG);
        ans=str.substr(posp,posn-posp+1);
    }
    return ans;
}