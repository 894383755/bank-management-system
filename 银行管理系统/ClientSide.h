#pragma once
class ClientSide
{
private:
	Client * client;
	ClientSide(void) ;
	~ClientSide(void) ;
public:
	size_t Menu();//���˵�
	bool Account();//�����˺����벢��ѯ�Ƿ���ȷ
	bool CheckBalance();//��ѯ���
	bool GetMoney();//ȡǮ
	bool SaveMoney();//��Ǯ
};

