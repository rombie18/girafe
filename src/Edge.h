#include "Vertex.h"

class Edge {
    private:
    int ID;
    Vertex vertex1;
    Vertex vertex2;

    public:
    int getID();
    Vertex getVertex1();
    Vertex getVertex2();

    int setID(int);
    Vertex setVertex1(Vertex);
    Vertex setVertex2(Vertex);
};

int Edge::getID() {
    return ID;
}

Vertex Edge::getVertex1() {
    return vertex1;
}

Vertex Edge::getVertex2() {
    return vertex2;
}

int Edge::setID(int Id) {
    ID = Id;
}

Vertex Edge::setVertex1(Vertex v1) {
    vertex1 = v1;
}

Vertex Edge::setVertex2(Vertex v2) {
    vertex1 = v2;
}