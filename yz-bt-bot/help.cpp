/*
显示-help-
*/
#pragma once
#include <string>

using namespace std;

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