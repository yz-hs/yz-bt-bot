#include <iostream>
#include <set>
#include <sstream>
#include <fstream>

#include <cqcppsdk/cqcppsdk.h>

using namespace cq;
using namespace std;
using Message = cq::message::Message;
using MessageSegment = cq::message::MessageSegment;

string helper={
    "帮助—— yz-bt酱（命令以#开头） \
   \n----------------------------- \
   \n群管理系列： \
   \nban @某人 时长 ——禁言 \
   \nwhole_ban ——全体禁言 \
   \nun_whole_ban ——取消全体禁言 \
   \npeo ——获取群友列表 \
   \nset_admin @某人 0/1 ——设置管理员 \
   \nmn @某人 名称 ——改群名片 \
   \n监测上传文件事件（被动）。\
   \n监测入群、离群事件（被动）。\
   \n \
   \n杂项：\
   \nabout ——关于 \
   \nqwq ——卖萌 \
   \nhelp ——帮助 \
   \nrep数字 话 ——完全复读n次\
   \n其他 ——AI复读 \
   \n \
   \n运行代码（dongbei）：\
   \nread 数据 ——保存输入 \
   \nrun 代码 ——运行代码 \
   \nruncode ——运行缓存的代码 \
   \n\
   \n注意： \
   \n(1)支持私聊，AI复读时不用加#号。 \
   \n(2)for命令中，数字是紧贴着for关键字的。\
   \n(3)大部分群管理功能需要权限。"
};

string abouter={
    "关于—— yz-bt酱 \
   \n------------------- \
   \n如今在测试阶段。 \
   \nmade by 可爱的yz-hs。 \
   \nyz-bt酱 v1.0.1 beta"
};

void yreplace( std::string &strBig, const std::string &strsrc, const std::string &strdst)
{
    std::string::size_type pos = 0;
    std::string::size_type srclen = strsrc.size();
    std::string::size_type dstlen = strdst.size();

    while( (pos=strBig.find(strsrc, pos)) != std::string::npos )
    {
        strBig.replace( pos, srclen, strdst );
        pos += dstlen;
    }
}//简单替换

/*std::string UnicodeToANSI(const std::wstring & wstr)
{
    std::string ret;
    std::mbstate_t state = {};
    const wchar_t *src = wstr.data();
    size_t len = std::wcsrtombs(nullptr, &src, 0, &state);
    if (static_cast<size_t>(-1) != len) {
        std::unique_ptr< char [] > buff(new char[len + 1]);
        len = std::wcsrtombs(buff.get(), &src, len, &state);
        if (static_cast<size_t>(-1) != len) {
            ret.assign(buff.get(), len);
        }
    }
    return ret;
}

std::wstring ANSIToUnicode(const std::string & str)
{
    std::wstring ret;
    std::mbstate_t state = {};
    const char *src = str.data();
    size_t len = std::mbsrtowcs(nullptr, &src, 0, &state);
    if (static_cast<size_t>(-1) != len) {
        std::unique_ptr< wchar_t [] > buff(new wchar_t[len + 1]);
        len = std::mbsrtowcs(buff.get(), &src, len, &state);
        if (static_cast<size_t>(-1) != len) {
            ret.assign(buff.get(), len);
        }
    }
    return ret;
}*/

