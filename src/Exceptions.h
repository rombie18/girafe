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


#endif //MAIN_CPP_EXCEPTIONS_H
