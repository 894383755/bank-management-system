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
		printf("�������˻�\n");
		scanf("%I64d",&user);
		printf("����������\n");
		scanf("%I64d",&pass);
		client  = server.findAccount(user);
		if(it->CheckPass(&pass))return true;
		printf("�˺Ż��������\n");
	}
	return false
}
bool ClientSide::CheckBalance(){
	if(NULL == client) {print("!!!ϵͳ����!!!\n");return false;}
	printf("������Ϊ: %I64d",client ->CheckBalance());
	printf("�����������\n");
	return true;
}
bool ClientSide::GetMoney(){
	if(NULL == client) {print("!!!ϵͳ����!!!\n");return 0;}
	long long int wantGet;
	printf("����������ȡ����Ǯ��(Ԫ)\n");
	while(1){
		scanf("%I64d",wantGet);
		if(0 < wantGet ) {//
			printf("???����������ȡ����Ǯ��(Ԫ)\n");
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
	if(NULL == client) {print("!!!ϵͳ����!!!\n");return 0;}

}
