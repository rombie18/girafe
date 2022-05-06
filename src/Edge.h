#include "Vertex.h"

#ifndef SRC_EDGE_H
#define SRC_EDGE_H

class Edge {
    private:
    int id;
    Vertex vertex1;
    Vertex vertex2;

    public:
    int getId();
    Vertex getVertex1();
    Vertex getVertex2();

    void setId(int);
    void setVertex1(Vertex);
    void setVertex2(Vertex);
};

int Edge::getId() {
    return id;
}

Vertex Edge::getVertex1() {
    return vertex1;
}

Vertex Edge::getVertex2() {
    return vertex2;
}

void Edge::setId(int id) {
    this->id = id;
}

void Edge::setVertex1(Vertex v1) {
    vertex1 = v1;
}

void Edge::setVertex2(Vertex v2) {
    vertex1 = v2;
}

#endif //SRC_EDGE_H