#pragma once
class ServeSide
{
private:
	Client * clientArr[1000];//客户表
public:
	ServeSide(void);
	~ServeSide(void);
	Client * FindClient(long long int);//查找客户
	bool NewClient();//新建客户
	bool RemoveClient();//删除客户
	bool ChangeClient();//改变客户
};

