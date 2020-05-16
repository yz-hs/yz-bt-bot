#pragma once
#include <cqcppsdk/cqcppsdk.h>
#include <string>
using namespace cq;
using namespace std;

void ex_send_message(Target,string,bool);
void cut_message(Target,string);
void EX_SMSG_INIT();