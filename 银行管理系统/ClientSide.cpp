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
	printf("请输入你要的功能:\n");
	printf("0:重新登录:\n");
	printf("1:查询余额:\n");
	printf("2:定额取款:\n");
	printf("3:定额存款\n");
	int select;
	scanf_s("%d",&select);
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
		system("PAUSE");
	}
	return false;
}
bool ClientSide::CheckBalance(){
	system("CLS");
	if(NULL == client) {printf("!!!系统出错!!!\n");system("PAUES");return false;}
	printf("你的余额为: %I64d",client ->QueryBalance());
	system("PAUSE");
	return true;
}
bool ClientSide::GetMoney(){
	system("CLS");
	if(NULL == client) {printf("!!!系统出错!!!\n");return 0;}
	LL wantGet = 0;
	printf("请输入你想取的整钱数(元)\n");
	while(1){
		scanf_s("%lld",wantGet);
		if(0 > wantGet ) {//
			printf("请输入大于0的数\n");
			system("PAUSE");
			continue;
		}
		if(client->QueryBalance() <(ULL) wantGet){
			printf("你的存款不足 请重新输入\n");
			system("PAUSE");
			continue;
		}
		break;
	}
	client->SubMoney(wantGet);
	printf("取款成功\n");//
	system("PAUES");
	return true;
}
bool ClientSide::SaveMoney(){
	if(NULL == client) {printf("!!!系统出错!!!\n");return 0;}
	LL wantSave = 0;
	printf("请输入你想取的整钱数(元)\n");
	while(1){
		scanf_s("%lld",wantSave);
		if(0 > wantSave ) {//
			printf("请输入大于0的数\n");
			system("PAUSE");
			continue;
		}
		break;
	}
	client->SubMoney(wantSave);
	printf("取款成功\n");//
	system("PAUES");
	return true;
}
