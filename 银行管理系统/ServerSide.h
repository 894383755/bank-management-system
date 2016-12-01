#pragma once
#include "stdafx.h"


class ServerSide
{
#define BUFSIZE 1000
private:
	ServerSide(void);
	~ServerSide(void);
	static bool isLinkNetWork;//网络端口
	static MYSQL * mysql;//数据库
	static ServerSide * hasServerSide;//服务器只有一个
	//服务程序使用
	bool FindClient(ULL ID);//查找客户
	bool NewClient();//新建客户
	bool RemoveClient();//删除客户
	bool ChangeClient();//改变客户
	static bool LinkDataBase();//链接数据库
	static bool LinkNetWork();//链接网络端口3
public:
	static bool RunServerSide();//开始运行服务器 只能运行一个

	//客户程序使用
	bool CheckClient(ULL user,ULL pass);//检查账号密码
	LL QueryBalance(ULL ID,ULL pass);//查询
	bool SubMoney(ULL ID,ULL pass,ULL wantGet);//取钱
	bool SaveMoney(ULL ID,ULL pass,ULL wantGet);//存钱
};

