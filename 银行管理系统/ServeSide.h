#pragma once
class ServeSide
{
private:
	Client * clientArr[1000];//�ͻ���
public:
	ServeSide(void);
	~ServeSide(void);
	Client * FindClient(long long int);//���ҿͻ�
	bool NewClient();//�½��ͻ�
	bool RemoveClient();//ɾ���ͻ�
	bool ChangeClient();//�ı�ͻ�
};

