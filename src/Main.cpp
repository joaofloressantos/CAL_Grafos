#include "Map.h"
#include <sstream>
#include <iostream>

/**
 * Creates a graph
 *
 * @return a graph
 */
using namespace std;

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
	cout << "oh yes its happening THE GAME LOLOLOLOLOLOL" << endl;

	vector<int> path = graph.getPath(4, 11);

		for(unsigned int i = 0; i < path.size(); i++) {
				ss << path[i] << " ";
			}

		cout << ss.str() << endl;

	cout << endl << ((Zone*)graph.getVertex(11))->clients[0].storeZone << endl;

}


