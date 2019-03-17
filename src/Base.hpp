#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <vector>

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
        virtual bool execute(int, int) = 0;
        virtual bool checkFlag() = 0;
        virtual void setFlagTrue() = 0;
        virtual string at(int ) = 0;
        virtual int size() = 0;
        virtual vector<string> get_data() = 0;
};

#endif
