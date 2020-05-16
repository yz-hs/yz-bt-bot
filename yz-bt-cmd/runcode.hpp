#pragma once
#include <cqcppsdk/cqcppsdk.h>
#include <string>
#include <xstring>
using namespace std;
using namespace cq;

void RUNCODESETTING();
void RUNCODEMAIN(const PrivateMessageEvent &event);
void RUNCODEMAIN(const GroupMessageEvent &event);
string RUNCODENAME();