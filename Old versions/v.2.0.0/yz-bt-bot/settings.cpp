/*
用户可以改变此处代码
（巨佬可忽略此句话）
*/
#pragma once
#include <string>
#include <set>
using namespace std;

//*************************************************************************************************************杂项

string qwqlist[]={"qwq","嘤嘤嘤","QwQ","(*≧▽≦)o☆","ヾ(≧▽≦*)o","qwq","/w\\","yz-bt真可爱！","pwp","awa","TAT"};//qwq命令会出现的话
int64_t qwqnum=10;//您有几个qwq

string PAUSE={"-pause-"};//pause分割消息 特殊识别符

int RANDOM_SEND_P=10;//随机发送信息概率 百分比1~100
string RANDOM_SEND_M={"[CQ:face,id=187]"};//随机发送信息的内容

set<int64_t>ENABLED_GROUPS={1093911579,790890146,788218488,1085366379,817607767,659164017,383575479,1015504552};//启用群

bool REPEATMODE=0;//AI复读选项：1为无需复读触发号；0为需复读触发号。
string REPEATFLAG="$";//复读触发号
int REPEAT_P=100;//复读概率 百分比1~100
int REPEAT_FTIME=0;//（非AI复读）当第N条相同的信息时，复读（未开发）

//**********************************************************************************************************帮助
string RUN_HELP={"格式：$run (-read-) yourcode。运行dongbei代码。若有-read-参数则会保存输入。以后会支持更多语言的。"};
string RUNCODE_HELP={"格式：$runcode。运行缓存的代码。"};
string QWQ_HELP={"格式：$qwq。随机卖萌。"};
string BAN_HELP={"格式：$ban (*QQ号码*) (*时长*)。禁言。"};
string HELP_HELP={"格式：$help。获取帮助。"};
string ABOUT_HELP={"格式：$about。获取关于。"};
string REPEAT_HELP={"格式：(包含$的任意话)。真 AI复读。"};
string SET_ADMIN_HELP={"格式：$set_admin (*QQ号码*) (*0或1*)。设置/取消管理员。"};
string WHOLE_BAN_HELP={"格式：$whole_ban (*0或1*)。设置/取消全员禁言。"};
string PEO_HELP={"格式：$peo。获取群友列表。"};
string NAME_HELP={"格式：$name (*QQ号码*) (#字符串#)。更改群名片。"};
string REP_HELP={"格式：$rep (*小于15*) (#话(-pause-)#)。次数完全复读。"};
//string LIKE_HELP={"格式：$rep (*QQ号码*) (*次数*)。发送好友赞。"}; //氪金版

string HELP={
    "帮助—— yz-bt酱（命令以$开头）\
   \n-----------------------------\
   \n命令：\
   \n详情请在命令后加-help-参数。\
   \n 群管理：set_admin ban whole_ban peo name。\
   \n 代码相关：run runcode。\
   \n 杂项：about qwq help rep (包含$的任意话)。\
   \n被动：\
   \n 监测上传文件事件。\
   \n 监测入群、离群事件。\
   \n注意：\
   \n 您输入的命令与参数可任意魔改顺序，甚至添加无关的话。\
   \n 参数约定：由两个特定字符包裹。-表示内置参数，*表示数字参数，#表示字符串参数。\
   \n 更多内容请访问：https://github.com/yz-hs/yz-bt-bot/blob/master/features.md。"
};

string ABOUT={
    "关于——yz-bt酱\
   \n-------------------\
   \nmade by yz-hs.\
   \n赞助者：fqt & sxs。\
   \nyz-hs官网：http://orzyz.tk/。\
   \n项目地址：https://github.com/yz-hs/yz-bt-bot/。\
   \nyz-bt酱 v2.0.0"
};//yz-hs提示您 请不要改变版权信息！

//*******************************************************************************************************************命令
//注掉任意命令即禁用命令

string NOT_FOUND="notfound";//404找不到

string mcmdlist[]={//主命令
    "$run",
    "$runcode",
    "$qwq",
    "$ban",
    "$set_admin",
    "$whole_ban",
    "$peo",
    "$name",
    "$about",
    "$help",
    "$rep"
    //"$like"
};
int64_t mcmdnum=11;

string scmdlist[]={//参数
    "-help-"
};
int64_t scmdnum=1;

char NFLAG='*';//数字参数标识符
string NFLAG_S="*";//兼容，请保持与以上一致
char SFLAG='#';//字符串参数标识符
string SFLAG_S="#";//兼容，请保持与以上一致