#pragma once

#include "stdafx.h"

int  ServerProgress(){
	printf("ServerProgress is run\n");
	
	ServerSide * serverSide = ServerSide::RunServerSide();//获得(创建)服务进程
	//while(1){
	//	ULL isPass;
	//	printf("请输入服务器管理密码");
	//	scanf_s("%d",&isPass);
	//	if(isPass == 123) break;
	//}
	//while(1){
	//	
	//}
	//char query[1000];
	//while(1){
	//	printf("请输入 sql语句修改数据库\n");
	//	scanf_s("%s",query);
	//	int result = mysql_query(serverSide->mysql,query);
	//	if( !result){//
	//		printf("共有%d行被修改\n",mysql_affected_rows(serverSide->mysql));
	//	}else{
	//		printf("!!!error query :%s\n",mysql_error(serverSide->mysql));
	//	}
	//	printf("是否要退出 (Y/N)\n");
	//	char c =getchar();
	//	if('Y' == c || 'y' ==c) break;
	//}
	return 0;
}