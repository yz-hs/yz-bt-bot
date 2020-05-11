#pragma once
#include<string>
using namespace std;

void re_place(string &strBig,const string &strsrc,const string &strdst,bool type);//文本串，被替换串，替换串，类型（1为替换1次，0为全部替换）
int getstrp(const string &str,const string &sub);//返回格式串在文本串中的位置（无则返回-1）
bool ifgetstrp(const string &str,const string &sub);//返回格式串是否在文本串中

int64_t mymin(int64_t,int64_t);
int64_t mymax(int64_t,int64_t);
