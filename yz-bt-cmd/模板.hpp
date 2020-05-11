//仅作为模板，不作为代码的一部分！
#pragma once
#include <cqcppsdk/cqcppsdk.h>
#include <string>
using namespace std;
using namespace cq;

void _SETTING();
void _MAIN(const PrivateMessageEvent &event);
void _MAIN(const GroupMessageEvent &event);
string _NAME();