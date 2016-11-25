#pragma once
class Client
{
	unsigned long long int m_ID;//账号
	unsigned long long int m_pass;//密码
	long long int Balance;//余额
	Client(void);
	~Client(void);
public:
	bool CheckID(unsigned long long int);//检查账号是否正确
	bool AddMoney();//存钱时增加
	bool SubMoney();//取钱时减少
	bool CheckBalance();//余额
	bool CheckPass(unsigned long long int);//检查密码是否正确
};

