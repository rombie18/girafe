//
// Created by DaanJanssen on 15/04/2022.
//

#include "SensorNode.h"

#ifndef SRC_VERTEX_H
#define SRC_VERTEX_H

class Vertex {
    private:
    int id;
    SensorNode* sensornode;

    public:
        Vertex();
        int getId();
        void setId(int id);
        SensorNode* getSensorNode();
        void setSensorNode(SensorNode* sensorNode);

};

Vertex::Vertex() {}

//Returnt de identifier (id, getal).
int Vertex::getId() {
    return id;
}

//Stelt de identifier van de vertex/edge in
//(variabele ‘id’ in voorgestelde UML-diagram).
void Vertex::setId(int id) {
    this->id = id;
}

//Geeft een referentie/verwijzing naar de
//sensornode van deze vertex.
SensorNode* Vertex::getSensorNode() {
    return sensornode;
}

//Stelt de pointer naar de sensornode in
//(variabele ‘sensornode’ in voorgestelde UMLdiagram).
void Vertex::setSensorNode(SensorNode* sensorNode) {
    this->sensornode = sensorNode;
}

#endif //SRC_VERTEX_H
