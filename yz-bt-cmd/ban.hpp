#pragma once
#include <cqcppsdk/cqcppsdk.h>
#include <string>
using namespace std;
using namespace cq;

void BANSETTING();
void BANMAIN(const PrivateMessageEvent &event);
void BANMAIN(const GroupMessageEvent &event);
string BANNAME();

void WBANSETTING();
void WBANMAIN(const PrivateMessageEvent &event);
void WBANMAIN(const GroupMessageEvent &event);
string WBANNAME();