#pragma once
#include "StdAfx.h"
typedef unsigned long long int ULL;
typedef long long int          LL;
class Client
{
	friend class ServerSide ;
	ULL m_ID;//�˺�
	ULL m_pass;//����
	LL  balance;//���
	Client(ULL ID,ULL pass,LL money = 0);//�½��˻�
	~Client(void);
public:
	bool CheckID(ULL) const;//����˺��Ƿ���ȷ
	ULL AddMoney(ULL);//��Ǯʱ����
	ULL SubMoney(ULL);//ȡǮʱ����
	ULL  QueryBalance() const;//������
	bool CheckPass(ULL) const;//��������Ƿ���ȷ  ��Ҫ���˺�
};

