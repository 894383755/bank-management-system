#pragma once
#include "stdafx.h"


class ServerSide
{
#define BUFSIZE 1000
private:
	friend DWORD WINAPI TcpServer(LPARAM  lparam);
	ServerSide(void);
	~ServerSide(void);
	static bool isLinkNetWork;//����˿�
	static MYSQL * mysql;//���ݿ�
	static ServerSide * hasServerSide;//������ֻ��һ��
	//�������ʹ��
	bool FindClient(ULL ID);//���ҿͻ�
	bool NewClient();//�½��ͻ�
	bool RemoveClient();//ɾ���ͻ�
	bool ChangeClient();//�ı�ͻ�
	static bool LinkDataBase();//�������ݿ�
	static bool LinkNetWork();//��������˿�3
	bool MenuFun(char * fun,ULL user,ULL pass,ULL other);//
public:
	static bool RunServerSide();//��ʼ���з����� ֻ������һ��
	//�ͻ�����ʹ��
	bool CheckClient(ULL user,ULL pass,ULL other);//����˺�����
	LL QueryBalance(ULL ID,ULL pass,ULL other);//��ѯ
	bool SubMoney(ULL ID,ULL pass,ULL wantGet);//ȡǮ
	bool SaveMoney(ULL ID,ULL pass,ULL wantGet);//��Ǯ
	
};

