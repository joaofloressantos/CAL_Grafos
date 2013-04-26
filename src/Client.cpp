#include "Client.h"

/**
 * @brief Client constructor.
 * Initially it does not have a set sone or store zone so it can be determined later.
 * @param name Client's name
 * @param NIF Client's NIF
 */
Client::Client(string name, unsigned long NIF)
{
	this->name = name;
	this->NIF = NIF;
	zone = -1;
	storeZone = -1;
}

/**
* @brief Gets client name
* @return Client name
*/
string Client::getName()
{
	return name;
}

/**
*@brief Gets client NIF
*@return Client NIF
**/
unsigned long  Client::getNIF()
{
	return NIF;
}

/**
*@brief Gets client zone
*@return Client zone
*/
int Client::getZone()
{
	return zone;
}

/**
*@brief Sets client zone
*@param zone Client zone
*/
void Client::setZone(int zone)
{
	this->zone = zone;
}

/**
*@brief Sets Client's store zone
*@param zone Client's store zone
*/
void Client::setStoreZone(int zone)
{
	this->storeZone = zone;
}

