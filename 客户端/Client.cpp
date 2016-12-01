#include "StdAfx.h"
#include "Client.h"


Client::Client(ULL toID,ULL topass,LL tomoney):m_ID(toID),m_pass(topass),balance(tomoney){

}


Client::~Client(void){

}

bool Client::CheckID(ULL isID) const{

	return isID == m_ID;
}

ULL Client::AddMoney(ULL addNum){

	return balance = balance + addNum;
}

ULL Client::SubMoney(ULL subNum){
	return balance = balance + subNum;
}

ULL  Client::QueryBalance()const{
	return balance;
}

bool Client::CheckPass(ULL isPass) const{
	return isPass == m_pass;
}