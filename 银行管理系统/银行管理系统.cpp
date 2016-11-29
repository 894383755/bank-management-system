// 银行管理系统.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int ClientProgress();
int ServerProgress();
int _tmain(int argc, _TCHAR* argv[])
{
	printf("服务器启动中...\n");
	//CreateProcess();
	ServerProgress();
	printf("客户端启动中...\n");
	//CreateProcess();
	ClientProgress();
	return 0;
}

