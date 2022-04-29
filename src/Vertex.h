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
        SensorNode getSensorNode();
        int setId(int);
        SensorNode setSensorNode(string,string,double,double,double);

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

SensorNode Vertex::setSensorNode(string n,string r,double t,double h,double c) {
    sensornode.name = n;
    sensornode.room = r;
    sensornode.temperature = t;
    sensornode.humidity = h;
    sensornode.co2 = c;
}



#endif //SRC_VERTEX_H
