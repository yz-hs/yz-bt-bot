#pragma once
#include "spe_work.hpp"
#include "../yz-bt-tools/all_include.hpp"
#include "../yz-bt-cmd/Command.hpp"

Command spe_work;//和命令类似

Spe_send spe_send[100];//特殊回复消息对
int spe_send_num=7;//多少特殊回复

void SPE_WORK_SETTING()
{
    spe_work.ADD_GROUPS(1093911579);spe_work.ADD_GROUPS(1085366379);spe_work.ADD_GROUPS(790890146);
    spe_work.ADD_PERSONS(2378975755);
    spe_work.SET_IS_ALLSEND(0,0);

    //************************设置特殊回复：
    spe_send[1].read_cnt=2;
    spe_send[1]._readm[1]="IOI";spe_send[1]._readm[2]="AK";
    spe_send[1]._writem="orz！太强了！%%%！";

    spe_send[2].read_cnt=1;
    spe_send[2]._readm[1]="图灵测试";
    spe_send[2]._writem="图灵测试？那玩意我早通过了！";

    spe_send[3].read_cnt=1;
    spe_send[3]._readm[1]="[CQ:face,id=187]";
    spe_send[3]._writem="qwq";

    spe_send[4].read_cnt=1;
    spe_send[4]._readm[1]="yz-hs";
    spe_send[4]._writem="谁叫她？叫她干嘛？";

    spe_send[5].read_cnt=1;
    spe_send[5]._readm[1]="yz-bt";
    spe_send[5]._writem="谁叫我？叫我干嘛？";

    spe_send[6].read_cnt=1;
    spe_send[6]._readm[1]="bot";
    spe_send[6]._writem="指的是我吗qwq";

    spe_send[7].read_cnt=1;
    spe_send[7]._readm[1]="orz";
    spe_send[7]._writem="orz！太强了！%%%！";
    return;
}

string Ban_Package="!sleep";//禁言套餐
int Ban_Package_time=60*60*8;//时长

string Random_Sendmsg="[CQ:face,id=187]";//随机回复消息
int Random_Sendmsg_P=5;//概率（百分比）

//*************************************************************可以更改以上内容

void SPE_WORK_MAIN(const PrivateMessageEvent &event)
{
    SPE_WORK_SETTING();

    if(spe_work.IS_ALLPERSONS==0&&spe_work.ENABLED_PERSONS.count(event.user_id)==0)
        return;
    if(spe_work.BLACK_PERSONS.count(event.user_id)>=1)
        return;

    srand(time(0));

    for(int i=1;i<=spe_send_num;i++)//特殊回复消息
    {
        bool flag=1;
        for(int j=1;j<=spe_send[i].read_cnt;j++)
            if(!ifgetstrp(event.message,spe_send[i]._readm[j]))
            {
                flag=0;
                break;
            }
        if(flag)
        {
            send_message(event.target,spe_send[i]._writem);
            break;
        }
    }

    if(rand()%100<Random_Sendmsg_P)
        send_message(event.target,Random_Sendmsg);
}

void SPE_WORK_MAIN(const GroupMessageEvent &event)
{
    SPE_WORK_SETTING();
    
    if(spe_work.IS_ALLGROUPS==0&&spe_work.ENABLED_GROUPS.count(event.group_id)==0)
        return;
    if(spe_work.BLACK_PERSONS.count(event.user_id)>=1)
        return;

    srand(time(0));

    for(int i=1;i<=spe_send_num;i++)//特殊回复消息
    {
        bool flag=1;
        for(int j=1;j<=spe_send[i].read_cnt;j++)
            if(!ifgetstrp(event.message,spe_send[i]._readm[j]))
            {
                flag=0;
                break;
            }
        if(flag)
        {
            send_message(event.target,spe_send[i]._writem);
            break;
        }
    }

    if(ifgetstrp(event.message,Ban_Package))
        set_group_ban(event.group_id,event.user_id,Ban_Package_time);

    if(rand()%100<Random_Sendmsg_P)
        send_message(event.target,Random_Sendmsg);
}