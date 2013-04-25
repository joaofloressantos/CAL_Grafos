/*
 * Map.cpp
 *
 *  Created on: Apr 23, 2013
 *      Author: wso277
 */
#include "Map.h"

 Map::Map() {
 }

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
 	((Zone*)this->getVertex(1))->addClient(Client("Dat client", 1234234234));
 	((Zone*)this->getVertex(2))->addClient(Client("Dat1 client", 1234234234));
 	((Zone*)this->getVertex(3))->addClient(Client("Dat2 client", 1234234234));
 	((Zone*)this->getVertex(4))->addClient(Client("Dat3 client", 1234234234));
 	((Zone*)this->getVertex(5))->addClient(Client("Da4t client", 1234234234));
 	((Zone*)this->getVertex(6))->addClient(Client("Dat5 client", 1234234234));
 	((Zone*)this->getVertex(7))->addClient(Client("Da6t client", 1234234234));
 	((Zone*)this->getVertex(8))->addClient(Client("Dat7 client", 1234234234));
 	((Zone*)this->getVertex(9))->addClient(Client("Dat8 client", 1234234234));
 	((Zone*)this->getVertex(10))->addClient(Client("D1at client", 1234234234));
 	((Zone*)this->getVertex(11))->addClient(Client("Dat44 client", 1234234234));
 	((Zone*)this->getVertex(12))->addClient(Client("Dat55 client", 1234234234));
 	((Zone*)this->getVertex(13))->addClient(Client("Dat99 client", 1234234234));
 	((Zone*)this->getVertex(14))->addClient(Client("Dat43 client", 1234234234));
 	((Zone*)this->getVertex(15))->addClient(Client("Dat32 client", 1234234234));
 	((Zone*)this->getVertex(16))->addClient(Client("Dat688 21client", 1234234234));
 	((Zone*)this->getVertex(17))->addClient(Client("Dat987 client", 1234234234));
 	((Zone*)this->getVertex(18))->addClient(Client("Dat123 client", 123423234));
 }

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

 void Map::chooseStore(int d) {
 	Zone *v;
 	Zone *v1 = ((Zone*)this->getVertex(d));
 	vector<int> path;
 	long int total_dist=1000000000000000000;
 	long int total_vert=1000000000000000000;
 	for (unsigned int a = 0; a < vertexSet.size(); a++) {

 		v = (Zone*) vertexSet[a];
 		path = getPath(1,v->getInfo());
 		int i=0;
 		while (i<path.size()) {

 			cout << i << endl;
 			if ( (((Zone*)this->getVertex(path[i]))->hasStore) && (this->getVertex(path[i])->dist <= total_dist)) {
		//if ()
 				cout << i << endl;
 				int j=0;
 				while (j < v1->clients.size()) {
 					v1->clients[j].storeZone = path[i];
 					j++;
 				}
 				total_dist =this->getVertex(path[i])->dist;
 			}
 			else {
 				i++;
 				total_vert++;
 				total_dist+=this->getVertex(path[i])->dist;
 			}
 		}

 	}

 }

template<class T>
vector<T> Graph<T>::getfloydWarshallPath(const T &origin, const T &dest) {

	int originIndex = -1, destinationIndex = -1;

	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		if (vertexSet[i]->info == origin)
			originIndex = i;
		if (vertexSet[i]->info == dest)
			destinationIndex = i;

		if (originIndex != -1 && destinationIndex != -1)
			break;
	}

	vector<T> res;

	//se nao foi encontrada solucao possivel, retorna lista vazia
	if (W[originIndex][destinationIndex] == INT_INFINITY)
		return res;

	res.push_back(vertexSet[originIndex]->info);

	//se houver pontos intermedios...
	if (P[originIndex][destinationIndex] != -1) {
		int intermedIndex = P[originIndex][destinationIndex];

		getfloydWarshallPathAux(originIndex, intermedIndex, res);

		res.push_back(vertexSet[intermedIndex]->info);

		getfloydWarshallPathAux(intermedIndex, destinationIndex, res);
	}

	res.push_back(vertexSet[destinationIndex]->info);

	return res;
}