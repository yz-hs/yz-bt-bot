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

//******extern

extern string RUN_HELP;
extern string RUNCODE_HELP;
extern string QWQ_HELP;
extern string BAN_HELP;
extern string HELP_HELP;
extern string ABOUT_HELP;
extern string REPEAT_HELP;
extern string SET_ADMIN_HELP;
extern string WHOLE_BAN_HELP;
extern string PEO_HELP;
extern string NAME_HELP;
extern string REP_HELP;
extern string LIKE_HELP;
extern string NOT_FOUND;
extern string qwqlist[];
extern string HELP;
extern string ABOUT;
extern string PAUSE;
extern string RANDOM_SEND_M;
extern const char mcmdlist[100][100];
extern const int64_t mcmdnum;
extern const char scmdlist[100][100];
extern const int64_t scmdnum;
extern int64_t qwqnum;
extern int RANDOM_SEND_P;
extern int64_t mymin(int64_t a,int64_t b);
extern void rplace(std::string &strBig,const std::string &strsrc,const std::string &strdst);
extern int getstrp(const std::string &str,const std::string &sub);
extern string getmcmd(string str);
extern int64_t getncmd(string str,int fortimes);
extern string getscmd(string str,int fortimes);
extern bool therecmd(string str,string sub);
extern string AIrepeat(string str);
extern set<int64_t> ENABLED_GROUPS;