CQ_INIT {
    srand(time(0));
    setlocale(LC_ALL, "chs");
    on_enable([] { logging::info("启用", "插件已启用"); });

    on_private_message([](const PrivateMessageEvent &event) {
        try {
            if(event.message=="#about")//关于
            {
                send_message(event.target, abouter);
            }
            else if(event.message=="#help")
            {
                send_message(event.target, helper);
            }
            else if(event.message=="#qwq")
            {
                string qwq;
                switch (rand()%10)
                {
                    case 0:qwq="qwq";break;
                    case 1:qwq="嘤嘤嘤";break;
                    case 2:qwq="QwQ";break;
                    case 3:qwq="(*≧▽≦)o☆";break;
                    case 4:qwq="ヾ(≧▽≦*)o";break;
                    case 5:qwq="qwq";break;
                    case 6:qwq="/w\\";break;
                    case 7:qwq="yz-bt真可爱！";break;
                    case 8:qwq="pwp";break;
                    case 9:qwq="awa";break;
                    default:qwq="TAT";break;
                }
                send_message(event.target, qwq);
            }
            else
            {
                if(event.message[0]=='#'&&event.message[1]=='r'&&event.message[2]=='e'&&event.message[3]=='p')
                {
                    int num=event.message[4]-'0';
                    num=min(num,20);
                    string tmp=event.message.substr(6,event.message.size());
                    for(int i=1;i<=num;i++)
                    send_message(event.target,tmp);
                }
                else
                {              
                    string tmp=event.message;
                    yreplace(tmp,"我" , "您");
                    yreplace(tmp,"是吗" , "是的");
                    yreplace(tmp,"是吧" , "是的");
                    if(time(0)%2)
                    {
                        yreplace(tmp,"是不是" , "是");
                        yreplace(tmp,"能不能" , "能");
                        yreplace(tmp,"会不会" , "会");
                        yreplace(tmp,"可以不可以" , "可以");
                        yreplace(tmp,"要不要" , "要");
                        yreplace(tmp,"有没有" , "有");
                        yreplace(tmp,"？" , "。");
                        yreplace(tmp,"?" , ".");
                    }
                    else
                    {
                        yreplace(tmp,"是不是" , "不是");
                        yreplace(tmp,"能不能" , "不能");
                        yreplace(tmp,"会不会" , "不会");
                        yreplace(tmp,"可以不可以" , "不可以");
                        yreplace(tmp,"要不要" , "不要");
                        yreplace(tmp,"有没有" , "没有");
                        yreplace(tmp,"？" , "！");
                        yreplace(tmp,"?" , "!");
                    }
                    yreplace(tmp,"吗" , "");
                    yreplace(tmp,"吧" , "");
                    yreplace(tmp,"嘛" , "");
                    yreplace(tmp,"么" , "");
                    yreplace(tmp,"你" , "我");
                    yreplace(tmp,"yz-hs好可爱","是的呢");
                    yreplace(tmp,"好强"," orz");
                    yreplace(tmp,"太强了"," %%%");
                    send_message(event.target, tmp); // 复读
                }
            }
        } catch (ApiError &err) {
            logging::warning("私聊", "私聊消息复读失败, 错误码: " + to_string(err.code));
        }
    });

    on_message([](const MessageEvent &event) {
        logging::debug("消息", "收到消息: " + event.message + "\n实际类型: " + typeid(event).name());
    });

    on_group_message([](const GroupMessageEvent &event) {
        static const set<int64_t> ENABLED_GROUPS = {790890146,788218488,1085366379,817607767,659164017,383575479,1015504552};
        if (ENABLED_GROUPS.count(event.group_id) == 0) return; // 不在启用的群中, 忽略
        try {
            if(event.message=="#about")//关于
            {
                send_message(event.target, abouter);
            }
            else if(event.message=="#help")
            {
                send_message(event.target, helper);
            }
            else if(event.message=="#peo")
            {
                auto mem_list = get_group_member_list(event.group_id); // 获取群成员列表
                string msg;
                for (auto i = 0; i < (static_cast<int>(mem_list.size())); i++) {
                    msg += "昵称: " + mem_list[i].nickname + "\n";
                }
                send_group_message(event.group_id, msg); // 发送群消息
            }
            else if(event.message=="#whole_ban")
            {
                set_group_whole_ban(event.group_id,1);
                send_message(event.target, "全体已被禁言");
            }
            else if(event.message=="#un_whole_ban")
            {
                set_group_whole_ban(event.group_id,0);
                send_message(event.target, "全体已取消禁言");
            }
            else if(event.message=="#runcode")
            {
                system("cd yz-bt-run");
                system("dongbei.py code.txt < read.txt > ans.txt");
                ifstream fin("ans.txt", ios::in);
                istreambuf_iterator<char>beg(fin), end;
                string ans(beg, end);
                fin.close();
                system("cd ..");
                send_message(event.target,"运行结果：");
                send_message(event.target,ans);
            }
            else if(event.message=="#qwq")
            {
                string qwq;
                switch (rand()%10)
                {
                    case 0:qwq="qwq";break;
                    case 1:qwq="嘤嘤嘤";break;
                    case 2:qwq="QwQ";break;
                    case 3:qwq="(*≧▽≦)o☆";break;
                    case 4:qwq="ヾ(≧▽≦*)o";break;
                    case 5:qwq="qwq";break;
                    case 6:qwq="/w\\";break;
                    case 7:qwq="yz-bt真可爱！";break;
                    case 8:qwq="pwp";break;
                    case 9:qwq="awa";break;
                    default:qwq="TAT";break;
                }
                send_message(event.target, qwq);
            }
            else
            {
                if(event.message[0]=='#'&&event.message[1]=='r'&&event.message[2]=='e'&&event.message[3]=='a'&&event.message[4]=='d')
                {
                    system("cd yz-bt-run");
                    ofstream fout("read.txt");
                    string scode=event.message.substr(6,event.message.size());
                    for(auto &c:scode) if(c=='\r') c=0;
                    fout<<scode;
                    fout.close();
                    system("cd ..");
                    send_message(event.target,"输入数据已保存");
                }
                else if(event.message[0]=='#'&&event.message[1]=='r'&&event.message[2]=='u'&&event.message[3]=='n')
                {
                    system("cd yz-bt-run");
                    string tmp,ans;
                    ofstream fout;
                    fout.open("code.txt");
                    string scode=event.message.substr(5,event.message.size());
                    fout<<scode;
                    fout.close();
                    system("dongbei.py code.txt < read.txt > ans.txt");
                    ifstream fin("ans.txt", ios::in);
                    while(fin>>tmp) ans+=tmp,ans+=' ';
                    fin.close();
                    system("cd ..");
                    send_message(event.target,"运行结果：");
                    send_message(event.target,ans);
                }
                else if(event.message[0]=='#'&&event.message[1]=='r'&&event.message[2]=='e'&&event.message[3]=='p')
                {
                    int num=event.message[4]-'0';
                    num=min(num,10);
                    string tmp=event.message.substr(6,event.message.size());
                    for(int i=1;i<=num;i++)
                        send_message(event.target,tmp);
                }
                else if(event.message[0]=='#'&&event.message[1]=='m'&&event.message[2]=='n')
                {
                    string tmp=event.message;
                    int64_t num=0;
                    int i=0,j=0,len=tmp.length();
                    for(;!(tmp[i]>='0'&&tmp[i]<='9');i++);
                    for(;(tmp[i]>='0'&&tmp[i]<='9');i++)
                        num=num*10+(tmp[i]-'0');
                    i++;
                    string tmp2=tmp.substr(i,tmp.length());
                    set_group_card(event.group_id, num, tmp2);
                }
                else if(event.message[0]=='#'&&event.message[1]=='b'&&event.message[2]=='a'&&event.message[3]=='n')
                {
                    string tmp=event.message;
                    int64_t num=0,fortime=0;
                    int i=0;
                    for(;!(tmp[i]>='0'&&tmp[i]<='9');i++);
                    for(;(tmp[i]>='0'&&tmp[i]<='9');i++)
                        num=num*10+(tmp[i]-'0');
                    for(;!(tmp[i]>='0'&&tmp[i]<='9');i++);
                    for(;(tmp[i]>='0'&&tmp[i]<='9');i++)
                        fortime=fortime*10+(tmp[i]-'0');
                    if(num==2378975755)
                    {
                        send_message(event.target, "yz-hs这么可爱，算了吧（");
                    }
                    else
                    {
                        set_group_ban(event.group_id, num, fortime);
                    }
                }
                else if(event.message[0]=='#'&&event.message[1]=='s'&&event.message[2]=='e'&&event.message[3]=='t'&&event.message[4]=='_'&&event.message[5]=='a'&&event.message[6]=='d'&&event.message[7]=='m'&&event.message[8]=='i'&&event.message[9]=='n')
                {
                    string tmp=event.message;
                    int64_t num=0,able=0;
                    int i=0;
                    for(;!(tmp[i]>='0'&&tmp[i]<='9');i++);
                    for(;(tmp[i]>='0'&&tmp[i]<='9');i++)
                        num=num*10+(tmp[i]-'0');
                    for(;!(tmp[i]>='0'&&tmp[i]<='9');i++);
                    for(;(tmp[i]>='0'&&tmp[i]<='9');i++)
                        able=able*10+(tmp[i]-'0');
                    set_group_admin(event.group_id, num, able);
                }
                else
                {
                    string tmp=event.message;
                    yreplace(tmp,"#" , "");
                    yreplace(tmp,"我" , "您");
                    yreplace(tmp,"是吗" , "是的");
                    yreplace(tmp,"是吧" , "是的");
                    if(time(0)%2)
                    {
                        yreplace(tmp,"是不是" , "是");
                        yreplace(tmp,"能不能" , "能");
                        yreplace(tmp,"会不会" , "会");
                        yreplace(tmp,"可以不可以" , "可以");
                        yreplace(tmp,"要不要" , "要");
                        yreplace(tmp,"有没有" , "有");
                        yreplace(tmp,"？" , "。");
                        yreplace(tmp,"?" , ".");
                    }
                    else
                    {
                        yreplace(tmp,"是不是" , "不是");
                        yreplace(tmp,"能不能" , "不能");
                        yreplace(tmp,"会不会" , "不会");
                        yreplace(tmp,"可以不可以" , "不可以");
                        yreplace(tmp,"要不要" , "不要");
                        yreplace(tmp,"有没有" , "没有");
                        yreplace(tmp,"？" , "！");
                        yreplace(tmp,"?" , "!");
                    }
                    yreplace(tmp,"吗" , "");
                    yreplace(tmp,"吧" , "");
                    yreplace(tmp,"嘛" , "");
                    yreplace(tmp,"么" , "");
                    yreplace(tmp,"你" , "我");
                    yreplace(tmp,"stop" , "不可能的");
                    yreplace(tmp,"yz-hs好可爱","是的呢");
                    yreplace(tmp,"好强"," orz");
                    yreplace(tmp,"太强了"," %%%");
                    send_message(event.target, tmp); // 复读
                }
            }
        } catch (ApiError &) { // 忽略发送失败
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
    logging::info("菜单", "点击菜单1");
}

CQ_MENU(menu_demo_2) {
    send_private_message(10000, "测试");
}
