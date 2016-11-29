#pragma once
#include <WinSock2.h>
#include <mysql.h>
#include <windows.h>
#pragma comment(lib,"libmysql.lib")
class ServerSide
{
//#define CLIENTMAXNUM 1000
private:
	ServerSide(void);
	~ServerSide(void);
	static MYSQL * mysql;//���ݿ�
	static ServerSide * hasServerSide;//������ֻ��һ��
	//�������ʹ��
	bool FindClient(ULL ID);//���ҿͻ�
	bool NewClient();//�½��ͻ�
	bool RemoveClient();//ɾ���ͻ�
	bool ChangeClient();//�ı�ͻ�
public:
	static ServerSide * RunServerSide();//��ʼ���з����� ֻ������һ��
	static bool LinkDataBase();//�������ݿ�
	//�ͻ�����ʹ��
	bool CheckClient(ULL user,ULL pass);//����˺�����
	LL QueryBalance(ULL ID,ULL pass);//��ѯ
	bool SubMoney(ULL ID,ULL pass,ULL wantGet);//ȡǮ
	bool SaveMoney(ULL ID,ULL pass,ULL wantGet);//��Ǯ
};

