// 银行管理系统.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ServerSide.h"
int _tmain(int argc, _TCHAR* argv[])
{
	printf("服务器启动中...\n");
	ServerSide::RunServerSide();//获得(创建)服务器
	printf("服务器正在运行...\n");
	printf("!!!按任意键关闭服务器!!!\n");
	system("PAUSE");
	return 0;
}

