//
// Created by DaanJanssen on 15/04/2022.
//

#include <iostream>
#include <string>

#ifndef SRC_SENSORNODE_H
#define SRC_SENSORNODE_H

using namespace std;

struct SensorNode {
    SensorNode(string name, string room, double temperature, double humidity, double co2);
    string name;
    string room;
    double temperature;
    double humidity;
    double co2;
};

SensorNode::SensorNode(string name, string room, double temperature, double humidity, double co2) {
    this->name = name;
    this->room = room;
    this->temperature = temperature;
    this->humidity = humidity;
    this->co2 = co2;
}

#endif //SRC_SENSORNODE_H
