#include "Map.h"
#include <sstream>

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

	cout << ss.str();
}


