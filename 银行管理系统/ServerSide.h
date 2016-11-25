#pragma once
class ServerSide
{
#define CLIENTMAXNUM 1000
private:
	ServerSide(void);
	~ServerSide(void);
	Client * clientArr[CLIENTMAXNUM ];//�ͻ���
	static ServerSide * hasServerSide;//������ֻ��һ��
public:
	static ServerSide * RunServerSide();//��ʼ���з����� ֻ������һ��
	Client * FindClient(unsigned long long int ID);//���ҿͻ�
	bool NewClient();//�½��ͻ�
	bool RemoveClient();//ɾ���ͻ�
	bool ChangeClient();//�ı�ͻ�
};

