#ifndef SEMICOLON_H
#define SEMICOLON_H

#include "connector.hpp"

class Semicolon : public Connector {
    private:
        // bool (Base* );
    public:
        Semicolon() { };
        Semicolon(Base* , Base* );
        void deleteHashtag() { };
        bool findHashtag() { };
        void printCommand() { };
        bool execute();
        bool checkFlag();
        void setFlagTrue() { };
};

#endif