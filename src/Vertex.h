//
// Created by DaanJanssen on 15/04/2022.
//

#include "SensorNode.h"

#ifndef SRC_VERTEX_H
#define SRC_VERTEX_H


class Vertex {
    private:
    int Id;
    SensorNode sensornode;

    public:
        Vertex();
        int getId();
        int setId(int);
        SensorNode getSensorNode();
        void setSensorNode(SensorNode);

};

Vertex::Vertex() {
    Id = 0;
    sensornode.name = "";
    sensornode.room = "";
    sensornode.temperature = 0.0;
    sensornode.humidity = 0.0;
    sensornode.co2 = 0.0;
}

int Vertex::getId() {
    return Id;
}

int Vertex::setId(int id) {
    Id = id;
}

SensorNode Vertex::getSensorNode() {
    return sensornode;
}

void Vertex::setSensorNode(SensorNode sensorNode) {
    sensornode = sensorNode;
}


#endif //SRC_VERTEX_H
