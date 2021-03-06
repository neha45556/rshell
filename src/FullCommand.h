#ifndef FULLCOMMAND_H
#define FULLCOMMAND_H

#include "Base.hpp"
#include "input.h"
#include "Paren.h"
#include "command.h"
#include "semicolon.h"
#include "and.h"
#include "or.h"
#include "LessInput.h"
#include "MoreOutput.h"
#include "SymbolTree.h"
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

class FullCommand : public Base {
    private:
        vector<Base* > CommandLine;
        vector<Base* > Connectors;
        vector<string> StringConnectors;
    public:
        FullCommand() { };
        void parse(int, int, Input* );
        void addCommand(Base* );
        bool execute(int , int);
        bool checkFlag() { };
        void setFlagTrue() { };
        string at(int ) { };
        int size() { };
        vector<string> get_data() { };
};

#endif