#ifndef PAREN_H
#define PAREN_H

#include "Base.hpp"
#include "input.h"
#include "MultCmd.h"
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

class Paren : public Base {
    private:
        vector<Base* > CommandLine;
        vector<Base* > Connectors;
    public:
        Paren() { };
        // virtual void printCommand() = 0;
        bool execute();
        void addCommand(Base* );
        void addConnector(Base* );
        bool checkFlag();
        void setFlagTrue() { };
};

#endif