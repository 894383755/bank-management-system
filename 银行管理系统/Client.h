#pragma once
class Client
{
	friend ServeSide;
	unsigned long long int m_passWord;//����
	long long int Balance;//���
	Client(void);
	~Client(void);
public:
	unsigned long long int m_ID;//�˺�
	bool AddMoney();//��Ǯʱ����
	bool SubMoney();//ȡǮʱ����
	bool CheckBalance();//���
	bool CheckPass(unsigned long long int);//��������Ƿ���ȷ
};

