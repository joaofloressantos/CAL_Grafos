/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <stdlib.h> 
#include <list>
#include <string>
#include <limits.h>
#include <cmath>
#include <iostream>
using namespace std;

template<class T> class Edge;
template<class T> class Graph;

const int NOT_VISITED = 0;
const int BEING_VISITED = 1;
const int DONE_VISITED = 2;
const int INT_INFINITY = INT_MAX;

/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */
template<class T>
class Vertex {


	bool visited;

	int indegree;

	int set;
public:
	T info;
	vector<Edge<T> > adj;
	bool processing;
	double dist;
	Vertex(T in);
	friend class Graph<T> ;

	void addEdge(Vertex<T> *dest, double w);
	void addEdge(Vertex<T> *dest, double w, double f);
	bool removeEdgeTo(Vertex<T> *d);

	T getInfo() const;
	void setInfo(T info);

	int getDist() const;
	int getIndegree() const;
	vector<Edge<T> > getAdj() const;
	Vertex<T>* getPath() const;

	bool operator<(const Vertex<T> vertex);

	Vertex* path;

	void updateEdgeFlow(unsigned int index, float f);
};

template<class T>
struct vertex_greater_than {
	bool operator()(Vertex<T> * a, Vertex<T> * b) const {
		return a->getDist() > b->getDist();
	}
};

template<class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
	d->indegree--; //adicionado do exercicio 5
	typename vector<Edge<T> >::iterator it = adj.begin();
	typename vector<Edge<T> >::iterator ite = adj.end();
	while (it != ite) {
		if (it->dest == d) {
			adj.erase(it);
			return true;
		} else
			it++;
	}
	return false;
}

template<class T>
Vertex<T>::Vertex(T in) :
		info(in), visited(false), processing(false), indegree(0), dist(0) {
	path = NULL;
}

template<class T>
void Vertex<T>::addEdge(Vertex<T> *dest, double w) {
	Edge<T> edgeD(dest, w);
	edgeD.orig = this;
	adj.push_back(edgeD);
}

template<class T>
void Vertex<T>::addEdge(Vertex<T> *dest, double w, double f) {
	Edge<T> edgeD(dest, w, f);
	edgeD.orig = this;
	adj.push_back(edgeD);
}

template<class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template<class T>
int Vertex<T>::getDist() const {
	return this->dist;
}

template<class T>
vector<Edge<T> > Vertex<T>::getAdj() const {
	return this->adj;
}

template<class T>
Vertex<T>* Vertex<T>::getPath() const {
	return this->path;
}

template<class T>
void Vertex<T>::setInfo(T info) {
	this->info = info;
}

template<class T>
int Vertex<T>::getIndegree() const {
	return this->indegree;
}

template<class T>
void Vertex<T>::updateEdgeFlow(unsigned int index, float f) {
	if (index >= adj.size())
		return;
	adj[index].flow = f;
}

/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */
template<class T>
class Edge {




public:
	Vertex<T> * dest;
	Vertex<T> * orig;
	double weight;
	double flow;
	Edge(Vertex<T> *d, double w, double f = 0);
	double getFlow() const;
	double getWeight() const;
	Vertex<T> *getDest() const;
	bool operator<(const Edge<T> &other) const;

	friend class Graph<T> ;
	friend class Vertex<T> ;
};

template<class T>
Edge<T>::Edge(Vertex<T> *d, double w, double f) :
		dest(d), weight(w), flow(f) {
}

template<class T>
double Edge<T>::getFlow() const {
	return flow;
}

template<class T>
double Edge<T>::getWeight() const {
	return weight;
}

template<class T>
Vertex<T>* Edge<T>::getDest() const {
	return dest;
}

template<class T>
bool Edge<T>::operator<(const Edge<T> &other) const {
	return this->weight < other.weight;
}

template<class T>
struct edge_greater_than {
	bool operator()(Edge<T> a, Edge<T> b) const {
		return a.getWeight() > b.getWeight();
	}
};

/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */
template<class T>
class Graph {

	void dfs(Vertex<T> *v, vector<T> &res) const;

