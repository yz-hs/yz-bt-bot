#pragma once
#include <cqcppsdk/cqcppsdk.h>
#include <string>
using namespace std;
using namespace cq;

void HELPSETTING();
void HELPMAIN(const PrivateMessageEvent &event);
void HELPMAIN(const GroupMessageEvent &event);
string HELPNAME();