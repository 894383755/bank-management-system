#include "stdafx.h"
int ClientProgress(){
	ClientSide clientSide;
	if(! clientSide.CheckLinkServer() ){
		printf("�޷����ӷ�����\n");
		return 0;
	}
	if(clientSide.Account())
	while(clientSide.Menu())
		/* �� */;
	return 0;
}