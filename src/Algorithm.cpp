//
// Created by DaanJanssen on 29/04/2022.
//

#include <vector>
#include "Vertex.h"

using namespace std;

bool bfs(Vertex startVertex) {
    int depth = 0;
    vector<Vertex> vertices;
    vector<int> usedVertices;

    startVertex.

}

/*
    int i = 0; //Iterator
    int V = 7; //Grootte bool array
    bool* visited = new bool[V] ;   //Bool array aanmaken
    for (int j = 0; j < V; j++)
        visited[j] = false; //Bool array initieel alle leden false

    list<Vertex<int>*> vertexLijst = g.getVertices();
    list<Vertex<int>*> adjlist;
    Vertex<int>* v = vertexLijst.back(); //Vertex7 wordt uit lijst gehaald (beginnen we mee)

    cout << "vertex" << v->getId()<< ": stap"<< i << endl;

    i++;
    vertexLijst.pop_back(); //We starten met vertex 7 (E116), deze staat laatst in de vertexlijst
    visited[v->getId()] = true; //Deze vertex is nu visited
    adjlist = g.adjacentVertices(v);    //Buren zoeken van vertex 7 -> In lijst plaatsen
    list<Vertex<int> *> adj2list;   //2e Hulplijst aanmaken
    for(Vertex<int> * vert : adjlist){cout << "vertex" << vert->getId()<< ": stap"<< i << endl;}  //Deze vertices worden in de eerste stap doorlopen

    while(!adjlist.empty()) {
        i++;
        for(Vertex<int> * num : adjlist){visited[num->getId()] = true; //Vertices in adjlist zijn "visited"

        for(Vertex<int> * vert : g.adjacentVertices(num))
            if(!visited[vert->getId()]){adj2list.push_back(vert);}}  //We plaatsen de niet bezochte buren van vert in adj2list
        adjlist.clear();    //adjlist leegmaken

        for (Vertex<int> *y : adj2list) {
            if(!visited[y->getId()]){
                visited[y->getId()] = true;
                cout << "vertex" << y->getId() << ": stap" << i << endl; //Deze vertices worden in de 'i'de stap doorlopen
                adjlist.push_back(y);   //Vervolgens worden deze vertices in adjlist geplaatst, zodat ook die buren bezocht kunnen worden
            }
        }
        adj2list.clear();   //adj2list wordt leeggemaakt

    }

*/

