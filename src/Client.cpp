/*
 * Client.cpp
 *
 *  Created on: 23 Apr 2013
 *      Author: João
 */

#include "Client.h"

Client::Client(string name, unsigned long NIF)
{
	this->name = name;
	this->NIF = NIF;
	zone = -1;
	storeZone = -1;
}

string Client::getName()
{
	return name;
}
unsigned long  Client::getNIF()
{
	return NIF;
}

int Client::getZone()
{
	return zone;
}

void Client::setZone(int zone)
{
	this->zone = zone;
}


void Client::setStoreZone(int zone)
{
	this->storeZone = zone;
}

