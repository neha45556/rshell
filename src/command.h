#ifndef COMMAND_H
#define COMMAND_H

#include "Base.hpp"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string>

using namespace std;

class Command : public Base {
    private:
        vector<string> SingleCommand;
        // vector<string> connectors;
        bool flag = false;
        // void populateConnectors(char copy[]);
    public:
        Command() { };
        Command(vector<string > SingleCommand);
        void printCommand();
        void deleteHashtag();
        bool findHashtag();
        bool execute();
        bool checkFlag();
        void setFlagTrue();
        string at(int ); 
        int size();
};

#endif