#pragma once
#include "Client.h"
class ClientSide
{
private:
	ServerSide *serverSide ;
	ULL ID,pass;
public:
	ClientSide() ;
	~ClientSide(void) ;
	size_t Menu();//主菜单
	bool Account();//输入账号密码并查询是否正确
	bool CheckBalance();//查询余额
	bool GetMoney();//取钱
	bool SaveMoney();//存钱
	bool CheckLinkServer();//检查是否连接服务器
};

