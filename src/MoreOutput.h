#ifndef MOREOUTPUT_H
#define MOREOUTPUT_H

#include "connector.hpp"

class MoreOutput : public Connector {
    private:
        // bool (Base* );
        string type = ">";
    public:
        MoreOutput() { };
        MoreOutput(Base* , Base* );
        bool execute(int, int);
        bool checkFlag();
        void setFlagTrue() { };
};

#endif