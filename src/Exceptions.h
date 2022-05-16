//
// Created by DaanJanssen on 16/05/2022.
//

#ifndef MAIN_CPP_EXCEPTIONS_H
#define MAIN_CPP_EXCEPTIONS_H

using namespace std;

struct InvalidStartVertexException : public exception {
    string message;

    InvalidStartVertexException(string message) {
        this->message = message;
    }

    ~InvalidStartVertexException() throw() {}

    const char *what() const throw() {
        return message.c_str();
    }
};

struct InvalidXmlException : public exception {
    string message;

    InvalidXmlException(string message) {
        this->message = message;
    }

    ~InvalidXmlException() throw() {}

    const char *what() const throw() {
        return message.c_str();
    }
};

bool validXmlVertex(pugi::xml_node& node) {
    if (node.attribute("id") == NULL) {
        return false;
    }
    return true;
}

bool validXmlSensornode(const pugi::xml_node& node) {
    if (node.attribute("name") == NULL) {
        return false;
    }
    if (node.attribute("room") == NULL) {
        return false;
    }
    return true;
}

bool validXmlEdge(pugi::xml_node& node) {
    if (node.attribute("id") == NULL) {
        return false;
    }
    if (node.attribute("vertex1") == NULL) {
        return false;
    }
    if (node.attribute("vertex2") == NULL) {
        return false;
    }
    return true;
}


#endif //MAIN_CPP_EXCEPTIONS_H
