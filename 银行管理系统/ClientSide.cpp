#include "StdAfx.h"
#include "ClientSide.h"


ClientSide::ClientSide(void)
{
}


ClientSide::~ClientSide(void)
{
}

size_t ClientSide::Menu(){

}
bool ClientSide::Account(){
	long long int user, pass;
	while(1){
		printf("请输入账户\n");
		scanf("%I64d",&user);
		printf("请输入密码\n");
		scanf("%I64d",&pass);
		client  = server.findAccount(user);
		if(it->CheckPass(&pass))return true;
		printf("账号或密码错误\n");
	}
	return false
}
bool ClientSide::CheckBalance(){
	if(NULL == client) {print("!!!系统出错!!!\n");return false;}
	printf("你的余额为: %I64d",client ->CheckBalance());
	printf("按任意键返回\n");
	return true;
}
bool ClientSide::GetMoney(){
	if(NULL == client) {print("!!!系统出错!!!\n");return 0;}
	long long int wantGet;
	printf("请输入你想取的整钱数(元)\n");
	while(1){
		scanf("%I64d",wantGet);
		if(0 < wantGet ) {//
			printf("???请输入你想取的整钱数(元)\n");
			continue;
		}
		if(client->CheckBalance() > wantGet){

			continue;
		}
		break;
	}
	client->SubMoney(wantGet);
	print("?????\n");//
	sys("pase");
}
bool ClientSide::SaveMoney(){
	if(NULL == client) {print("!!!系统出错!!!\n");return 0;}

}
