// ���й���ϵͳ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	printf("������������...\n");
	ServerSide * serverSide = ServerSide::RunServerSide();
	printf("�ͻ���������...\n");
	ClientSide clientSide(serverSide);
	while(clientSide.Account())
		clientSide.Menu();
	return 0;
}

