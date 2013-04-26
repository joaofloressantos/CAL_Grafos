#include <cstdio>
#include "Graphviewer.h"
#include "Files.h"


using namespace std;

/**
 * @brief Main program function.
 * Creates or loads a Map, asks for a zone to find a store and returns either the zone if it has a store or the path to the closest zone that has a store. Shows a map with the initial zone and final zone.
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
 	
 	cout << endl << "Insert Zone ID to find nearest store: ";

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

	cout << "Path to store: ";
	vector<int> y = graph.getPath(d, store);

	unsigned int i = 0;
	for(; i < y.size()-1; i++)
	{
		cout << y[i] << "->";
	}
	cout << y[i] << endl;

	int count = 0;
	for (int i = 0; i< vs.size(); i++) {

		gv->addNode(vs[i]->getInfo());
		gv->setVertexLabel(vs[i]->getInfo(),((Zone*)vs[i])->getName());
		if(((Zone*)vs[i])->checkStore() && ((Zone*)vs[i])->getInfo()!= d)
		{
			gv->setVertexColor(vs[i]->getInfo(), "yellow");
		}
		for (int j = 0; j < vs[i]->adj.size();j++) {
			
			gv->addEdge(count, vs[i]->getInfo(), vs[i]->adj[j].dest->getInfo(), EdgeType::DIRECTED); 
			ss.str("");
			ss << vs[i]->adj[j].weight;
			weight = ss.str();
			gv->setEdgeLabel(count, weight);
			for(unsigned int k = 0; k<y.size()-1; k++)
			{
				if((y[k] == vs[i]->getInfo()) && y[k+1] == (vs[i]->adj[j].dest->getInfo()))
				{
					gv->setEdgeColor(count, "red");
				}
			}
			count++;
		}
	}
	gv->setVertexColor(d, "green");
	gv->setVertexColor(store, "red");

	if(d == store)
	{
		gv->setVertexColor(d, "cyan");
	}

	gv->rearrange();
	
	cout << "Closest store is at vertex: " << store << endl;
	saveMap(graph);

	cout << endl << endl << "--------------Vertex Meanings--------------" << endl
		<< "RED: Store location" << endl
		<< "GREEN: Starting zone" << endl
		<< "CYAN: Store location and Starting Zone match" << endl
		<< "BLUE: Zone with no store" << endl
		<< "YELLOW: Zone with store" << endl << endl
		<< endl << endl << "---------------Edge Meanings---------------" <<endl
		<< "BLACK: Regular edge" <<endl
		<< "RED: Path to Store" << endl << endl << endl;
	
	
}


