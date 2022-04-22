//
// Created by woutr on 22/04/2022.
//
#include <list>
using namespace std;

class Edge {};
class Vertex {};

class Graph {
private:
    list<Edge> edgeList;
    list<Vertex> vertexList;

public:
    void addVertexToList(Vertex vertex);
    void addEdgeToList(Edge edge);
    list<Edge> getEdges();
    list<Vertex> getVertices();
    list<Edge> incidentEdges(Vertex vertex);
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

list<Edge> Graph::incidentEdges(Vertex vertex) {
    //TODO
    return list<Edge>();
}

list<Vertex> Graph::adjecentVertices(Edge edge) {
    //TODO
    return list<Vertex>();
}

bool Graph::areAdjecent(Vertex one, Vertex two) {
    //TODO
    return false;
}

bool Graph::opposite() {
    //TODO
    return false;
}