#include "StdAfx.h"
#include "ServerSide.h"
#include <iostream>
const int STR_MAX_LEN = 100;
const int PORT = 60000;
using namespace std;
//静态:
bool ServerSide::isLinkNetWork = false;
ServerSide * ServerSide::hasServerSide = NULL;
MYSQL * ServerSide::mysql = NULL;
bool ServerSide::RunServerSide(){
	if(hasServerSide == NULL)
		hasServerSide = new ServerSide;
	while(mysql == NULL)
		LinkDataBase();
	while(!isLinkNetWork)
		LinkNetWork();
	return true;
}
//构造:
ServerSide::ServerSide(void)
{
}


ServerSide::~ServerSide(void)
{
	delete hasServerSide;
	mysql_close(mysql); 
}

bool ServerSide::FindClient(ULL ID){
	char str[STR_MAX_LEN];
	sprintf_s(str,"serlect * from client where ID == %llu",ID);
	if( ! mysql_query(mysql,str))
		return true;
	else return false;
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
	char str[STR_MAX_LEN];
	sprintf_s(str,"INsert into client VALUES (%d,123456,%d)",ID,pass);
	int result = mysql_query(mysql,str);
	if(result == 0) printf("新建账户失败\n");
	else printf("新建账户成功\n");
	printf("按任意键返回菜单\n");
	system("pause");
	return true;
}

bool ServerSide::RemoveClient(){
	ULL ID;
	printf("请输入删除客户的账号\n");
	scanf_s("%I64u",&ID);
	while(FindClient(ID) == NULL){
		printf("账号不存在或输入错误\n");
		printf("请输入删除客户的账号\n");
		scanf_s("%I64u",&ID);
	}
	/* 插入sql代码          */
	printf("删除账户成功\n");
	printf("按任意键返回菜单\n");
	system("pause");
	return true;
}

bool ServerSide::ChangeClient(){//需要修改
	ULL ID,pass;
	LL bablance;
	while(1){
		printf("请输入修改客户的账号\n");
		scanf_s("%I64u",&ID);
		if(FindClient(ID))
			break;
	}
	printf("请输入修改账号的密码\n");
	scanf_s("%I64u",&pass);
	//client->m_pass = pass;
	printf("请输入修改账号的余额\n");
	scanf_s("%I64d",&bablance);
	//client->balance = bablance;
	printf("修改账户成功\n");
	printf("按任意键返回菜单\n");
	system("pause");
	return true;
}

bool ServerSide::LinkDataBase(){
	mysql = new MYSQL;
	mysql_init(mysql);
	char user[]="root";
	char pass[]="root";
	char host[]="localhost";//"127.0.0.1"
	char name[]="test";
	unsigned int port = 3306;
	if( mysql_real_connect(mysql,host,user,pass,name,port,NULL,0) == NULL){
		printf("!!!error connect :%s\n",mysql_error(mysql));
		mysql_close(mysql); 
		return false;
	}else {
		printf("data best is  success\n");
	}
	return true;
}

bool ServerSide::CheckClient(ULL user,ULL pass,ULL other)
{
	char str[STR_MAX_LEN];
	sprintf_s(str,"select * from client where client.user = %llu and client.pass = %llu",user,pass);
	if (mysql_query(mysql,str)){//
		return false;
	}else {
		MYSQL_RES * sqlRes = mysql_store_result(mysql);
		if (mysql_num_rows(sqlRes) ){
			if(sqlRes)
				mysql_free_result(sqlRes);
			return true;
		}else {
			if(sqlRes)
				mysql_free_result(sqlRes);
			return false;
		}
	}
}
LL ServerSide::QueryBalance(ULL user,ULL pass,ULL other){
	char str[STR_MAX_LEN];
	sprintf_s(str,"select client.money from client where client.user = %llu and client.pass = %llu",user,pass);
	if (mysql_query(mysql,str)){//
		return 0;
	}else {
		MYSQL_RES * sqlRes = mysql_store_result(mysql);
		if (mysql_num_rows(sqlRes)){
			MYSQL_ROW sqlRow = mysql_fetch_row(sqlRes);
			LL money;
			sscanf_s(sqlRow[0],"%lld",&money);
			if(sqlRes)
				mysql_free_result(sqlRes);
			return money;
		}else {
			if(sqlRes)
				mysql_free_result(sqlRes);
			return 0;
		}
	}
}
bool ServerSide::SubMoney(ULL user,ULL pass,ULL wantGet){
	if(QueryBalance(user,pass,wantGet)<(LL)wantGet)
		return false;
	char str[STR_MAX_LEN];
	sprintf_s(str,"UPDATE client SET money = money - %llu WHERE user = %llu and pass = %llu",wantGet,user,pass);
	if ( mysql_query(mysql,str)){
		return false;
	}else {
		return true;
	}
}
bool ServerSide::SaveMoney(ULL user,ULL pass,ULL saveGet){
	char str[STR_MAX_LEN];
	sprintf_s(str,"UPDATE client SET money = money + %llu WHERE user = %llu and pass = %llu",saveGet,user,pass);
	if( mysql_query(mysql,str))
		return false;
	else 
		return true;
}

