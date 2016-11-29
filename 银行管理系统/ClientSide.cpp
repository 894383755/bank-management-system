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
	printf("请输入你要的功能:\n");
	printf("0:退出登录:\n");
	printf("1:查询余额:\n");
	printf("2:定额取款:\n");
	printf("3:定额存款\n");
	printf("4:重新登录:\n");
	int select;
	scanf_s("%d",&select);
	switch(select){
	case 0://退出
		return 0;
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
	case 4://重登录
		Account();
		break;
	default :
		printf("输入错误 请重新输入\n");
		scanf_s("%d",&select);
		break;
	}
	return 1;
}
bool ClientSide::Account(){
	while(1){
		system("cls");
		printf("请输入账户\n");
		scanf_s("%llu",&ID);
		printf("请输入密码\n");
		scanf_s("%llu",&pass);
		if(serverSide->CheckClient(ID,pass))
			return true;
		printf("\n!!!账号或密码错误!!!\n");
		system("PAUSE");
	}
	return false;
}
bool ClientSide::CheckBalance(){
	system("CLS");
	printf("你的余额为: %lld\n",serverSide ->QueryBalance(ID,pass));
	system("PAUSE");
	return true;
}
bool ClientSide::GetMoney(){
	LL wantGet = 0;
	while(1){
		system("CLS");
		printf("请输入你想取的整钱数(元)\n");
		scanf_s("%lld",&wantGet);
		if(0 > wantGet ) {//
			printf("请输入大于0的数\n");
			system("PAUSE");
			continue;
		}
		if((LL) serverSide ->QueryBalance(ID,pass) < wantGet){
			printf("你的存款不足 请重新输入\n");
			system("PAUSE");
			continue;
		}
		break;
	}
	if(serverSide->SubMoney(ID,pass,wantGet))
		printf("取款成功\n");
	else 
		printf("取款失败\n");
	system("PAUSE");
	getchar();
	return true;
}
bool ClientSide::SaveMoney(){
	LL wantSave = 0;
	while(1){
		system("CLS");
		printf("请输入你想存的整钱数(元)\n");
		scanf_s("%lld",&wantSave);
		if(0 > wantSave ) {//
			printf("请输入大于0的数\n");
			system("PAUSE");
			continue;
		}
		break;
	}
	if(serverSide->SaveMoney(ID,pass,wantSave))
		printf("存款成功\n");
	else 
		printf("存款失败\n");
	system("PAUSE");
	getchar();
	return true;
}
bool  ClientSide::CheckLinkServer(){
	if(serverSide == NULL)
		return false;
	else return true;
}