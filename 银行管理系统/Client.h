#pragma once
class Client
{
	friend ServeSide;
	unsigned long long int m_passWord;//密码
	long long int Balance;//余额
	Client(void);
	~Client(void);
public:
	unsigned long long int m_ID;//账号
	bool AddMoney();//存钱时增加
	bool SubMoney();//取钱时减少
	bool CheckBalance();//余额
	bool CheckPass(unsigned long long int);//检查密码是否正确
};

