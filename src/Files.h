#ifndef FILES_H_
#define FILES_H_

#include "Map.h"
#include <sstream>
#include <iostream>
#include <fstream>
/**
*@brief Functions for file access
*
*/

/**
*@brief Saves graph components to text file
*@param graph Graph to be saved
*/
void saveMap(Map graph)
{
	ofstream zones;
	ofstream edges;
	ofstream clients;
	vector<Vertex<int>* > vs = graph.getVertexSet();

 	//Saving Zones & Clients & Edges

	zones.open ("zones.txt");
	clients.open ("clients.txt");
	edges.open("edges.txt");

	for(unsigned int i = 0; i < vs.size(); i++)
	{	
		Zone* temp = (Zone*)vs[i];
		zones << temp->getID() << "|" << temp->getName() << "|" << temp->checkStore() << endl;
		for(unsigned int j = 0; j < temp->clients.size(); j++)
		{
			clients << temp->clients[j].getName() << "|" << temp->clients[j].getZone() << "|" << temp->clients[j].getNIF() << endl;
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
*@brief Loads graph components from text file
*@return graph Loaded Graph
*/
Map loadMap()
{
	Map graph;
	ifstream zones;
	ifstream edges;
	ifstream clients;
	string line;
	int ires1, ires2, ires3;
	string sres1, sres2, sres3;

	Zone::resetID();

	//Load Zones
	zones.open ("zones.txt");
	while (zones.good())
	{
		getline (zones,line,'|');
		ires1 = atoi(line.c_str());
		if(ires1 == 0)
		{
			break;
		}
		getline (zones,line,'|');
		sres1 = line;
		getline (zones,line);
		ires2 = atoi(line.c_str());
		graph.addVertex(ires1,sres1,ires2);
	}
	zones.close();

	//Load Edges
	edges.open("edges.txt");
	while (edges.good())
	{
		getline (edges,line,'|');
		ires1 = atoi(line.c_str());
		if(ires1 == 0)
		{
			break;
		}
		getline (edges,line,'|');
		ires2 = atoi(line.c_str());
		getline (edges,line);
		ires3 = atoi(line.c_str());
		graph.addEdge(ires1,ires2,ires3);
	}
	edges.close();

	//Load Clients
	clients.open ("clients.txt");
	while (clients.good())
	{
		getline (clients,line,'|');
		sres1 = line;
		if(sres1 == "")
		{
			break;
		}
		getline (clients,line,'|');
		ires1 = atoi(line.c_str());
		getline (clients,line);
		ires2 = atoi(line.c_str());
		((Zone*)graph.getVertex(ires1))->addClient(Client(sres1, ires2));
	}
	clients.close();
	return graph;
}

#endif /* FILES_H_ */