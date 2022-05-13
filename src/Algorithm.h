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

void bfs(Graph* graph, Vertex<SensorNode>* startVertex) {

    int level = 0;

    list<Edge*> exploredEdges = list<Edge*>();
    list<Vertex<SensorNode>*> exploredVertices = list<Vertex<SensorNode>*>();

    map<int, vector<Vertex<SensorNode>*>> vertices = map<int, vector<Vertex<SensorNode>*>>();

    vertices[level] = vector<Vertex<SensorNode>*>();
    vertices[level].push_back(startVertex);

    cout << "Type of Edge:"<< endl;

    while (!vertices[level].empty()) {
        vertices[level+1] = vector<Vertex<SensorNode>*>();
        for(Vertex<SensorNode>* vertex : vertices[level]) {
            for(Edge* edge : graph->incidentEdges(vertex)) {
                if (!in_list(exploredEdges, edge)) {
                    exploredEdges.push_back(edge);
                    Vertex<SensorNode>* opposite = graph->opposite(vertex, edge);
                    if (!in_list(exploredVertices, opposite)) {
                        exploredVertices.push_back(opposite);
                        cout << "  Discovery edge: " + to_string(edge->getId()) << endl;
                        vertices[level+1].push_back(opposite);
                    } else {
                        cout << "  Cross edge: " + to_string(edge->getId()) << endl;
                    }
                }
            }
        }
        level++;
    }
    vertices.erase(level);

    cout << endl;
    cout << "Levels:"<< endl;


    map<int, vector<Vertex<SensorNode>*>>::iterator i;
    for(i = vertices.begin(); i != vertices.end(); i++) {
        cout << "  Level " + to_string(i->first) + ":"<< endl;
        for(Vertex<SensorNode>* vertex : i->second) {
            cout << "    Vertex " + to_string(vertex->getId()) + ": " + vertex->getSensorNode()->room << endl;
        }
    }
}

#endif //MAIN_CPP_ALGORITHM_H
