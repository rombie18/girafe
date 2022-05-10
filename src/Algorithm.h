//
// Created by daanj on 10/05/2022.
//

#include <vector>
#include "Vertex.h"
#include "Graph.h"

#ifndef MAIN_CPP_ALGORITHM_H
#define MAIN_CPP_ALGORITHM_H

using namespace std;

void bfss(Graph* graph, Vertex* startVertex) {
    list<Vertex*> level1 = graph->adjecentVertices(startVertex);
}

bool bfs(Graph* g) {
    int i = 0; //Iterator
    int V = 7; //Grootte bool array
    bool* visited = new bool[V] ;   //Bool array aanmaken
    for (int j = 0; j < V; j++) {
        visited[j] = false; //Bool array initieel alle leden false

        list<Vertex *> vertexLijst = g->getVertices();
        list<Vertex *> adjlist;
        Vertex *v = vertexLijst.back(); //Vertex7 wordt uit lijst gehaald (beginnen we mee)

        cout << "vertex" << v->getId() << ": stap" << i << endl;

        i++;
        vertexLijst.pop_back(); //We starten met vertex 7 (E116), deze staat laatst in de vertexlijst
        visited[v->getId()] = true; //Deze vertex is nu visited
        adjlist = g->adjecentVertices(v);    //Buren zoeken van vertex 7 -> In lijst plaatsen
        list<Vertex *> adj2list;   //2e Hulplijst aanmaken
        for (Vertex *vert: adjlist) {
            cout << "vertex" << vert->getId() << ": stap" << i << endl;
        }  //Deze vertices worden in de eerste stap doorlopen

        while (!adjlist.empty()) {
            i++;
            for (Vertex *num: adjlist) {
                visited[num->getId()] = true; //Vertices in adjlist zijn "visited"

                for (Vertex *vert: g->adjecentVertices(num))
                    if (!visited[vert->getId()]) { adj2list.push_back(vert); }
            }  //We plaatsen de niet bezochte buren van vert in adj2list
            adjlist.clear();    //adjlist leegmaken

            for (Vertex *y: adj2list) {
                if (!visited[y->getId()]) {
                    visited[y->getId()] = true;
                    cout << "vertex" << y->getId() << ": stap" << i
                         << endl; //Deze vertices worden in de 'i'de stap doorlopen
                    adjlist.push_back(
                            y);   //Vervolgens worden deze vertices in adjlist geplaatst, zodat ook die buren bezocht kunnen worden
                }
            }
            adj2list.clear();   //adj2list wordt leeggemaakt

        }
    }
}

#endif //MAIN_CPP_ALGORITHM_H
