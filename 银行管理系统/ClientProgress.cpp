#include "stdafx.h"
int ClientProgress(){
	ClientSide clientSide;
	if(! clientSide.CheckLinkServer() ){
		printf("无法连接服务器\n");
		return 0;
	}
	if(clientSide.Account())
	while(clientSide.Menu())
		/* 空 */;
	return 0;
}