bool ServerSide::MenuFun(char *fun,ULL user,ULL pass,ULL money)
{

	if(!strcmp(fun,"CheckClient")){
		if(CheckClient(user,pass,money))
			strcpy_s(fun,BUFSIZE,"OK");
		else 
			strcpy_s(fun,BUFSIZE,"NO");
	}else if(!strcmp(fun,"QueryBalance")){
		sprintf(fun,"%lld",QueryBalance(user,pass,money));
	}else if(!strcmp(fun,"SubMoney")){
		if(SubMoney(user,pass,money))
			strcpy_s(fun,BUFSIZE,"OK");
		else 
			strcpy_s(fun,BUFSIZE,"NO");
	}else if(!strcmp(fun,"SaveMoney")){
		if(SaveMoney(user,pass,money))
			strcpy_s(fun,BUFSIZE,"OK");
		else 
			strcpy_s(fun,BUFSIZE,"NO");
	}return false;
	return true;
}

DWORD WINAPI TcpServer(LPARAM  lparam)
{
	cout<<"bulid Thread is OK \n";
	SOCKET socket = (SOCKET) lparam;
	char sendBuf[BUFSIZE],recvBuf[BUFSIZE];
	while(1){
		memset(recvBuf,0,sizeof(recvBuf));
		auto errRecv = recv(socket,recvBuf,sizeof(recvBuf),0);
		if(SOCKET_ERROR == errRecv){
			continue;
		}else if(0 == errRecv){
			cout<<"Thread is end \n\n";
			closesocket(socket);
			return 0;
		}else cout<<"recv : "<<recvBuf<<endl;
		char fun[BUFSIZE];
		ULL  user,pass,money;
		sscanf_s(recvBuf,"%[^:]:%llu,%llu,%llu",fun,&user,&pass,&money);
		ServerSide::hasServerSide->MenuFun(fun,user,pass,money);
		strcpy_s(sendBuf,BUFSIZE,fun);
		if(SOCKET_ERROR == send(socket,sendBuf,sizeof(sendBuf),0)){
			cout<<"send is false \n";
		}else cout<<"send :"<<sendBuf<<endl;
	}
}

bool ServerSide::LinkNetWork(){
	// 初始化网络
	WSADATA wsaData;
	WORD wVersionRequested;
	wVersionRequested = MAKEWORD( 2, 2 );
	if(WSAStartup( wVersionRequested, &wsaData ))
	{
		cout<<"WSAStartup is failed \n";
		return false;
	}
	cout<<"WSAStartup is OK \n";

	SOCKET sockSrv=socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
	addrSrv.sin_family=AF_INET;
	addrSrv.sin_port=htons(PORT);
	if(SOCKET_ERROR == bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR))){
		cout<<"bind is false \n";
	}else cout<<"bind is OK \n";
	if(SOCKET_ERROR == listen(sockSrv,5))
	{
		cout<<"listen is false \n";
	}else cout<<"listen is OK \n";
	SOCKADDR_IN addrClient;
	int len=sizeof(SOCKADDR);
	while(1)
	{
		SOCKET sockConn=accept(sockSrv,(SOCKADDR*)&addrClient,&len);
		if(INVALID_SOCKET == sockConn){
			cout<<"accept is false \n";
		}else cout<<"accept is OK \n";
		isLinkNetWork = true;
		CreateThread(0,0,(LPTHREAD_START_ROUTINE)TcpServer,(LPVOID)sockConn,0,0);
	}
	closesocket(sockSrv);
	cout<<"tcp_server is end\n";
}


