#pragma once
#include "stdafx.h"
class ClientSide
{
typedef unsigned long long int ULL ;
typedef long long int          LL ;

private:
	ULL ID;
	ULL pass;
	SOCKET sockClient;
	int isConnectNetWork;
	char *recvMsg;
	char *sendMsg;
public:
	ClientSide() ;
	~ClientSide(void) ;
	size_t Menu();//���˵�
	bool Account();//�����˺����벢��ѯ�Ƿ���ȷ
	LL CheckBalance();//��ѯ���
	bool GetMoney();//ȡǮ
	bool SaveMoney();//��Ǯ
	bool CheckLinkServer();//����Ƿ����ӷ�����
	char *SendMsg(char *);//��������������Ϣ ��������Ϣ
	bool LinkServer();//���ӷ�����
};

