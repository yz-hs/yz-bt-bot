/*写于2020-03-27*/

#include <iostream>
#include <set>
#include <sstream>
#include <fstream>
//debug群号：1093911579
#include <cqcppsdk/cqcppsdk.h>

using namespace cq;
using namespace std;
using Message = cq::message::Message;
using MessageSegment = cq::message::MessageSegment;

string helper={
    
};

string abouter={
    
};

CQ_INIT {
    srand(time(0));
    setlocale(LC_ALL, "chs");
    on_enable([] { logging::info("启用", "插件已启用"); });

    on_private_message([](const PrivateMessageEvent &event) {
        try {
            
        } catch (ApiError &err) {
            logging::warning("私聊", "私聊消息处理出现错误, 错误码: " + to_string(err.code));
        }
    });

    on_group_message([](const GroupMessageEvent &event) {
        static const set<int64_t> ENABLED_GROUPS = {1093911579};
        if (ENABLED_GROUPS.count(event.group_id) == 0) return; // 不在启用的群中, 忽略
        try {
            
        } catch (ApiError &err) {
            logging::warning("群聊", "群聊消息处理出现错误, 错误码: " + to_string(err.code));
        }
        if (event.is_anonymous()) {
            logging::info("群聊", "消息是匿名消息, 匿名昵称: " + event.anonymous.name);
        }
        event.block(); // 阻止当前事件传递到下一个插件
    });

    on_group_member_decrease([](const auto &event) {
        stringstream ss;
        ss << "群成员" << event.user_id << "已离开本群" ;
        try {
            send_message(event.target, ss.str());
        } catch (ApiError &) {
        }
    });

    on_group_member_increase([](const auto &event) {
        stringstream ss;
        ss << "群成员" << event.user_id << "已进入本群" ;
        try {
            send_message(event.target, ss.str());
        } catch (ApiError &) {
        }
    });

    on_group_upload([](const auto &event) { // 可以使用 auto 自动推断类型
        stringstream ss;
        ss << "您上传了一个文件, 文件名: " << event.file.name << ", 大小(字节): " << event.file.size;
        try {
            send_message(event.target, ss.str());
        } catch (ApiError &) {
        }
    });
}

CQ_MENU(menu_demo_1) {
    
}
