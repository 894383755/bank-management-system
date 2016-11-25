#pragma once
#include "Client.h"
class ClientSide
{
private:
	Client * client;
	ServerSide *serverSide ;
public:
	ClientSide(ServerSide * toserverSide) ;
	~ClientSide(void) ;
	size_t Menu();//主菜单
	bool Account();//输入账号密码并查询是否正确
	bool CheckBalance();//查询余额
	bool GetMoney();//取钱
	bool SaveMoney();//存钱
};