CQ_INIT {
    srand((int)(time(0)));
    setlocale(LC_ALL, "chs");
    on_enable([] { logging::info("启用", "插件已启用"); });

    on_private_message([](const PrivateMessageEvent &event) {
        try {

            string mcmd=getmcmd(event.message);
            if(mcmd=="$help")
            {
                if(therecmd(event.message,"-help-"))
                    send_message(event.target,HELP_HELP);
                send_message(event.target,HELP);
            }
            else if(mcmd=="$about")
            {
                if(therecmd(event.message,"-help-"))
                    send_message(event.target,ABOUT_HELP);
                send_message(event.target,ABOUT);
            }
            else if(mcmd=="$qwq")
            {
                if(therecmd(event.message,"-help-"))
                    send_message(event.target,QWQ_HELP);
                int qwq=rand()%qwqnum;
                send_message(event.target,qwqlist[qwq]);
            }
            else if(mcmd=="$rep")
            {
                if(therecmd(event.message,"-help-"))
                    send_message(event.target,REP_HELP);
                int64_t fortimes=getncmd(event.message,1);
                string str=event.message,sub[1000];
                int cnt=0,pre=0,pos=getstrp(str,PAUSE);
                while(pos!=-1)
                {
                    sub[++cnt]=str.substr(pre,pos-pre);
                    pre=pos+PAUSE.length();
                    str=str.substr(pre,str.length());
                    pos=getstrp(str,PAUSE);
                }
                sub[++cnt]=str;
                for(int64_t i=1;i<=mymin(10,fortimes);i++)
                    for(int j=1;j<=cnt;j++)
                        send_message(event.target,sub[j]);
            }
            /*else if(mcmd=="$like")
            {
                if(therecmd(event.message,"-help-"))
                    send_message(event.target,LIKE_HELP);
                int64_t QQnum=getncmd(event.message,1);
                int64_t fortimes=getncmd(event.message,2);
                send_like(QQnum,fortimes);
            }*///氪金版
            else
            {
                if(therecmd(event.message,"IOI")&&therecmd(event.message,"AK"))
                {
                    send_message(event.target,"orz！太强了！%%%！");
                }
                else if(therecmd(event.message,"嘤")||therecmd(event.message,"哼")||therecmd(event.message,"[CQ:face,id=187]"))
                {
                    int qwq=rand()%qwqnum;
                    send_message(event.target,qwqlist[qwq]);
                }
                else if(therecmd(event.message,"yz-hs"))
                {
                    send_message(event.target,"谁叫她？叫她干吗？[CQ:face,id=187]");
                }
                else if(therecmd(event.message,"yz-bt"))
                {
                    send_message(event.target,"谁叫我？叫我干吗？[CQ:face,id=187]");
                }
                else
                {
                    if(therecmd(event.message,"-help-"))
                        send_message(event.target,REPEAT_HELP);
                    string str=event.message,sub[1000];
                    int cnt=0,pre=0,pos=getstrp(str,PAUSE);
                    while(pos!=-1)
                    {
                        sub[++cnt]=str.substr(pre,pos-pre);
                        pre=pos+PAUSE.length();
                        str=str.substr(pre,str.length());
                        pos=getstrp(str,PAUSE);
                    }
                    sub[++cnt]=str;
                    for(int i=1;i<=cnt;i++)
                        send_message(event.target,AIrepeat(sub[i]));
                    int tmp=rand()%100+1;
                    if(tmp<=RANDOM_SEND_P)
                        send_message(event.target,RANDOM_SEND_M);
                }
            } 

        } catch (ApiError &err) {
            logging::warning("私聊", "私聊消息处理出现错误, 错误码: " + to_string(err.code));
        }
    });

    on_group_message([](const GroupMessageEvent &event) {
        if (ENABLED_GROUPS.count(event.group_id) == 0) return; // 不在启用的群中, 忽略
        try {

            string mcmd=getmcmd(event.message);
            if(mcmd=="$help")
            {
                if(therecmd(event.message,"-help-"))
                    send_message(event.target,HELP_HELP);
                send_message(event.target,HELP);
            }
            else if(mcmd=="$about")
            {
                if(therecmd(event.message,"-help-"))
                    send_message(event.target,ABOUT_HELP);
                send_message(event.target,ABOUT);
            }
            else if(mcmd=="$peo")
            {
                if(therecmd(event.message,"-help-"))
                    send_message(event.target,PEO_HELP);
                auto mem_list=get_group_member_list(event.group_id);
                string msg;
                for (auto i=0;i<(static_cast<int>(mem_list.size()));i++)
                    msg+="昵称: "+mem_list[i].nickname+"\n";
                send_message(event.target,msg);
            }
            else if(mcmd=="$whole_ban")
            {
                if(therecmd(event.message,"-help-"))
                    send_message(event.target,WHOLE_BAN_HELP);
                int64_t ifit=getncmd(event.message,1);
                set_group_whole_ban(event.group_id,ifit);
            }
            else if(mcmd=="$qwq")
            {
                if(therecmd(event.message,"-help-"))
                    send_message(event.target,QWQ_HELP);
                int qwq=rand()%qwqnum;
                send_message(event.target,qwqlist[qwq]);
            }
            else if(mcmd=="$ban")
            {
                if(therecmd(event.message,"-help-"))
                    send_message(event.target,BAN_HELP);
                int64_t QQnum=getncmd(event.message,1);
                int64_t fortime=getncmd(event.message,2);
                send_message(event.target,"用户"+to_string(QQnum)+"已被禁言"+to_string(fortime)+"秒。");
                set_group_ban(event.group_id,QQnum,fortime);
            }
            else if(mcmd=="$set_admin")
            {
                if(therecmd(event.message,"-help-"))
                    send_message(event.target,SET_ADMIN_HELP);
                int64_t QQnum=getncmd(event.message,1);
                int64_t itis=getncmd(event.message,2);
                send_message(event.target,"用户"+to_string(QQnum)+"已被"+(itis==1?"设为":"取消")+"管理员权限。");
                set_group_admin(event.group_id,QQnum,itis);
            }
            else if(mcmd=="$name")
            {
                if(therecmd(event.message,"-help-"))
                    send_message(event.target,NAME_HELP);
                int64_t QQnum=getncmd(event.message,1);
                string named=getscmd(event.message,1);
                set_group_card(event.group_id,QQnum,named);
            }
            else if(mcmd=="$rep")
            {
                if(therecmd(event.message,"-help-"))
                    send_message(event.target,REP_HELP);
                int64_t fortimes=getncmd(event.message,1);
                string str=event.message,sub[1000];
                int cnt=0,pre=0,pos=getstrp(str,PAUSE);
                while(pos!=-1)
                {
                    sub[++cnt]=str.substr(pre,pos-pre);
                    pre=pos+PAUSE.length();
                    str=str.substr(pre,str.length());
                    pos=getstrp(str,PAUSE);
                }
                sub[++cnt]=str;
                for(int64_t i=1;i<=mymin(10,fortimes);i++)
                    for(int j=1;j<=cnt;j++)
                        send_message(event.target,sub[j]);
            }
            /*else if(mcmd=="$like")
            {
                if(therecmd(event.message,"-help-"))
                    send_message(event.target,LIKE_HELP);
                int64_t QQnum=getncmd(event.message,1);
                int64_t fortimes=getncmd(event.message,2);
                send_like(QQnum,fortimes);
            }*///氪金版
            else
            {
                if(mcmd==NOT_FOUND&&therecmd(event.message,"$"))
                {
                    if(therecmd(event.message,"-help-"))
                        send_message(event.target,REPEAT_HELP);
                    string str=event.message,sub[1000];
                    int cnt=0,pre=0,pos=getstrp(str,PAUSE);
                    while(pos!=-1)
                    {
                        sub[++cnt]=str.substr(pre,pos-pre);
                        pre=pos+PAUSE.length();
                        str=str.substr(pre,str.length());
                        pos=getstrp(str,PAUSE);
                    }
                    sub[++cnt]=str;
                    for(int i=1;i<=cnt;i++)
                        send_message(event.target,AIrepeat(sub[i]));
                }
                else if(therecmd(event.message,"!sleep"))
                {
                    set_group_ban(event.group_id,event.user_id,60*60*8);
                }
                else if(therecmd(event.message,"IOI")&&therecmd(event.message,"AK"))
                {
                    send_message(event.target,"orz！太强了！%%%！");
                }
                else if(therecmd(event.message,"嘤")||therecmd(event.message,"哼")||therecmd(event.message,"[CQ:face,id=187]"))
                {
                    int qwq=rand()%qwqnum;
                    send_message(event.target,qwqlist[qwq]);
                }
                else if(therecmd(event.message,"yz-hs"))
                {
                    send_message(event.target,"谁叫她？叫她干吗？[CQ:face,id=187]");
                }
                else if(therecmd(event.message,"yz-bt"))
                {
                    send_message(event.target,"谁叫我？叫我干吗？[CQ:face,id=187]");
                }
                else
                {
                    int tmp=rand()%100+1;
                    if(tmp<=RANDOM_SEND_P)
                        send_message(event.target,RANDOM_SEND_M);
                }
            } 
            
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
