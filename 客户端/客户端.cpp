// 客户端.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ClientSide.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ClientSide clientSide;
	if(!clientSide.CheckLinkServer())
		if(!clientSide.LinkServer()){
			printf("!!!Link Server is error\n");
			system("PAUSE");
			return 0;
		}
	if(clientSide.CheckClient())
		while(clientSide.Menu())
			continue;
			/* 空 */;
	return 0;
}

