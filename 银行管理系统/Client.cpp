#include "StdAfx.h"
#include "Client.h"


Client::Client(ULL toID,ULL topass,LL tomoney):m_ID(toID),m_pass(topass),balance(tomoney){

}


Client::~Client(void){

}

bool Client::CheckID(ULL) const{
	return true;
}

ULL Client::AddMoney(ULL addNum){
	return QueryBalance();
}

ULL Client::SubMoney(ULL subNum){
	return QueryBalance();
}

ULL  Client::QueryBalance()const{
	return balance;
}

bool Client::CheckPass(ULL) const{
	return false;
}