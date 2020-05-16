#pragma once
#include <cqcppsdk/cqcppsdk.h>
#include <string>
using namespace cq;
using namespace std;

struct Spe_send//关键词回复
{
    string _readm[10];//可能需多个关键词同时满足
    string _writem;//回复内容
    int read_cnt;//关键词数量
};

void SPE_WORK_MAIN(const PrivateMessageEvent &event);
void SPE_WORK_MAIN(const GroupMessageEvent &event);