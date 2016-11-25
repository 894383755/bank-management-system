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
	while(0){
		printf("密码格式错误\n");
		printf("请输入新建客户的密码\n");
		scanf_s("%I64u",&pass);
	}
	for(int i = 0 ; i < CLIENTMAXNUM ;i++)
		if(clientArr[i] == NULL){
			clientArr[i] = new Client(ID,pass);
		}
	printf("新建账户成功\n");
	printf("按任意键返回菜单\n");
	system("pause");
	return true;
}

bool ServerSide::RemoveClient(){
	printf("删除账户成功\n");
	printf("按任意键返回菜单\n");
	system("pause");
	return true;
}

bool ServerSide::ChangeClient(){
	printf("修改账户成功\n");
	printf("按任意键返回菜单\n");
	system("pause");
	return true;
}