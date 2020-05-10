#pragma once
#include <string>
#include <set>
using namespace std;

class Command
{
    public:
        string HELP;
        set<int64_t>ENABLED_GROUPS;
        set<int64_t>ENABLED_PERSONS;
        bool IS_ALLGROUPS;
        bool IS_ALLPERSONS;
        string NAME;
        string DISABLE;

        void EDIT_HELP(string tmp);
        void ADD_GROUPS(int64_t num);
        void ADD_PERSONS(int64_t num);
        void SET_IS_ALLSEND(bool a,bool b);
        void CMD_NAME(string tmp);
        void EDIT_DISABLE(string tmp);
};

int64_t getncmd(string str,int fortimes);
string getscmd(string str,int fortimes);