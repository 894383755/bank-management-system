#pragma once
#include "Client.h"
class ClientSide
{
private:
	Client * client;
	ServerSide *serverSide ;
public:
	ClientSide(ServerSide * toserverSide) ;
	~ClientSide(void) ;
	size_t Menu();//���˵�
	bool Account();//�����˺����벢��ѯ�Ƿ���ȷ
	bool CheckBalance();//��ѯ���
	bool GetMoney();//ȡǮ
	bool SaveMoney();//��Ǯ
};

