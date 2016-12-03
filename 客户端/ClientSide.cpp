#include "StdAfx.h"
#include "ClientSide.h"
const int PORT = 60000;
ClientSide::ClientSide():isConnectNetWork (SOCKET_ERROR)
{
	
}


ClientSide::~ClientSide(void)
{
}

bool ClientSide::Menu(){
	system("CLS");
	printf("请输入你要的功能:\n");
	printf("0:退出登录:\n");
	printf("1:查询余额:\n");
	printf("2:定额取款:\n");
	printf("3:定额存款\n");
	int select;
	scanf_s("%d",&select);
	switch(select){
	case 0://退出
		closesocket(sockClient);
		return false;
		break;
	case 1://查余额
		QueryBalance();
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
bool ClientSide::CheckClient(){
	while(1){
		system("cls");
		printf("请输入账户\n");
		scanf_s("%llu",&ID);
		printf("请输入密码\n");
		scanf_s("%llu",&pass);
		sprintf_s(sendMsg,"CheckClient:%llu,%llu,0;",ID,pass);
		send(sockClient,sendMsg,strlen(sendMsg),0);
		recv(sockClient,recvMsg,sizeof(recvMsg),0);
		if(strcmp(recvMsg,"OK") )
			printf("\n!!!账号或密码错误!!!\n");
		else 
			break;
		system("PAUSE");
	}
	return true;
}

LL ClientSide::QueryBalance(){
	system("CLS");
	sprintf_s(sendMsg,"QueryBalance:%llu,%llu,0;",ID,pass);
	send(sockClient,sendMsg,strlen(sendMsg),0);
	recv(sockClient,recvMsg,sizeof(recvMsg),0);
	LL balance ;
	sscanf_s(recvMsg,"%lld",&balance);
	printf("你的余额为: %lld\n",balance);
	system("PAUSE");
	return balance;
}
bool ClientSide::GetMoney(){
	int wantGet = 0;
	while(1){
		system("CLS");
		printf("请输入你想取的整钱数(元)\n");
		scanf_s("%d",&wantGet);
		if(0 > wantGet ) {//
			printf("请输入大于0的数\n");
			system("PAUSE");
			continue;
		}
		if( 0 == wantGet) return true;
		break;
	}
	sprintf_s(sendMsg,"SubMoney:%llu,%llu,%llu;",ID,pass,(ULL)wantGet);
	send(sockClient,sendMsg,strlen(sendMsg),0);
	recv(sockClient,recvMsg,sizeof(recvMsg),0);
	if(!strcmp(recvMsg,"OK"))
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
	sprintf_s(sendMsg,"SaveMoney:%llu,%llu,%llu;",ID,pass,(ULL)wantSave);
	send(sockClient,sendMsg,strlen(sendMsg),0);
	recv(sockClient,recvMsg,sizeof(recvMsg),0);
	if(!strcmp(recvMsg,"OK"))
		printf("存款成功\n");
	else 
		printf("存款失败\n");
	system("PAUSE");
	getchar();
	return true;
}
bool  ClientSide::CheckLinkServer(){
	if(isConnectNetWork != SOCKET_ERROR )
		return true;
	else 
		return false;
}
bool  ClientSide::LinkServer(){
	WSADATA wsaData;
	WORD wVersionRequested;
	wVersionRequested = MAKEWORD( 2, 2 );
	if(WSAStartup( wVersionRequested, &wsaData ))
	{
		//cout<<"WSAStartup is failed \n";
		return false;
	}
	sockClient = socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	addrSrv.sin_family=AF_INET;
	addrSrv.sin_port=htons(PORT);
	isConnectNetWork = connect(sockClient,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	return CheckLinkServer();
}