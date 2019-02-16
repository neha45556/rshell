#ifndef AND_H
#define AND_H

#include "connector.hpp"

class And : public Connector {
    private:
        // bool (Base* )
    public:
        And() { };
        And(Base* , Base* );
        void deleteHashtag() { };
        bool findHashtag() { };
        void printCommand() { };
        bool execute();
        bool checkFlag();
        void setFlagTrue() { };
};

#endif