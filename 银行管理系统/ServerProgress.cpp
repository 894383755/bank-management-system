#pragma once

#include "stdafx.h"

int  ServerProgress(){
	printf("ServerProgress is run\n");
	
	ServerSide * serverSide = ServerSide::RunServerSide();//���(����)�������
	//while(1){
	//	ULL isPass;
	//	printf("�������������������");
	//	scanf_s("%d",&isPass);
	//	if(isPass == 123) break;
	//}
	//while(1){
	//	
	//}
	//char query[1000];
	//while(1){
	//	printf("������ sql����޸����ݿ�\n");
	//	scanf_s("%s",query);
	//	int result = mysql_query(serverSide->mysql,query);
	//	if( !result){//
	//		printf("����%d�б��޸�\n",mysql_affected_rows(serverSide->mysql));
	//	}else{
	//		printf("!!!error query :%s\n",mysql_error(serverSide->mysql));
	//	}
	//	printf("�Ƿ�Ҫ�˳� (Y/N)\n");
	//	char c =getchar();
	//	if('Y' == c || 'y' ==c) break;
	//}
	return 0;
}