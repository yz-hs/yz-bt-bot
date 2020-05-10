#pragma once
#include <cqcppsdk/cqcppsdk.h>
#include <string>
using namespace std;
using namespace cq;

void BANSETTING();
void BANMAIN(const PrivateMessageEvent &event);
void BANMAIN(const GroupMessageEvent &event);
string BANNAME();