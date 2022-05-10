#include "Vertex.h"

#ifndef SRC_EDGE_H
#define SRC_EDGE_H

class Edge {
    private:
    int id;
    Vertex* vertex1;
    Vertex* vertex2;

    public:
    int getId();
    Vertex* getVertex1();
    Vertex* getVertex2();

    void setId(int id);
    void setVertex1(Vertex* vertex);
    void setVertex2(Vertex* vertex);
};

//Returnt de identifier (id, getal).
int Edge::getId() {
    return id;
}

//Stelt de identifier van de vertex/edge in
//(variabele ‘id’ in voorgestelde UML-diagram).
void Edge::setId(int id) {
    this->id = id;
}

//Returnt een referentie naar de variabele
//‘vertex1/2’.
Vertex* Edge::getVertex1() {
    return vertex1;
}

//Returnt een referentie naar de variabele
//‘vertex1/2’.
Vertex* Edge::getVertex2() {
    return vertex2;
}

//Stelt de referentie naar vertex1/2 in voor de
//edge
void Edge::setVertex1(Vertex* vertex) {
    vertex1 = vertex;
}

//Stelt de referentie naar vertex1/2 in voor de
//edge
void Edge::setVertex2(Vertex* vertex) {
    vertex2 = vertex;
}

#endif //SRC_EDGE_H