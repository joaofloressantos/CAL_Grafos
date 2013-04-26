/*
 * Map.cpp
 *
 *  Created on: Apr 23, 2013
 *      Author: wso277
 */
#include "Map.h"

/**
*@brief Empty map constructor. Kind of a placeholder
*/
 Map::Map() {
 }

/**
*@brief Sets the Map as the default map, adding zones, edges and clients.
*/
 void Map::setDefault()
 {
 	this->addVertex(1, "Porto", true);
 	this->addVertex(2, "Lisboa", false);
 	this->addVertex(3, "Coimbra", true);
 	this->addVertex(4, "Vila Real", true);
 	this->addVertex(5, "Portalegre", false);
 	this->addVertex(6, "Viseu", true);
 	this->addVertex(7, "Braga", true);
 	this->addVertex(8, "Viana do Castelo", true);
 	this->addVertex(9, "Bragança", true);
 	this->addVertex(10, "Leiria", true);
 	this->addVertex(11, "Guarda", false);
 	this->addVertex(12, "Santarem", true);
 	this->addVertex(13, "Setubal", false);
 	this->addVertex(14, "Beja", true);
 	this->addVertex(15, "Evora", true);
 	this->addVertex(16, "Faro", true);
 	this->addVertex(17, "Aveiro", false);
 	this->addVertex(18, "Castelo Branco", false);

	//One way
 	this->addEdge(1, 2, 2);
 	this->addEdge(2, 3, 7);
 	this->addEdge(3, 4, 3);
 	this->addEdge(4, 5, 5);
 	this->addEdge(1, 5, 2);
 	this->addEdge(5, 6, 3);
 	this->addEdge(6, 7, 2);
 	this->addEdge(7, 8, 2);
 	this->addEdge(8, 9, 2);
 	this->addEdge(9, 10, 2);
 	this->addEdge(10, 11, 2);
 	this->addEdge(11, 12, 33);
 	this->addEdge(12, 13, 11);
 	this->addEdge(13, 14, 5);
 	this->addEdge(14, 15, 3);
 	this->addEdge(15, 16, 5);
 	this->addEdge(16, 17, 8);
 	this->addEdge(17, 18, 32);
 	this->addEdge(18, 1, 12);
 	this->addEdge(18, 2, 1);
 	this->addEdge(2, 17, 3);
 	this->addEdge(16, 3, 2);
 	this->addEdge(5, 15, 10);
 	this->addEdge(6, 12, 2);
 	this->addEdge(7, 13, 2);
 	this->addEdge(8, 14, 1);
 	this->addEdge(8, 11, 1);
 	this->addEdge(9, 11, 7);
 	this->addEdge(10, 9, 2);

	//other way
 	this->addEdge(2, 1, 2);
 	this->addEdge(3, 2, 7);
 	this->addEdge(4, 3, 3);
 	this->addEdge(5, 4, 5);
 	this->addEdge(5, 1, 2);
 	this->addEdge(6, 5, 3);
 	this->addEdge(7, 6, 2);
 	this->addEdge(8, 7, 2);
 	this->addEdge(9, 8, 2);
 	this->addEdge(10, 9, 2);
 	this->addEdge(11, 10, 2);
 	this->addEdge(12, 11, 33);
 	this->addEdge(13, 12, 11);
 	this->addEdge(14, 13, 5);
 	this->addEdge(15, 14, 3);
 	this->addEdge(16, 15, 5);
 	this->addEdge(17, 16, 8);
 	this->addEdge(18, 17, 32);
 	this->addEdge(1, 18, 12);
 	this->addEdge(2, 18, 1);
 	this->addEdge(17, 2, 3);
 	this->addEdge(3, 16, 2);
 	this->addEdge(15, 5, 10);
 	this->addEdge(12, 6, 2);
 	this->addEdge(13, 7, 2);
 	this->addEdge(14, 8, 1);
 	this->addEdge(11, 8, 1);
 	this->addEdge(11, 9, 7);
 	this->addEdge(9, 10, 2);

	//Clients
 	((Zone*)this->getVertex(1))->addClient(Client("Client 1", 1234234234));
 	((Zone*)this->getVertex(2))->addClient(Client("Client 2", 1234234234));
 	((Zone*)this->getVertex(3))->addClient(Client("Client 3", 1234234234));
 	((Zone*)this->getVertex(4))->addClient(Client("Client 4", 1234234234));
 	((Zone*)this->getVertex(5))->addClient(Client("Client 5", 1234234234));
 	((Zone*)this->getVertex(6))->addClient(Client("Client 6", 1234234234));
 	((Zone*)this->getVertex(7))->addClient(Client("Client 7", 1234234234));
 	((Zone*)this->getVertex(8))->addClient(Client("Client 8", 1234234234));
 	((Zone*)this->getVertex(9))->addClient(Client("Client 9", 1234234234));
 	((Zone*)this->getVertex(10))->addClient(Client("Client 10", 1234234234));
 	((Zone*)this->getVertex(11))->addClient(Client("Client 11", 1234234234));
 	((Zone*)this->getVertex(12))->addClient(Client("Client 12", 1234234234));
 	((Zone*)this->getVertex(13))->addClient(Client("Client 13", 1234234234));
 	((Zone*)this->getVertex(14))->addClient(Client("Client 14", 1234234234));
 	((Zone*)this->getVertex(15))->addClient(Client("Client 15", 1234234234));
 	((Zone*)this->getVertex(16))->addClient(Client("Client 16", 1234234234));
 	((Zone*)this->getVertex(17))->addClient(Client("Client 17", 1234234234));
 	((Zone*)this->getVertex(18))->addClient(Client("Client 18", 123423234));
 }

/**
*@brief Adds a new Zone to the map
*@param in Zone ID
*@param name Zone name
*@param hasStore Indicates if the Zone has a store
*@return True if insertion successful. False if not successful.
*/
 bool Map::addVertex(const int &in, string name, bool hasStore) {
 	vector<Vertex<int>*>::iterator it = vertexSet.begin();
 	vector<Vertex<int>*>::iterator ite = vertexSet.end();
 	for (; it != ite; it++)
 	{
 		if ((*it)->getInfo() == in)
 		{
 			return false;
 		}
 	}
 	Zone *v1 = new Zone(in, name, hasStore);
 	vertexSet.push_back(v1);
 	return true;
 }

/**
*@brief Returns closest store to given zone specified by d
*@param d Given zone
*@return Closest zone ID
*/
 int Map::chooseStore(int d) {
	 int vertex=-1;
	 int dist =INT_INFINITY;
	 int pathSize =INT_INFINITY;
	 vector<Vertex<int>*> v1 = this->getVertexSet();
	 
	 for (int i=0; i < v1.size(); i++) {
		 Zone* v = ((Zone*)v1[i]);
		 
		 if(i!=d) {
			
			if ( (v->dist < dist) && v->hasStore) {
				
				dist = v->dist;
				vertex = v->getInfo();
				pathSize = this->getPath(d,i+1).size();
			}
			if ( (v->dist == dist) && v->hasStore) {
			
				if (this->getPath(d,i+1).size() < pathSize ) {
					
					dist = v->dist;
					vertex = v->getInfo();
					pathSize =this->getPath(d,i+1).size();
				}
			}
		 }
		
	 }
	 
	 return vertex;

 }
 
 
 
 
 