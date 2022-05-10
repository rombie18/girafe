//
// Created by DaanJanssen on 10/05/2022.
//

#include <vector>
#include <map>
#include <algorithm>
#include "Vertex.h"
#include "Graph.h"

#ifndef MAIN_CPP_ALGORITHM_H
#define MAIN_CPP_ALGORITHM_H

using namespace std;

template <typename T>
bool in_list(std::list<T> haystack, T needle) {
    return find(haystack.begin(), haystack.end(), needle) != haystack.end();
}

void bfs(Graph* graph, Vertex* startVertex) {

    int level = 0;

    list<Edge*> exploredEdges = list<Edge*>();
    list<Vertex*> exploredVertices = list<Vertex*>();

    map<int, vector<Vertex*>> l = map<int, vector<Vertex*>>();

    l[level] = vector<Vertex*>();
    l[level].push_back(startVertex);

    while (!l[level].empty()) {
        l[level+1] = vector<Vertex*>();
        for(Vertex* vertex : l[level]) {
            for(Edge* edge : graph->incidentEdges(vertex)) {
                if (!in_list(exploredEdges, edge)) {
                    exploredEdges.push_back(edge);
                    Vertex* opposite = graph->opposite(vertex, edge);
                    if (!in_list(exploredVertices, opposite)) {
                        exploredVertices.push_back(opposite);
                        cout << "Discovery edge: " + to_string(edge->getId()) << endl;
                        l[level+1].push_back(opposite);
                    } else {
                        cout << "Cross edge: " + to_string(edge->getId()) << endl;
                    }
                }
            }
        }
        level++;
    }

    cout << endl;

    map<int, vector<Vertex*>>::iterator i;
    for(i = l.begin(); i != l.end(); i++) {
        cout << "Level " + to_string(i->first) << endl;
        for(Vertex* vertex : i->second) {
            cout << " Vertex " + to_string(vertex->getId()) + ": " + vertex->getSensorNode()->room << endl;
        }
    }
}

// cout << vertex + " level: " << + level << endl;
#endif //MAIN_CPP_ALGORITHM_H
