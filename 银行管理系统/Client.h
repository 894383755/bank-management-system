#pragma once
class Client
{
	unsigned long long int m_passWord;//����
	long long int Balance;//���
public:
	Client(void);
	~Client(void);
	unsigned long long int m_ID;//�˺�
	bool AddMoney();//��Ǯʱ����
	bool SubMoney();//ȡǮʱ����
	bool CheckBalance();//���
	bool CheckPass(unsigned long long int)://��������Ƿ���ȷ
};

