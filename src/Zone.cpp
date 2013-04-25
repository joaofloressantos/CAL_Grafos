/*
 * Zona.cpp
 *
 *  Created on: Apr 23, 2013
 *      Author: wso277
 */

#include "Zone.h"

using namespace std;

int Zone::zoneID = 1;

Zone::Zone(const int &in, string name, bool hasStore):Vertex<int>(in) {
	this->name = name;
	this->hasStore = hasStore;
	ID = zoneID;
	zoneID++;
}

void Zone::addClient(Client c)
{
	c.setZone(ID);
	clients.push_back(c);
}

void Zone::removeClient(unsigned long NIF)
{
	for (unsigned int i = 0; i < clients.size(); i++)
	{
		if (clients[i].getNIF() == NIF)
			clients.erase(clients.begin() + i);
	}
}

bool Zone::checkStore()
{
	return hasStore;
}

string Zone::getName()
{
	return name;
}

void Zone::setStore(bool hasStore)
{
	this->hasStore = hasStore;
}

int Zone::getID()
{
	return ID;
}



