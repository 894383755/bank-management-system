#pragma once
#include "stdafx.h"
class ClientSide
{
typedef unsigned long long int ULL ;
typedef long long int          LL ;

private:
	ULL ID;
	ULL pass;
	SOCKET sockClient;
	int isConnectNetWork;
	char *recvMsg;
	char *sendMsg;
public:
	ClientSide() ;
	~ClientSide(void) ;
	size_t Menu();//主菜单
	bool Account();//输入账号密码并查询是否正确
	LL CheckBalance();//查询余额
	bool GetMoney();//取钱
	bool SaveMoney();//存钱
	bool CheckLinkServer();//检查是否连接服务器
	char *SendMsg(char *);//给服务器发送消息 并接受消息
	bool LinkServer();//链接服务器
};

