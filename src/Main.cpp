#include "Files.h"


using namespace std;

/**
 * Creates a graph
 *
 * @return a graph
 */
 int main()
 {
 	Map graph;
 	graph.setDefault();
 	graph.dijkstraShortestPath(4);
 	vector<Vertex<int>* > vs = graph.getVertexSet();
 	stringstream ss;
 	ss.str("");
 	
 	graph.chooseStore();

 	saveMap(graph);
 	graph = loadMap();
 	vs = graph.getVertexSet();
 }


