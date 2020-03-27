#include<iostream>
#include<cstdio>
#include<string>
#include"getcmd.hpp"

using namespace std;

int getstrp(string str,string sub)//获取一个子串的位置
{
    int slen=str.size();
    int blen=sub.size();
    for(int i=0;i<slen;i++)
        if(str[i]==sub[0])
        {
            bool flag=1;
            for(int j=0;j<blen;j++)
                if(str[i+j]!=sub[j])
                {
                    flag=0;
                    break;
                }
            if(flag)
                return i;
        }
    return -1;
}

string getmcmd(string str)
{
    int slen=str.size();
    string re;
    int pl=-1;
    for(int i=1;i<=mcmdnum;i++)
    {
        int tmp=getstrp(str,mcmdlist[i]);

    }
}

int main()
{
    string a,b;
    cin>>a>>b;
    cout<<getstrp(a,b);
}