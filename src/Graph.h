//
// Created by woutr on 22/04/2022.
//

#include <list>
#include "Edge.h"
#include "Vertex.h"

#ifndef MAIN_CPP_GRAPH_H
#define MAIN_CPP_GRAPH_H

using namespace std;

class Graph {
private:
    list<Edge*> edgeList;
    list<Vertex*> vertexList;

public:
    void addVertexToList(Vertex* vertex);
    void addEdgeToList(Edge* edge);
    list<Edge*> getEdges();
    list<Vertex*> getVertices();
    list<Edge*> incidentEdges(Vertex* vertex);
    list<Vertex*> adjecentVertices(Edge* edge);
    bool areAdjecent(Vertex* one, Vertex* two);
    Vertex* opposite(Vertex* vertex, Edge* edge);
};

//Herinner dat de variabele ‘vertexList’ een STLlist is die pointers naar alle vertices bevat.
//De functie voegt dus een pointer naar een
//vertex toe aan de variabele ‘vertexList’.
void Graph::addVertexToList(Vertex* vertex) {
    vertexList.push_front(vertex);
}

//Herinner dat de variabele ‘edgeList’ een STL-list
//is die pointers naar alle edges bevat.
//Voegt een pointer naar een edge toe aan de
//variabele ‘edgeList’.
void Graph::addEdgeToList(Edge* edge) {
    edgeList.push_front(edge);
}

//Geeft een STL-list met pointers naar de edges
//van de grafe
list<Edge*> Graph::getEdges() {
    return edgeList;
}

//Geeft een STL-list met pointers naar de vertices
//van de grafe
list<Vertex*> Graph::getVertices() {
    return vertexList;
}

//De ‘incident edges’ van een vertex zijn alle
//edges die vertrekken/aankomen in deze vertex.
//De functie ‘incidentEdges’ geeft daarom een
//lijst met deze edges voor een gegeven vertex.
list<Edge*> Graph::incidentEdges(Vertex* vertex) {
    list<Edge*> incidentEdges = {};
    for(Edge* edge : edgeList) {
        Vertex* temp1 = edge->getVertex1();
        Vertex* temp2 = edge->getVertex2();
        if (temp1 == vertex || temp2 == vertex) {
            incidentEdges.push_back(edge);
        }
    }

    return incidentEdges;


}

//De ‘adjacent vertices’ van een vertex zijn alle
//vertices die een edge (link) delen met de
//gegeven vertex. De functie ‘adjacentVertices’
//geeft daarom een lijst met deze vertices voor
//een gegeven vertex.
list<Vertex*> Graph::adjecentVertices(Edge* edge) {
    list<Vertex *> vertices;
    vertices.push_back(edge->getVertex1());
    vertices.push_back(edge->getVertex2());

    return vertices;
}

//Geeft een Booleaanse waarde die zegt of twee
//vertices naast mekaar liggen (= rechtstreeks
//met mekaar verbonden door edge).
bool Graph::areAdjecent(Vertex* vertex1, Vertex* vertex2) {
    for(Edge* edge : edgeList) {
        if (edge->getVertex1() == vertex2 && edge->getVertex2() == vertex1) {
            return true;
        } else if (edge->getVertex1() == vertex1 && edge->getVertex2() == vertex2) {
            return true;
        }
    }

    return false;
}

//Geeft de vertex aan de overkant voor een
//gegeven vertex en edge. Dus als één van de
//twee uiteindes (vertices) gekend is, verkrijg je
//met deze functie de andere vertex
Vertex* Graph::opposite(Vertex* vertex, Edge* edge) {
    if (edge->getVertex1() == vertex) {
        return edge->getVertex2();
    } else if (edge->getVertex2() == vertex) {
        return edge->getVertex1();
    } else {
        return nullptr;
    }
}

#endif //MAIN_CPP_GRAPH_H
