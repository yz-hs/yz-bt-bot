#include<string>

using namespace std;

const string NOT_FOUND="notfound";

/*
存放所有的主命令
*/

const string mcmdlist[]={
    "run",
    "runcode",
    "qwq",
    "ban",
    "set_admin"
};
const int mcmdnum=5;

/*
存放所有的参数
*/

const string scmdlist[]={
    "-pause-",/*shit昨天忘记加逗号','导致bug一堆 —— 2020-03-28*/
    "-read-",
    "-help-",
    "-true-",
    "-false-"
};
const int scmdnum=5;