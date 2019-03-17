#ifndef SYMBOLTREE_H
#define SYMBOLTREE_H

#include "Base.hpp"
#include "LessInput.h"
#include "MoreOutput.h"
#include "pipe.h"
#include "DoubleOut.h"
// #include "Paren.h"
// #include "MultCmd.h"
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

class SymbolTree : public Base {
    private:
        vector<string> SingleCommand;
        vector<Base* > Symbols; //redirections
        vector<Base* > SymbolCommands; //actual command
        vector<string> StringSymbols; 
        bool flag = false;
    public:
        SymbolTree() { };
        SymbolTree(vector<string> );
        bool checkFlag();
        void setFlagTrue();
        bool execute(int, int);
        string at(int) { };
        int size() { };
        vector<string> get_data() { };
        void SymbolParse(int, int);
};
     
#endif