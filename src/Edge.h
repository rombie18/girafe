#include "Vertex.h"

#ifndef SRC_EDGE_H
#define SRC_EDGE_H

class Edge {
    private:
    int id;
    Vertex<SensorNode>* vertex1;
    Vertex<SensorNode>* vertex2;

    public:
    Edge() {}
    ~Edge() {}

    int getId();
    Vertex<SensorNode>* getVertex1();
    Vertex<SensorNode>* getVertex2();

    void setId(int id);
    void setVertex1(Vertex<SensorNode>* vertex);
    void setVertex2(Vertex<SensorNode>* vertex);
};

//Returnt de identifier (id, getal).
int Edge::getId() {
    return id;
}

//Stelt de identifier van de vertex/edge in (variabele ‘id’ in voorgestelde UML-diagram).
void Edge::setId(int id) {
    this->id = id;
}

//Returnt een referentie naar de variabele ‘vertex1/2’.
Vertex<SensorNode>* Edge::getVertex1() {
    return vertex1;
}

//Returnt een referentie naar de variabele ‘vertex1/2’.
Vertex<SensorNode>* Edge::getVertex2() {
    return vertex2;
}

//Stelt de referentie naar vertex1/2 in voor de edge
void Edge::setVertex1(Vertex<SensorNode>* vertex) {
    vertex1 = vertex;
}

//Stelt de referentie naar vertex1/2 in voor de edge
void Edge::setVertex2(Vertex<SensorNode>* vertex) {
    vertex2 = vertex;
}

#endif //SRC_EDGE_H