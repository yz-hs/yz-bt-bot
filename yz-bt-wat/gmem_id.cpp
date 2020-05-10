#pragma once
#include <string>
#include "gmem_id.hpp"

using namespace std;

void gmem_d_MAIN(const GroupMemberDecreaseEvent &event)
{
    string tmp="用户"+to_string(event.user_id)+"离开了本群。";
    send_message(event.target,tmp);
}

void gmem_i_MAIN(const GroupMemberIncreaseEvent &event)
{
    string tmp="用户"+to_string(event.user_id)+"（[CQ:at,qq="+to_string(event.user_id)+"]）加入了本群。";
    send_message(event.target,tmp);
}