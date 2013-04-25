#include "Map.h"
#include <sstream>
#include <iostream>
#include <fstream>


using namespace std;

void saveMap(Map graph)
{
	ofstream zones;
	ofstream edges;
	ofstream clients;

 	//Saving Zones & Clients
	vector<Vertex<int>* > vs = graph.getVertexSet();

	zones.open ("zones.txt");
	clients.open ("clients.txt");
	edges.open("edges.txt");

	for(unsigned int i = 0; i < vs.size(); i++)
	{	
		Zone* temp = (Zone*)vs[i];
		zones << temp->getID() << "|" << temp->getName() << "|" << temp->checkStore() << endl;
		for(unsigned int j = 0; j < temp->clients.size(); j++)
		{
			clients << temp->clients[j].getName() << "|" << temp->clients[j].getZone() << endl;
		}
		for(unsigned int k = 0; k < temp->adj.size(); k++)
		{
			edges << temp->getID() << "|" << ((Zone*)temp->adj[k].dest)->getID() << "|" << temp->adj[k].weight << endl;
		}
	}

	zones.close();
	clients.close();
	edges.close();
}

/**
 * Creates a graph
 *
 * @return a graph
 */
 int main()
 {
 	Map graph;
 	graph.dijkstraShortestPath(4);
 	vector<Vertex<int>* > vs = graph.getVertexSet();
 	stringstream ss;
 	ss.str("");
 	for(unsigned int i = 0; i < vs.size(); i++) {
 		ss << vs[i]->getInfo() << "<-";
 		if ( vs[i]->path != NULL )  ss << vs[i]->path->getInfo();
 		ss << "|";
 	}

 	((Zone*)graph.getVertex(1))->addClient(Client("Dat client", 1234234234));
 	((Zone*)graph.getVertex(2))->addClient(Client("Dat1 client", 1234234234));
 	((Zone*)graph.getVertex(3))->addClient(Client("Dat2 client", 1234234234));
 	((Zone*)graph.getVertex(4))->addClient(Client("Dat3 client", 1234234234));
 	((Zone*)graph.getVertex(5))->addClient(Client("Da4t client", 1234234234));
 	((Zone*)graph.getVertex(6))->addClient(Client("Dat5 client", 1234234234));
 	((Zone*)graph.getVertex(7))->addClient(Client("Da6t client", 1234234234));
 	((Zone*)graph.getVertex(8))->addClient(Client("Dat7 client", 1234234234));
 	((Zone*)graph.getVertex(9))->addClient(Client("Dat8 client", 1234234234));
 	((Zone*)graph.getVertex(10))->addClient(Client("D1at client", 1234234234));
 	((Zone*)graph.getVertex(11))->addClient(Client("Dat44 client", 1234234234));
 	((Zone*)graph.getVertex(12))->addClient(Client("Dat55 client", 1234234234));
 	((Zone*)graph.getVertex(13))->addClient(Client("Dat99 client", 1234234234));
 	((Zone*)graph.getVertex(14))->addClient(Client("Dat43 client", 1234234234));
 	((Zone*)graph.getVertex(15))->addClient(Client("Dat32 client", 1234234234));
 	((Zone*)graph.getVertex(16))->addClient(Client("Dat688 21client", 1234234234));
 	((Zone*)graph.getVertex(17))->addClient(Client("Dat987 client", 1234234234));
 	((Zone*)graph.getVertex(18))->addClient(Client("Dat123 client", 123423234));
 	graph.chooseStore();

 	saveMap(graph);
 }


