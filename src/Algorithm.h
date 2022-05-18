#include <vector>
#include <map>
#include <algorithm>
#include "Vertex.h"
#include "Graph.h"

#ifndef MAIN_CPP_ALGORITHM_H
#define MAIN_CPP_ALGORITHM_H

using namespace std;

// Helper function to check if object is already present in list
template <typename T>
bool in_list(std::list<T> haystack, T needle) {
    return find(haystack.begin(), haystack.end(), needle) != haystack.end();
}

// Breadth First Search algorithm
// Returns a map with vertices ordered by level
// Eg. {0: ["E116"], 1: ["E110", "E117"], 2: ["E113", "E123", "E456"]}
map<int, vector<Vertex<SensorNode>*>> bfs(Graph* graph, Vertex<SensorNode>* startVertex) {

    int level = 0;

    list<Edge*> exploredEdges = list<Edge*>();
    list<Vertex<SensorNode>*> exploredVertices = list<Vertex<SensorNode>*>();

    map<int, vector<Vertex<SensorNode>*>> vertices = map<int, vector<Vertex<SensorNode>*>>();

    vertices[level] = vector<Vertex<SensorNode>*>();
    vertices[level].push_back(startVertex);

    while (!vertices[level].empty()) {
        vertices[level+1] = vector<Vertex<SensorNode>*>();
        for(Vertex<SensorNode>* vertex : vertices[level]) {
            for(Edge* edge : graph->incidentEdges(vertex)) {
                if (!in_list(exploredEdges, edge)) {
                    exploredEdges.push_back(edge);
                    Vertex<SensorNode>* opposite = graph->opposite(vertex, edge);
                    if (!in_list(exploredVertices, opposite)) {
                        exploredVertices.push_back(opposite);
                        vertices[level+1].push_back(opposite);
                        //cout << "  Discovery edge: " + to_string(edge->getId()) << endl;
                    } else {
                        //cout << "  Cross edge: " + to_string(edge->getId()) << endl;
                    }
                }
            }
        }
        level++;
    }
    vertices.erase(level);

    return vertices;
}

#endif //MAIN_CPP_ALGORITHM_H
