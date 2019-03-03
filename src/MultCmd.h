#ifndef MULTCMD_H
#define MULTCMD_H

#include "Base.hpp"
#include "input.h"
#include "command.h"
#include "semicolon.h"
#include "and.h"
#include "or.h"
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

class Input;
//class Command;

using namespace std;

class MultCmd : public Base {
    private:
        vector<Base* > CommandLine;
        vector<Base* > Connectors;
        vector<string> StringConnectors;
    public:
        MultCmd() { };
        bool execute();
        bool checkFlag();
        void setFlagTrue() { };
        void addConnector(string );
        void addCommand(Base* );
        void addManyCommands(int , int , vector<string> );
        //void printCommand();
};

#endif