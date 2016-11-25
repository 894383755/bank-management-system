#include "StdAfx.h"
#include "ServerSide.h"
//æ≤Ã¨:
static ServerSide * hasServerSide = NULL;
static ServerSide * ServerSide::RunServerSide(){
	if(hasServerSide == NULL)
		hasServerSide = new ServerSide;
	return hasServerSide;
}
//ππ‘Ï:
ServerSide::ServerSide(void)
{
}


ServerSide::~ServerSide(void)
{
}

Client * ServerSide::FindClient(unsigned long long int ID){
	for (int i = 0;i < clientNum; i++){
		if(clientArr[i]->CheckID(ID))
			return clientArr[i];
	}
	return NULL;
}

bool ServerSide::NewClient(){

}

bool ServerSide::RemoveClient(){

}

bool ServerSide:ChangeClient(){

}