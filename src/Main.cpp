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
	stringstream ss,ss1;
	ss.str("");
	ss1.str("");
	for(unsigned int i = 0; i < vs.size(); i++) {
		ss << vs[i]->getInfo() << "<-";
		if ( vs[i]->path != NULL )  ss << vs[i]->path->getInfo();
		ss << "|";
	}


	vector<int> path = graph.getPath(4, 18);

	for(unsigned int i = 0; i < path.size(); i++) {
			ss << path[i] << " ";
		}

	cout << ss.str() << endl;

}


