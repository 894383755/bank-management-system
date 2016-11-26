#include "StdAfx.h"
#include "ClientSide.h"


ClientSide::ClientSide(ServerSide * toserverSide)
{
	serverSide = toserverSide ;
}


ClientSide::~ClientSide(void)
{
	client = NULL;
	serverSide = NULL;
}

size_t ClientSide::Menu(){
	system("CLS");
	printf("��������Ҫ�Ĺ���:\n");
	printf("0:���µ�¼:\n");
	printf("1:��ѯ���:\n");
	printf("2:����ȡ��:\n");
	printf("3:������\n");
	int select;
	scanf_s("%d",&select);
	switch(select){
	case 0://�˳�(�ص�¼)
		Account();
		break;
	case 1://�����
		CheckBalance();
		break;
	case 2://ȡǮ
		GetMoney();
		break;
	case 3://��Ǯ
		SaveMoney();
		break;
	default :
		printf("������� ����������\n");
		scanf_s("%d",&select);
		break;
	}
	return true;
}
bool ClientSide::Account(){
	ULL user, pass;
	while(1){
		system("CLS");
		printf("�������˻�\n");
		scanf_s("%I64d",&user);
		printf("����������\n");
		scanf_s("%I64d",&pass);
		client  = serverSide->FindClient(user);
		if(client->CheckPass(pass))return true;
		printf("�˺Ż��������\n");
		system("PAUSE");
	}
	return false;
}
bool ClientSide::CheckBalance(){
	system("CLS");
	if(NULL == client) {printf("!!!ϵͳ����!!!\n");system("PAUES");return false;}
	printf("������Ϊ: %I64d",client ->QueryBalance());
	system("PAUSE");
	return true;
}
bool ClientSide::GetMoney(){
	system("CLS");
	if(NULL == client) {printf("!!!ϵͳ����!!!\n");return 0;}
	LL wantGet = 0;
	printf("����������ȡ����Ǯ��(Ԫ)\n");
	while(1){
		scanf_s("%lld",wantGet);
		if(0 > wantGet ) {//
			printf("���������0����\n");
			system("PAUSE");
			continue;
		}
		if(client->QueryBalance() <(ULL) wantGet){
			printf("��Ĵ��� ����������\n");
			system("PAUSE");
			continue;
		}
		break;
	}
	client->SubMoney(wantGet);
	printf("ȡ��ɹ�\n");//
	system("PAUES");
	return true;
}
bool ClientSide::SaveMoney(){
	if(NULL == client) {printf("!!!ϵͳ����!!!\n");return 0;}
	LL wantSave = 0;
	printf("����������ȡ����Ǯ��(Ԫ)\n");
	while(1){
		scanf_s("%lld",wantSave);
		if(0 > wantSave ) {//
			printf("���������0����\n");
			system("PAUSE");
			continue;
		}
		break;
	}
	client->SubMoney(wantSave);
	printf("ȡ��ɹ�\n");//
	system("PAUES");
	return true;
}
