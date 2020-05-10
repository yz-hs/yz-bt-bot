#pragma once
#include <cqcppsdk/cqcppsdk.h>
#include <string>
using namespace std;
using namespace cq;

void QWQSETTING();
void QWQMAIN(const PrivateMessageEvent &event);
void QWQMAIN(const GroupMessageEvent &event);
string QWQNAME();