//
// Created by DaanJanssen on 15/04/2022.
//

#include <iostream>
#include <string>

#ifndef SRC_SENSORNODE_H
#define SRC_SENSORNODE_H

using namespace std;

struct SensorNode {
    string name;
    string room;
    double temperature;
    double humidity;
    double co2;
};

#endif //SRC_SENSORNODE_H
