
/* 
 * File:   main.cpp
 * Author: juane
 *
 * Created on 05 March 2018, 11:11
 */

#include "grafo.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Graph *grafo=new Graph(false);
    grafo->addVertex(1);
    grafo->addVertex(2);
    grafo->addVertex(3);
    grafo->addVertex(4);
    grafo->addVertex(5);
    grafo->addVertex(6);
    grafo->addVertex(7);
    grafo->addVertex(8);
    grafo->addVertex(9);
    grafo->addVertex(10);
    grafo->addEdge(1, 2, 10);
    grafo->addEdge(1, 3, 25);
    grafo->addEdge(1, 4, 35);
    grafo->addEdge(1, 7, 100);
    grafo->addEdge(2, 5, 60);
    grafo->addEdge(2, 7, 40);
    grafo->addEdge(3, 8, 90);
    grafo->addEdge(3, 1, 15);
    grafo->addEdge(3, 6, 80);
    grafo->addEdge(4, 9, 10);
    grafo->addEdge(5, 10, 70);
    grafo->addEdge(5, 1, 40);
    grafo->addEdge(8, 3, 30);
    grafo->addEdge(2, 4, 10);
    grafo->addEdge(10, 1, 58);
    grafo->addEdge(10, 1, 60);
    grafo->addEdge(10, 1, 59);

    cout << grafo->areAdjacent(3,1) << endl;
     cout << grafo->areAdjacent(3,9) << endl;
    cout << grafo->getWeight(3,9) << endl;
    cout << grafo->getWeight(1,3) << endl;
    cout << grafo->getWeight(1, 1) << endl;
    cout << grafo->getWeight(1, 2) << endl;
    
    vector<int> dij=grafo->Dijkstra(1);
    
    cout << "\n";
    for (int i = 1; i < dij.size(); i++) {
	cout << dij[i] << " ";
    }

    grafo->print();

    return 0;
}

