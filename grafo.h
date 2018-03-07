/* 
 * File:   grafo.h
 * Author: juane
 *
 * Created on 05 March 2018, 11:04
 */

#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int INF = 0x0fffffff;

/* Class to store vertices in the graph.
   own adjacency list to store all the edges.
   Each vertex has a name (int ).*/
class Vertex {
    typedef pair<int, Vertex*> ve;
    vector<ve> adj; //cost, destination vertex
    int name; //name of the vertex
public:

    Vertex(int id) : name(id) {
    }

    void insertAdj(const pair<int, Vertex *> &edge) {
        adj.push_back(edge);
    }

    vector<ve> getAdj() const {
        return adj;
    }

    
    int getName() const {
        return name;
    }
    
    int getWeight(int name);
    void setWeight(int name, int w);
    bool isAdjacent(int namep);

    void printNeighbours(); //prints neighbours of the vertex
};

/* Compare class. */
class CompareLess {
public:
    bool operator()(const pair<int, Vertex *> x, const pair<int, Vertex *> y) {
        return (x.first < y.first); 
    }
};

/* Graph class
   Stores a graph.
   Implements Dijkstra's algorithms (Kruskal, Prim and BFS in the future).
   Can be weighted and directed. */
class Graph {
    typedef map<int, Vertex*> vmap;
    bool directed; //is directed or not
    unsigned int numv; //number of vertices
    vmap work; //stores the map from name of vertex to Vertex class
public:
    Graph(bool dirp = false) : numv(0), directed(dirp) {    //Set if is directed or undirected
    }

    void addVertex(int); //adds a new vertex
    void addEdge(int from, int to, int cost); //adds a new edge
    bool areAdjacent(int v1, int v2) const;
    int getWeight(int v1, int v2) const;
    void setWight(int v1, int v2, int w);
    void clear();
    
    void print() const;

    //Classic algorithm in graphs
    vector<int> Dijkstra(int start); //implements Dijkstra's algo
    
    /*FUTURE*/
    void Prim(int); //Prim's algo
    void Kruskal(); //Kruskal's algo
    void BFS(int); //BFS algo
    /*END FUTURE*/
    
    //End classic algorithm in graphs
};

#endif /* GRAFO_H */

