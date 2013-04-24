#include "Graph.h"
#include "Client.h"

using namespace std;



class Zone : public Vertex<int> {
	string name;

	vector<Client> clients;
	static int zoneID;
	int ID;
	
public:
	bool hasStore;
	friend class Map;
	Zone(const int &in, string name, bool hasStore);
	void addClient(Client c);
	void removeClient(unsigned long NIF);
	bool checkStore();
	string getName();
	void setStore(bool hasStore);
	int getZoneID();
};

