// ���й���ϵͳ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
int ClientProgress();
int ServerProgress();
int _tmain(int argc, _TCHAR* argv[])
{
	printf("������������...\n");
	//CreateProcess();
	ServerProgress();
	printf("�ͻ���������...\n");
	//CreateProcess();
	ClientProgress();
	return 0;
}

