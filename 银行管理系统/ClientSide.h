#pragma once
#include "Client.h"
class ClientSide
{
private:
	ServerSide *serverSide ;
	ULL ID,pass;
public:
	ClientSide() ;
	~ClientSide(void) ;
	size_t Menu();//���˵�
	bool Account();//�����˺����벢��ѯ�Ƿ���ȷ
	bool CheckBalance();//��ѯ���
	bool GetMoney();//ȡǮ
	bool SaveMoney();//��Ǯ
	bool CheckLinkServer();//����Ƿ����ӷ�����
};

