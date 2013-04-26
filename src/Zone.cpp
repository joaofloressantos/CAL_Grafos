/*
 * Zona.cpp
 *
 *  Created on: Apr 23, 2013
 *      Author: wso277
 */

#include "Zone.h"

using namespace std;

/*Guarantees no zone has duplicate id*/
int Zone::zoneID = 1;

/**
*@brief Zone constructor.
*@param in Vertex ID
*@param name Zone name
*@param hasStore Indicates if the Zone has a store
*/
Zone::Zone(const int &in, string name, bool hasStore):Vertex<int>(in) {
	this->name = name;
	this->hasStore = hasStore;
	ID = zoneID;
	zoneID++;
}

/**
*@brief Adds a client to the Zone client vector
*@param c The client
*/
void Zone::addClient(Client c)
{
	c.setZone(ID);
	clients.push_back(c);
}

/**
*@brief Resets ID counter. Used when graph is loaded.
*/
void Zone::resetID()
{
	zoneID = 1;
}

/**
*@brief Checks if the Zone has a store
*@return True if the Zone has a store. False if the zone has no store.
*/
bool Zone::checkStore()
{
	return hasStore;
}

/**
*@brief Checks if the Zone has a store
*@return True if the Zone has a store. False if the zone has no store.
*/
string Zone::getName()
{
	return name;
}

/**
*@brief Sets the store status in a Zone
*@param hasStore Store status.
*/
void Zone::setStore(bool hasStore)
{
	this->hasStore = hasStore;
}

/**
*@brief Checks if the Zone has a store
*@return True if the Zone has a store. False if the zone has no store.
*/
int Zone::getID()
{
	return ID;
}



