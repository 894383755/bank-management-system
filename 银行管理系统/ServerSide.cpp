#include "StdAfx.h"
#include "ServerSide.h"

//��̬:
ServerSide * ServerSide::hasServerSide = NULL;
ServerSide * ServerSide::RunServerSide(){
	if(hasServerSide == NULL)
		hasServerSide = new ServerSide;
	return hasServerSide;
}
//����:
ServerSide::ServerSide(void)
{
}


ServerSide::~ServerSide(void)
{
	for(int i = 0 ; i < CLIENTMAXNUM ; i++){
		delete clientArr[i];
		clientArr[i] = NULL;
	}
		
}

Client * ServerSide::FindClient(unsigned long long int ID){
	for (int i = 0;i < CLIENTMAXNUM; i++){
		if(clientArr[i]->CheckID(ID))
			return clientArr[i];
	}
	return NULL;
}

bool ServerSide::NewClient(){
	ULL ID,pass;
	printf("�������½��ͻ����˺�\n");
	scanf_s("%I64u",&ID);
	while(FindClient(ID) != NULL){
		printf("�˺��ظ�\n");
		printf("�������½��ͻ����˺�\n");
		scanf_s("%I64u",&ID);
	}
	printf("�������½��˺ŵ�����\n");
	scanf_s("%I64u",&pass);
	for(int i = 0 ; i <= CLIENTMAXNUM ;i++){
		if(i == CLIENTMAXNUM){
			printf("�ͻ��洢����,�޷��½�\n");
			return false;
		}
		if(clientArr[i] == NULL){
			clientArr[i] = new Client(ID,pass);
		}
	}
	printf("�½��˻��ɹ�\n");
	printf("����������ز˵�\n");
	system("pause");
	return true;
}

bool ServerSide::RemoveClient(){
	ULL ID,pass;
	printf("������ɾ���ͻ����˺�\n");
	scanf_s("%I64u",&ID);
	while(FindClient(ID) == NULL){
		printf("�˺Ų����ڻ��������\n");
		printf("������ɾ���ͻ����˺�\n");
		scanf_s("%I64u",&ID);
	}
	for(int i = 0 ; i <= CLIENTMAXNUM ;i++){
		if(i == CLIENTMAXNUM){
			printf("����:�޷��ҵ�\n");
			return false;
		}
		if(clientArr[i]->m_ID == ID){
			clientArr[i] = NULL;
		}
	}
	printf("ɾ���˻��ɹ�\n");
	printf("����������ز˵�\n");
	system("pause");
	return true;
}

bool ServerSide::ChangeClient(){
	ULL ID,pass;
	LL bablance;
	printf("�������޸Ŀͻ����˺�\n");
	scanf_s("%I64u",&ID);
	Client * client = FindClient(ID);
	while(client == NULL){
		system("CLS");
		printf("�˺Ų����ڻ��������\n");
		printf("�������޸Ŀͻ����˺�\n");
		scanf_s("%I64u",&ID);
	}
	printf("�������޸��˺ŵ�����\n");
	scanf_s("%I64u",&pass);
	client->m_pass = pass;
	printf("�������޸��˺ŵ����\n");
	scanf_s("%I64d",&bablance);
	client->balance = bablance;
	printf("�޸��˻��ɹ�\n");
	printf("����������ز˵�\n");
	system("pause");
	return true;
}