#pragma once
#include "stdafx.h"


class ServerSide
{
#define BUFSIZE 1000
private:
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
public:
	static bool RunServerSide();//��ʼ���з����� ֻ������һ��

	//�ͻ�����ʹ��
	bool CheckClient(ULL user,ULL pass);//����˺�����
	LL QueryBalance(ULL ID,ULL pass);//��ѯ
	bool SubMoney(ULL ID,ULL pass,ULL wantGet);//ȡǮ
	bool SaveMoney(ULL ID,ULL pass,ULL wantGet);//��Ǯ
};

