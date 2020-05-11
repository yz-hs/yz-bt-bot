#pragma once
#include <cqcppsdk/cqcppsdk.h>
#include <string>
using namespace std;
using namespace cq;

void REPSETTING();
void REPMAIN(const PrivateMessageEvent &event);
void REPMAIN(const GroupMessageEvent &event);
string REPNAME();