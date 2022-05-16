#include "SensorNode.h"

#ifndef SRC_VERTEX_H
#define SRC_VERTEX_H

template<class T>
class Vertex {
    private:
    int id;

    T* sensornode;

    public:
        Vertex();
        ~Vertex();

        int getId();
        void setId(int id);
        T* getSensorNode();
        void setSensorNode(T* sensorNode);

};

template<typename T>
Vertex<T>::Vertex() {}

//Returnt de identifier (id, getal).
template<typename T>
int Vertex<T>::getId() {
    return id;
}

//Stelt de identifier van de vertex/edge in
//(variabele ‘id’ in voorgestelde UML-diagram).
template<typename T>
void Vertex<T>::setId(int id) {
    this->id = id;
}

//Geeft een referentie/verwijzing naar de
//sensornode van deze vertex.
template<typename T>
T* Vertex<T>::getSensorNode() {
    return sensornode;
}

//Stelt de pointer naar de sensornode in
//(variabele ‘sensornode’ in voorgestelde UMLdiagram).
template<typename T>
void Vertex<T>::setSensorNode(T* sensorNode) {
    this->sensornode = sensorNode;
}

#endif //SRC_VERTEX_H
