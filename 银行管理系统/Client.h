#pragma once
#include "StdAfx.h"
typedef unsigned long long int ULL;
typedef long long int          LL;
class Client
{
	friend class ServerSide ;
	ULL m_ID;//账号
	ULL m_pass;//密码
	LL  balance;//余额
	Client(ULL ID,ULL pass,LL money = 0);//新建账户
	~Client(void);
public:
	bool CheckID(ULL) const;//检查账号是否正确
	ULL AddMoney(ULL);//存钱时增加
	ULL SubMoney(ULL);//取钱时减少
	ULL  QueryBalance() const;//检查余额
	bool CheckPass(ULL) const;//检查密码是否正确  先要绑定账号
};

