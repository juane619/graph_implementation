#include <queue>
#include "grafo.h"
using namespace std;

//CLASS GRAPH

/* adds a new vertex to graph */
void Graph::addVertex(int name) {
    vmap::iterator itr = work.find(name);
    if (itr == work.end()) {
	Vertex *v = new Vertex(name);
	work[name] = v;
	numv++;
	return;
    }
    cout << "\nVertex already exists!";
}

/* adds a new edge to the graph.
   if the graph is directed, then the edge is added in both list of vertices'
   else only in one of them. 
 If adds other edge to a vertex that already exist, compare cost
 * and update this if is less.
 */
void Graph::addEdge(int from, int to, int cost) {
    vmap::iterator itr;
    Vertex *f = ((itr = work.find(from))->second); // finds Vertex* from name of vertex
    if (itr == work.end()) {
	cout << "\n Vertex '" << from << "' doesn't exist!";
	return;
    }
    Vertex *t = ((itr = work.find(to))->second); // finds Vertex* from name of vertex
    if (itr == work.end()) {
	cout << "\n Vertex '" << to << "' doesn't exist!";
	return;
    }
    if (areAdjacent(from, to) && cost < getWeight(from, to)) {
	setWight(from, to, cost);
	if (directed == false) { // checks if graph is directed.
	    setWight(to, from, cost);
	}
    } else {
	pair<int, Vertex*> edge = make_pair(cost, t); //make and add edge to adjacency list.
	f->insertAdj(edge);

	if (directed == false) { // checks if graph is directed.
	    edge = make_pair(cost, f); // if it is not then edge is added to both adjacency list.
	    t->insertAdj(edge);
	}
    }
}

/*True is are adjacent vertex1 and vertex2, assuming the vertexes exist*/
bool Graph::areAdjacent(int v1p, int v2p) const {
    auto it = work.find(v1p);

    Vertex *v1 = it->second; // finds Vertex* from name of vertex

    return v1->isAdjacent(v2p);
}

/*Weight between v1 and v2
 return INF if arent connected*/
int Graph::getWeight(int v1p, int v2p) const {
    auto it = work.find(v1p);

    Vertex *v1 = it->second; // finds Vertex* from name of vertex

    return v1->getWeight(v2p);
}

/*Change weight between v1 and v2*/
void Graph::setWight(int v1p, int v2p, int w) {
    auto it = work.find(v1p);

    Vertex *v1 = it->second; // finds Vertex* from name of vertex

    v1->setWeight(v2p, w);
}

/*Clear the graph*/
void Graph::clear() {
    work.clear();
    numv = 0;
}

/*print the neighboors of all vertex*/
void Graph::print() const {
    cout << "\nN nodos: " << numv << endl;
    for (auto it = work.begin(); it != work.end(); it++) {
	cout << "Nodo " << it->first << " -> ";
	it->second->printNeighbours();
    }
}


//Classic algorithm in graphs

/* Dijkstra's algo
   returns the shortest distance (vector) to all other vertices 
   from the start vertex. */
vector<int> Graph::Dijkstra(int start) {
    vector<int> weights;

    for (unsigned int i = 0; i <= numv; ++i) {
	weights.push_back(INF);
    }

    priority_queue<pair<int, Vertex*>, vector<pair<int, Vertex *> >, CompareLess > Q;

    weights[start] = 0;

    Q.push(make_pair(0, work[start]));
    pair<int, Vertex *> currentNode;
    while (!Q.empty()) {
	currentNode = Q.top();
	Q.pop();
	if (currentNode.first <= weights[(currentNode.second)->getName()]) {
	    for (pair<int, Vertex *> v : (currentNode.second)->getAdj()) {
		if (weights[(v.second)->getName()] > weights[(currentNode.second)->getName()] + v.first) {
		    weights[(v.second)->getName()] = weights[(currentNode.second)->getName()] + v.first;
		    Q.push(make_pair(weights[(v.second)->getName()], v.second));
		}
	    }
	}
    }

    return weights;
}


/*FUTURE*/

/* Breadth First Search*/
void Graph::BFS(int s) {
}

/* Kruskal's algo (Arbol generador minimo). */
void Graph::Kruskal() {
}

/* Prim's algo (Arbol generador minimo). */
void Graph::Prim(int root) {
}
/*END FUTURE*/
//END Classic algorithm in graphs


//END CLASS GRAPH


//CLASS VERTEX

/* print all neighbours of a vertex */
void Vertex::printNeighbours() {
    vector<pair<int, Vertex *> >::iterator i;
    for (i = adj.begin(); i != adj.end(); ++i) {
	cout << "(" << i->second->name << ", " << i->first << "), ";
    }
    cout << endl;
}

/*Return the weight with its namep edge joined*/
int Vertex::getWeight(int namep) {
    for (int i = 0; i < adj.size(); i++) {
	if (adj[i].second->name == namep)
	    return adj[i].first;
    }

    return INF;
}

/*Set the weight with its namep edge joined to wp*/
void Vertex::setWeight(int namep, int wp) {
    for (int i = 0; i < adj.size(); i++) {
	if (adj[i].second->name == namep)
	    adj[i].first = wp;
    }
}

/*Return if is adjacent with node namep*/
bool Vertex::isAdjacent(int namep) {
    for (int i = 0; i < adj.size(); i++) {
	if (adj[i].second->name == namep)
	    return true;
    }
    return false;
}


//END CLASS VERTEX


