/*
 * Map.cpp
 *
 *  Created on: Apr 23, 2013
 *      Author: wso277
 */
#include "Map.h"

Map::Map() {

	this->addVertex(1, "Porto", true);
	this->addVertex(2, "Lisboa", false);
	this->addVertex(3, "Coimbra", true);
	this->addVertex(4, "Vila Real", true);
	this->addVertex(5, "Portalegre", false);
	this->addVertex(6, "Viseu", false);
	this->addVertex(7, "Braga", false);
	this->addVertex(8, "Viana do Castelo", false);
	this->addVertex(9, "Bragança", false);
	this->addVertex(10, "Leiria", false);
	this->addVertex(11, "Guarda", false);
	this->addVertex(12, "Santarem", false);
	this->addVertex(13, "Setubal", false);
	this->addVertex(14, "Beja", false);
	this->addVertex(15, "Evora", false);
	this->addVertex(16, "Faro", false);
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
}

void Map::createCustomMap() {

}

bool Map::addVertex(const int &in, string name, bool hasStore) {
	vector<Vertex<int>*>::iterator it = vertexSet.begin();
	vector<Vertex<int>*>::iterator ite = vertexSet.end();
	for (; it != ite; it++)
		if ((*it)->getInfo() == in)
			return false;
	Zone *v1 = new Zone(in, name, hasStore);
	vertexSet.push_back(v1);
	return true;
}

void Map::chooseStore() {
	vector<Vertex<int>*>::iterator it = vertexSet.begin();
	vector<Vertex<int>*>::iterator ite = vertexSet.end();

	Zone *v;
	for (; it != ite; it++) {

		v = (Zone*) &it;
		unsigned int i = 0;
		vector<int> path = this->getPath(1, v->info);
		while (i < v->clients.size()) {
			int j = path.size() - 1;
			while (j > -1) {
				if (((Zone*) (this->getVertex(path[j])))->hasStore) {
					v->clients[i].storeZone = path[j];
					break;
				} else {
					j--;
				}
			}
			i++;
		}
	}

}

