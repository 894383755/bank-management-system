#include "StdAfx.h"
#include "ServerSide.h"

const int STR_MAX_LEN = 100;
//��̬:
ServerSide * ServerSide::hasServerSide = NULL;
MYSQL * ServerSide::mysql = NULL;
ServerSide * ServerSide::RunServerSide(){
	if(hasServerSide == NULL)
		hasServerSide = new ServerSide;
	if(mysql == NULL)
		LinkDataBase();
	return hasServerSide;
}
//����:
ServerSide::ServerSide(void)
{
}


ServerSide::~ServerSide(void)
{
	delete hasServerSide;
	mysql_close(mysql); 
}

bool ServerSide::FindClient(unsigned long long int ID){
	char str[STR_MAX_LEN];
	sprintf_s(str,"serlect * from client where ID == %llu",ID);
	if( ! mysql_query(mysql,str))
	return true;
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
	char str[STR_MAX_LEN];
	sprintf_s(str,"INsert into client VALUES (%d,123456,%d)",ID,pass);
	int result = mysql_query(mysql,str);
	if(result == 0) printf("�½��˻�ʧ��\n");
	else printf("�½��˻��ɹ�\n");
	printf("����������ز˵�\n");
	system("pause");
	return true;
}

bool ServerSide::RemoveClient(){
	ULL ID;
	printf("������ɾ���ͻ����˺�\n");
	scanf_s("%I64u",&ID);
	while(FindClient(ID) == NULL){
		printf("�˺Ų����ڻ��������\n");
		printf("������ɾ���ͻ����˺�\n");
		scanf_s("%I64u",&ID);
	}
	/* ����sql����          */
	printf("ɾ���˻��ɹ�\n");
	printf("����������ز˵�\n");
	system("pause");
	return true;
}

bool ServerSide::ChangeClient(){//��Ҫ�޸�
	ULL ID,pass;
	LL bablance;
	while(1){
		printf("�������޸Ŀͻ����˺�\n");
		scanf_s("%I64u",&ID);
		if(FindClient(ID))
			break;
	}
	printf("�������޸��˺ŵ�����\n");
	scanf_s("%I64u",&pass);
	//client->m_pass = pass;
	printf("�������޸��˺ŵ����\n");
	scanf_s("%I64d",&bablance);
	//client->balance = bablance;
	printf("�޸��˻��ɹ�\n");
	printf("����������ز˵�\n");
	system("pause");
	return true;
}

bool ServerSide::LinkDataBase(){
	printf("data best is star run :\n");
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
		printf("connect success\n");
	}
	return true;
}

bool ServerSide::CheckClient(ULL user,ULL pass)
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
LL ServerSide::QueryBalance(ULL user,ULL pass){
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