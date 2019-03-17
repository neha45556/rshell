#ifndef PIPE_H
#define PIPE_H

#include "connector.hpp"

using namespace std;

class Pipe : public Connector {
    private:
        
    public:
        Pipe() { };
        Pipe(Base* , Base* );
        bool execute(int, int);
        bool checkFlag() { };
        void setFlagTrue() { };
};

#endif