#include "StdAfx.h"
#include "ServerSide.h"

//静态:
ServerSide * ServerSide::hasServerSide = NULL;
ServerSide * ServerSide::RunServerSide(){
	if(hasServerSide == NULL)
		hasServerSide = new ServerSide;
	return hasServerSide;
}
//构造:
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
	printf("请输入新建客户的账号\n");
	scanf_s("%I64u",&ID);
	while(FindClient(ID) != NULL){
		printf("账号重复\n");
		printf("请输入新建客户的账号\n");
		scanf_s("%I64u",&ID);
	}
	printf("请输入新建账号的密码\n");
	scanf_s("%I64u",&pass);
	for(int i = 0 ; i <= CLIENTMAXNUM ;i++){
		if(i == CLIENTMAXNUM){
			printf("客户存储过多,无法新建\n");
			return false;
		}
		if(clientArr[i] == NULL){
			clientArr[i] = new Client(ID,pass);
		}
	}
	printf("新建账户成功\n");
	printf("按任意键返回菜单\n");
	system("pause");
	return true;
}

bool ServerSide::RemoveClient(){
	ULL ID,pass;
	printf("请输入删除客户的账号\n");
	scanf_s("%I64u",&ID);
	while(FindClient(ID) == NULL){
		printf("账号不存在或输入错误\n");
		printf("请输入删除客户的账号\n");
		scanf_s("%I64u",&ID);
	}
	for(int i = 0 ; i <= CLIENTMAXNUM ;i++){
		if(i == CLIENTMAXNUM){
			printf("错误:无法找到\n");
			return false;
		}
		if(clientArr[i]->m_ID == ID){
			clientArr[i] = NULL;
		}
	}
	printf("删除账户成功\n");
	printf("按任意键返回菜单\n");
	system("pause");
	return true;
}

bool ServerSide::ChangeClient(){
	ULL ID,pass;
	LL bablance;
	printf("请输入修改客户的账号\n");
	scanf_s("%I64u",&ID);
	Client * client = FindClient(ID);
	while(client == NULL){
		system("CLS");
		printf("账号不存在或输入错误\n");
		printf("请输入修改客户的账号\n");
		scanf_s("%I64u",&ID);
	}
	printf("请输入修改账号的密码\n");
	scanf_s("%I64u",&pass);
	client->m_pass = pass;
	printf("请输入修改账号的余额\n");
	scanf_s("%I64d",&bablance);
	client->balance = bablance;
	printf("修改账户成功\n");
	printf("按任意键返回菜单\n");
	system("pause");
	return true;
}