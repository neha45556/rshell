#ifndef EXECUTE_H
#define EXECUTE_H

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
class Command;

using namespace std;

class Execute : public Base {
    private:
        vector<Base* > CommandLine;
        vector<Base* > Connectors;
        // Input* VectorInput = nullptr;
    public:
        Execute() { };
        // void setInput(Input* );
        // void addCommand(Base* );
        void populateExecute(int, int, Input* );
        void populateExecuteConnectors(Input* );
        void deleteHashtag() { };
        bool findHashtag() { };
        void printCommand();
        bool execute();
        bool checkFlag();
        void setFlagTrue() { };
        void printExecute();
};

#endif