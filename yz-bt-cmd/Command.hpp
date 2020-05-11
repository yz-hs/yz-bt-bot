#pragma once
#include <string>
#include <set>
using namespace std;

class Command
{
    public:
        string HELP;
        set<int64_t>ENABLED_GROUPS;//启用的人
        set<int64_t>ENABLED_PERSONS;//启用的群
        set<int64_t>BLACK_PERSONS;//人员黑名单
        bool IS_ALLGROUPS;//任何群都可以用（建议关闭）？
        bool IS_ALLPERSONS;//任何人都可以用（推荐关闭）（除了黑名单）？
        //设置群黑名单没必要。
        string NAME;
        string DISABLE;

        void EDIT_HELP(string tmp);//编辑帮助信息
        void ADD_GROUPS(int64_t num);//添加启用群
        void ADD_PERSONS(int64_t num);//添加启用的人
        void SET_IS_ALLSEND(bool a,bool b);//分别对应：任何人都可以用？任何群都可以用？
        void CMD_NAME(string tmp);//命令的名称
        void EDIT_DISABLE(string tmp);//添加禁止使用信息
        void ADD_BPERSONS(int64_t num);//添加人员黑名单
};

int64_t getncmd(string str,int fortimes);
string getscmd(string str,int fortimes);