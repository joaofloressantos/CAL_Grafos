

#ifndef CLIENT_H_
#define CLIENT_H_

#include <string>
#include <iostream>

using namespace std;

/**
 *@brief  Represests a client in the graph. Stores name, NIF, zone and store zone.
 */
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
