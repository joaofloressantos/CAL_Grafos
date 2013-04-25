/*
 * Client.h
 *
 *  Created on: 23 Apr 2013
 *      Author: Jo�o
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <string>
#include <iostream>

using namespace std;

class Client{
	string name;
	unsigned long NIF;
	int zone;

public:

	int storeZone;
	Client(string name, unsigned long NIF);
	string getName();
	unsigned long getNIF();
	int getZone();
	void setZone(int zone);
	void setStoreZone(int zone);
};



#endif /* CLIENT_H_ */
