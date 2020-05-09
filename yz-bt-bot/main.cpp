#pragma once
#include <sstream>
#include <fstream>
#include <cqcppsdk/cqcppsdk.h>
#include "../yz-bt-cmd/all_include.h"
#include "../yz-bt-tools/all_include.h"

using namespace cq;
using namespace std;
using Message = cq::message::Message;
using MessageSegment = cq::message::MessageSegment;

//debug群号：1093911579

CQ_INIT {
    on_enable([] { logging::info("启用", "插件已启用"); });

    on_private_message([](const PrivateMessageEvent &event) {
        try {

            if(ifgetstrp(event.message,QWQNAME()))
                QWQMAIN(event);

        } catch (ApiError &err) {
            logging::warning("私聊", "私聊消息处理出现错误, 错误码: " + to_string(err.code));
        }
    });

    on_group_message([](const GroupMessageEvent &event) {
        try {
            
            if(ifgetstrp(event.message,QWQNAME()))
                QWQMAIN(event);

        } catch (ApiError &err) {
            logging::warning("群聊", "群聊消息处理出现错误, 错误码: " + to_string(err.code));
        }
        if (event.is_anonymous()) {
            logging::info("群聊", "消息是匿名消息, 匿名昵称: " + event.anonymous.name);
        }
        event.block(); // 阻止当前事件传递到下一个插件
    });

    on_group_member_decrease([](const auto &event) {
        
    });

    on_group_member_increase([](const auto &event) {
        
    });

    on_group_upload([](const auto &event) { // 可以使用 auto 自动推断类型
        
    });
}