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
	this->addEdge(2, 18, 4);
	this->addEdge(2, 17, 3);
	this->addEdge(16, 3, 2);
	this->addEdge(5, 15, 10);
	this->addEdge(6, 12, 2);
	this->addEdge(7, 13, 2);
	this->addEdge(8, 14, 1);
	this->addEdge(8, 11, 1);
	this->addEdge(9, 11, 7);
	this->addEdge(9, 10, 2);
	this->addEdge(10, 9, 2);
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

void Map::dijkstraShortestPath(const int &s) {

	bool found = false;

	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
		vertexSet[i]->processing = false;
	}

	Zone* v = (Zone*) getVertex(s);
	v->dist = 0;

	vector<Vertex<int>*> pq;
	pq.push_back(v);

	make_heap(pq.begin(), pq.end());

	while (!pq.empty()) {

		v = (Zone*) pq.front();
		pop_heap(pq.begin(), pq.end());
		pq.pop_back();

		for (unsigned int i = 0; i < v->adj.size(); i++) {
			Zone* w = (Zone*) (v->adj[i].dest);

			if (v->dist + v->adj[i].weight < w->dist) {

				w->dist = v->dist + v->adj[i].weight;
				w->path = v;

			}

			//se ja estiver na lista, apenas a actualiza
			if (!w->processing) {
				w->processing = true;
				pq.push_back(w);
			}

			make_heap(pq.begin(), pq.end(), vertex_greater_than<int>());
		}
	}
}

