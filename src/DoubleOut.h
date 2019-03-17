#ifndef DOUBLEOUT_H
#define DOUBLEOUT_H

#include "connector.hpp"

class DoubleOut : public Connector {
    private:
    
    public:
        DoubleOut() { };
        DoubleOut(Base* , Base* );
        bool execute(int, int);
        bool checkFlag();
        void setFlagTrue() { };
};

#endif