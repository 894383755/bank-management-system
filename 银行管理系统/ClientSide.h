#pragma once
class ClientSide
{
private:
	Client * client;
	ClientSide(void) ;
	~ClientSide(void) ;
public:
	size_t Menu();//主菜单
	bool Account();//输入账号密码并查询是否正确
	bool CheckBalance();//查询余额
	bool GetMoney();//取钱
	bool SaveMoney();//存钱
};

