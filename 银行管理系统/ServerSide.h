#pragma once
class ServerSide
{
#define CLIENTMAXNUM 1000
private:
	ServerSide(void);
	~ServerSide(void);
	Client * clientArr[CLIENTMAXNUM ];//客户表
	static ServerSide * hasServerSide;//服务器只有一个
public:
	static ServerSide * RunServerSide();//开始运行服务器 只能运行一个
	Client * FindClient(unsigned long long int ID);//查找客户
	bool NewClient();//新建客户
	bool RemoveClient();//删除客户
	bool ChangeClient();//改变客户
};

