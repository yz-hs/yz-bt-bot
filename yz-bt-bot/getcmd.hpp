#include<string>

using namespace std;

const string NOT_FOUND="notfound";

/*
存放所有的主命令
*/

const string mcmdlist[]={
    "run",//运行命令
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
    "-pause-"
    "-read-"
    "-help-"
    "-true-"
    "-false-"
};
const int scmdnum=5;