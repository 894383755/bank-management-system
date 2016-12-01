// 客户端.cpp : 定义控制台应用程序的入口点。
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
			/* 空 */;
	return 0;
}

