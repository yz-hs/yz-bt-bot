#pragma once
#include <string>
#include "uploadfile.hpp"

using namespace std;

void uplf_MAIN(const GroupUploadEvent &event)
{
    string tmp="用户 "+to_string(event.user_id)+"（[CQ:at,qq="+to_string(event.user_id)+"]）上传了一个文件。\n";
    tmp=tmp+"文件名为："+event.file.name+"，大小（字节）为："+to_string(event.file.size)+"。";
    send_message(event.target,tmp);
}