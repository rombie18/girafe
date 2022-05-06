//
// Created by woutr on 22/04/2022.
//
#include <list>
#include "Edge.h"
#include "Vertex.h"

using namespace std;

class Graph {
private:
    list<Edge> edgeList;
    list<Vertex> vertexList;

public:
    void addVertexToList(Vertex vertex);
    void addEdgeToList(Edge edge);
    list<Edge> getEdges();
    list<Vertex> getVertices();
    //list<Edge> incidentEdges(Vertex vertex);
    list<Vertex> adjecentVertices(Edge edge);
    bool areAdjecent(Vertex one, Vertex two);
    bool opposite();
};

void Graph::addVertexToList(Vertex vertex) {
    vertexList.push_front(vertex);
}

void Graph::addEdgeToList(Edge edge) {
    edgeList.push_front(edge);
}

list<Edge> Graph::getEdges() {
    return edgeList;
}

list<Vertex> Graph::getVertices() {
    return vertexList;
}

//list<Edge> Graph::incidentEdges(Vertex vertex) {
    //TODO
//    cout << "";
//}

list<Vertex> Graph::adjecentVertices(Edge edge) {
    list<Vertex> vertices;
    vertices.push_back(edge.getVertex1());
    vertices.push_back(edge.getVertex2());
    return vertices;
}
/*
bool Graph::areAdjecent(Vertex vertexOne, Vertex vertexTwo) {
    for(Edge e : edgeList) {
        if (e.getVertex1() == vertexTwo && e.getVertex2() == vertexOne) {

        }
    }
}*/

bool Graph::opposite() {
    //TODO
    return false;
}