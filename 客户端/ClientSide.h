#pragma once
#include "stdafx.h"
class ClientSide
{
typedef unsigned long long int ULL ;
typedef long long int          LL ;
static const int MSG_SIZE = 1000;
private:
	ULL ID;
	ULL pass;
	SOCKET sockClient;
	int isConnectNetWork;
	char recvMsg[MSG_SIZE];
	char sendMsg[MSG_SIZE];
public:
	ClientSide() ;
	~ClientSide(void) ;
	bool Menu();//���˵�
	bool CheckClient();//�����˺����벢��ѯ�Ƿ���ȷ
	LL QueryBalance();//��ѯ���
	bool GetMoney();//ȡǮ
	bool SaveMoney();//��Ǯ
	bool CheckLinkServer();//����Ƿ����ӷ�����
	char *SendMsg(char *);//��������������Ϣ ��������Ϣ
	bool LinkServer();//���ӷ�����
};

