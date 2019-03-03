#ifndef BASE_H
#define BASE_H

#include <iostream>

using namespace std;

class Base {
    private:
    
        bool flag = false;
        
    public:
    
        Base() { };
        //virtual void deleteHashtag() = 0;
        //virtual bool findHashtag() = 0;
        //virtual void printCommand() = 0;
        // virtual void addCommand(Base* ) = 0;
        // virtual void addConnector(Base* ) = 0;
        virtual bool execute() = 0;
        virtual bool checkFlag() = 0;
        virtual void setFlagTrue() = 0;
        
};

#endif