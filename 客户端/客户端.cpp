// �ͻ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ClientSide.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ClientSide clientSide;
	while(!clientSide.CheckLinkServer()){
		clientSide.LinkServer();
	}
	if(clientSide.Account())
		while(clientSide.Menu())
			/* �� */;
	return 0;
}

