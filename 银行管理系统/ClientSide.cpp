#include "StdAfx.h"
#include "ClientSide.h"


ClientSide::ClientSide(ServerSide * toserverSide)
{
	serverSide = toserverSide ;
}


ClientSide::~ClientSide(void)
{
}

size_t ClientSide::Menu(){
	system("CLS");
	printf("请输入你要的功能:\n");
	printf("0:重新登录:\n");
	printf("1:查询余额:\n");
	printf("2:定额取款:\n");
	printf("3:定额存款\n");
	int select;
	scanf("%d",&select);
	switch(select){
	case 0://退出(重登录)
		Account();
		break;
	case 1://查余额
		CheckBalance();
		break;
	case 2://取钱
		GetMoney();
		break;
	case 3://存钱
		SaveMoney();
		break;
	default :
		printf("输入错误 请重新输入\n");
		scanf_s("%d",&select);
		break;
	}
	return true;
}
bool ClientSide::Account(){
	ULL user, pass;
	while(1){
		system("CLS");
		printf("请输入账户\n");
		scanf_s("%I64d",&user);
		printf("请输入密码\n");
		scanf_s("%I64d",&pass);
		client  = serverSide->FindClient(user);
		if(client->CheckPass(pass))return true;
		printf("账号或密码错误\n");
	}
	return false;
}
bool ClientSide::CheckBalance(){
	system("CLS");
	if(NULL == client) {printf("!!!系统出错!!!\n");system("PAUES");return false;}
	printf("你的余额为: %I64d",client ->QueryBalance());
	printf("按任意键返回\n");
	return true;
}
bool ClientSide::GetMoney(){
	system("CLS");
	if(NULL == client) {printf("!!!系统出错!!!\n");return 0;}
	ULL wantGet = 0;
	printf("请输入你想取的整钱数(元)\n");
	while(1){
		scanf_s("%llu",wantGet);
		if(0 < wantGet ) {//
			printf("???\n");
			continue;
		}
		if(client->QueryBalance() < wantGet){
			printf("???\n");
			continue;
		}
		break;
	}
	client->SubMoney(wantGet);
	printf("?????\n");//
	system("PAUES");
	return true;
}
bool ClientSide::SaveMoney(){
	if(NULL == client) {printf("!!!系统出错!!!\n");return 0;}
	return true;
}
