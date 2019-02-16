#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP

#include <iostream>
#include "Base.hpp"

using namespace std;

class Connector : public Base {
    protected:
        Base* first = nullptr;
        Base* next = nullptr;
    public:
        Connector() { };
        Connector(Base* lhs, Base* rhs) {
            this->first = lhs;
            this->first = rhs;
        }
        virtual bool execute() = 0;
        virtual bool checkFlag() = 0;
};

#endif