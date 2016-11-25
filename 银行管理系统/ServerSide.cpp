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
	while(0){
		printf("�����ʽ����\n");
		printf("�������½��ͻ�������\n");
		scanf_s("%I64u",&pass);
	}
	for(int i = 0 ; i < CLIENTMAXNUM ;i++)
		if(clientArr[i] == NULL){
			clientArr[i] = new Client(ID,pass);
		}
	printf("�½��˻��ɹ�\n");
	printf("����������ز˵�\n");
	system("pause");
	return true;
}

bool ServerSide::RemoveClient(){
	printf("ɾ���˻��ɹ�\n");
	printf("����������ز˵�\n");
	system("pause");
	return true;
}

bool ServerSide::ChangeClient(){
	printf("�޸��˻��ɹ�\n");
	printf("����������ز˵�\n");
	system("pause");
	return true;
}