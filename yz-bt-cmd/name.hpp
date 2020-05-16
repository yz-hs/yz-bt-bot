#pragma once
#include <cqcppsdk/cqcppsdk.h>
#include <string>
using namespace std;
using namespace cq;

void NAMESETTING();
void NAMEMAIN(const PrivateMessageEvent &event);
void NAMEMAIN(const GroupMessageEvent &event);
string NAMENAME();