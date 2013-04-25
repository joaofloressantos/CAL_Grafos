#include <cstdio>
#include "graphviewer.h"
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
	int d = 5;
	int op;
	
	/*cout << "Menu" << endl;
	cout << "1 - Load default map" << endl;
	cout << "2 - Load map from file" << endl;
	
	cin << op;
	
	if (op == 1) {*/
		
		graph.setDefault();
	/*}
	else if (op == 2) {*/
		saveMap(graph);	
		graph = loadMap();
	/*}
 	
 	cout << endl << "Insert vertex index to find nearest store: ";
	
	cin << d;
	
	while (d > graph.getVertexSet.size()) {
		cout << endl << "Insert value lower than " << graph.getVertexSet.size()+1 << ": ";
		cin << d;
	}*/
	
	graph.dijkstraShortestPath(d);
 	
 	graph.chooseStore(d);
	
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
			count++;
		}
	}
	gv->setVertexColor(d, "green");
	
	//vector<int> path = graph.getPath(1,4);
	
	cout << vs[d-1]->getInfo() << "|" << ((Zone*)vs[d-1])->clients[0].storeZone << endl;
	
	gv->rearrange();
	
	
 }


