#include <cstdio>
#include "Graphviewer.h"
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
 	int d = 4;
 	int op;
 	string weight;
 	stringstream ss;
 	cout << "Menu" << endl;
 	cout << "1 - Load default map" << endl;
 	cout << "2 - Load map from file" << endl;

 	cin >> op;

 	if (op == 1) {

 		graph.setDefault();
 	}
 	else if (op == 2) {	
 		graph = loadMap();
 	}
 	
 	cout << endl << "Insert vertex index to find nearest store: ";

 	cin >> d;

 	while ( (d > graph.getVertexSet().size()) || (d<=0)) {
 		cout << endl << "Insert value lower than " << graph.getVertexSet().size()+1 << ": ";
 		cin >> d;
 	}


 	graph.dijkstraShortestPath(d);
 	int store = graph.chooseStore(d);

 	for (int i=0; i < ((Zone*)graph.getVertex(d))->clients.size();i++) {
 		((Zone*)graph.getVertex(d))->clients[i].storeZone = store;
 	}
 	GraphViewer *gv = new GraphViewer(800, 800, true);
 	gv->createWindow(600, 600);
	gv->defineVertexColor("blue"); //define vertex blue
	gv->defineEdgeColor("black"); //define edge black
	
	vector<Vertex<int>* > vs = graph.getVertexSet();
	int count = 0;
	for (int i = 0; i< vs.size(); i++) {

		gv->addNode(vs[i]->getInfo());
		gv->setVertexLabel(vs[i]->getInfo(),((Zone*)vs[i])->getName());
		for (int j = 0; j < vs[i]->adj.size();j++) {
			
			gv->addEdge(count, vs[i]->getInfo(), vs[i]->adj[j].dest->getInfo(), EdgeType::DIRECTED); 
			ss.str("");
			ss << vs[i]->adj[j].weight;
			weight = ss.str();
			gv->setEdgeLabel(count, weight);
			count++;
		}
	}
	gv->setVertexColor(d, "green");
	gv->setVertexColor(store, "red");
	
	cout << "Path to store: ";
	vector<int> y = graph.getPath(d, store);
	unsigned int i = 0;
	for(; i < y.size()-1; i++)
	{
		cout << y[i] << "->";
	}
	cout << y[i] << endl;

	gv->rearrange();
	
	cout << "Closest store is at vertex: " << store << endl;
	saveMap(graph);
	
	
}