	//exercicio 5
	int numCycles;
	void dfsVisit(Vertex<T> *v);
	void dfsVisit();
	void getPathTo(Vertex<T> *origin, list<T> &res);

	//exercicio 6
	int ** W;   //weight
	int ** P;   //path

public:
	vector<Vertex<T> *> vertexSet;
	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w, double f = 0);
	bool removeVertex(const T &in);
	bool removeEdge(const T &sourc, const T &dest);
	vector<T> dfs() const;
	vector<T> bfs(Vertex<T> *v) const;
	int maxNewChildren(Vertex<T> *v, T &inf) const;
	vector<Vertex<T> *> getVertexSet() const;
	int getNumVertex() const;

	//exercicio 5
	Vertex<T>* getVertex(const T &v) const;
	void resetIndegrees();
	vector<Vertex<T>*> getSources() const;
	int getNumCycles();
	vector<T> topologicalOrder();
	vector<T> getPath(const T &origin, const T &dest);
	void unweightedShortestPath(const T &v);
	bool isDAG();

	//exercicio 6
	void bellmanFordShortestPath(const T &s);
	void dijkstraShortestPath(const T &s);
	void floydWarshallShortestPath();
	int edgeCost(int vOrigIndex, int vDestIndex);
	vector<T> getfloydWarshallPath(const T &origin, const T &dest);
	void getfloydWarshallPathAux(int index1, int index2, vector<T> & res);

	//exercicio 8
	Graph<T> clone();
	void resetEdgeFlow();
	vector<Vertex<T>*> calculatePrim();
	vector<Vertex<T>*> calculateKruskal();
	//vector<Vertex<T>*> calculateFordFulkerson(T source);
	//float calculateFordFulkerson(Vertex<T>* current, Vertex<T>* parent, float min, Graph<T>* gf, Graph<T>* gr, vector<Vertex<T>*> visited);

};

template<class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {
	return vertexSet;
}

template<class T>
bool Graph<T>::addVertex(const T &in) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	for (; it != ite; it++)
		if ((*it)->info == in)
			return false;
	Vertex<T> *v1 = new Vertex<T>(in);
	vertexSet.push_back(v1);
	return true;
}


template<class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w, double f) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex<T> *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc) {
			vS = *it;
			found++;
		}
		if ((*it)->info == dest) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;
	vD->indegree++;
	vS->addEdge(vD, w, f);

	return true;
}

template<class T>
Vertex<T>* Graph<T>::getVertex(const T &v) const {
	for (unsigned int i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i]->info == v)
			return vertexSet[i];
	return NULL;
}

template<class T>
vector<T> Graph<T>::getPath(const T &origin, const T &dest) {

	list<T> buffer;
	Vertex<T>* v = getVertex(dest);

	buffer.push_front(v->info);
	while (v->path != NULL && v->path->info != origin) {
		v = v->path;
		buffer.push_front(v->info);
	}
	if (v->path != NULL)
		buffer.push_front(v->path->info);

	vector<T> res;
	while (!buffer.empty()) {
		res.push_back(buffer.front());
		buffer.pop_front();
	}
	return res;
}


template<class T>
void Graph<T>::dijkstraShortestPath(const T &s) {

	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
		vertexSet[i]->processing = false;
	}

	Vertex<T>* v = getVertex(s);
	v->dist = 0;

	vector<Vertex<T>*> pq;
	pq.push_back(v);

	make_heap(pq.begin(), pq.end());

	while (!pq.empty()) {

		v = pq.front();
		pop_heap(pq.begin(), pq.end());
		pq.pop_back();

		for (unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<T>* w = v->adj[i].dest;

			if (v->dist + v->adj[i].weight < w->dist) {

				w->dist = v->dist + v->adj[i].weight;
				w->path = v;

				//se j� estiver na lista, apenas a actualiza
				if (!w->processing) {
					w->processing = true;
					pq.push_back(w);
				}

				make_heap(pq.begin(), pq.end(), vertex_greater_than<T>());
			}
		}
	}
}

#endif /* GRAPH_H_ */
