#include "StdAfx.h"
#include "ClientSide.h"

ClientSide::ClientSide()
{
	serverSide = ServerSide::RunServerSide() ;
}


ClientSide::~ClientSide(void)
{
}

size_t ClientSide::Menu(){
	system("CLS");
	printf("��������Ҫ�Ĺ���:\n");
	printf("0:�˳���¼:\n");
	printf("1:��ѯ���:\n");
	printf("2:����ȡ��:\n");
	printf("3:������\n");
	printf("4:���µ�¼:\n");
	int select;
	scanf_s("%d",&select);
	switch(select){
	case 0://�˳�
		return 0;
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
	case 4://�ص�¼
		Account();
		break;
	default :
		printf("������� ����������\n");
		scanf_s("%d",&select);
		break;
	}
	return 1;
}
bool ClientSide::Account(){
	while(1){
		system("cls");
		printf("�������˻�\n");
		scanf_s("%llu",&ID);
		printf("����������\n");
		scanf_s("%llu",&pass);
		if(serverSide->CheckClient(ID,pass))
			return true;
		printf("\n!!!�˺Ż��������!!!\n");
		system("PAUSE");
	}
	return false;
}
bool ClientSide::CheckBalance(){
	system("CLS");
	printf("������Ϊ: %lld\n",serverSide ->QueryBalance(ID,pass));
	system("PAUSE");
	return true;
}
bool ClientSide::GetMoney(){
	LL wantGet = 0;
	while(1){
		system("CLS");
		printf("����������ȡ����Ǯ��(Ԫ)\n");
		scanf_s("%lld",&wantGet);
		if(0 > wantGet ) {//
			printf("���������0����\n");
			system("PAUSE");
			continue;
		}
		if((LL) serverSide ->QueryBalance(ID,pass) < wantGet){
			printf("��Ĵ��� ����������\n");
			system("PAUSE");
			continue;
		}
		break;
	}
	if(serverSide->SubMoney(ID,pass,wantGet))
		printf("ȡ��ɹ�\n");
	else 
		printf("ȡ��ʧ��\n");
	system("PAUSE");
	getchar();
	return true;
}
bool ClientSide::SaveMoney(){
	LL wantSave = 0;
	while(1){
		system("CLS");
		printf("��������������Ǯ��(Ԫ)\n");
		scanf_s("%lld",&wantSave);
		if(0 > wantSave ) {//
			printf("���������0����\n");
			system("PAUSE");
			continue;
		}
		break;
	}
	if(serverSide->SaveMoney(ID,pass,wantSave))
		printf("���ɹ�\n");
	else 
		printf("���ʧ��\n");
	system("PAUSE");
	getchar();
	return true;
}
bool  ClientSide::CheckLinkServer(){
	if(serverSide == NULL)
		return false;
	else return true;
}