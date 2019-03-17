#ifndef OR_H
#define OR_H

#include "connector.hpp"

class Or : public Connector {
    private:
        // bool (Base* )
    public:
        Or() { };
        Or(Base* , Base* );
        void deleteHashtag() { };
        bool findHashtag() { };
        void printCommand() { };
        bool execute(int, int);
        bool checkFlag();
        void setFlagTrue() { };
};

#endif