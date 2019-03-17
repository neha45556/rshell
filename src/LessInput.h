#ifndef LESSINPUT_H
#define LESSINPUT_H

#include "connector.hpp"

class LessInput : public Connector {
    private:
        // bool (Base* );
    public:
        LessInput() { };
        LessInput(Base* , Base* );
        bool execute(int, int);
        bool checkFlag();
        void setFlagTrue() { };
};

#endif