#pragma once
class Client
{
	unsigned long long int m_ID;//�˺�
	unsigned long long int m_pass;//����
	long long int Balance;//���
	Client(void);
	~Client(void);
public:
	bool CheckID(unsigned long long int);//����˺��Ƿ���ȷ
	bool AddMoney();//��Ǯʱ����
	bool SubMoney();//ȡǮʱ����
	bool CheckBalance();//���
	bool CheckPass(unsigned long long int);//��������Ƿ���ȷ
};

