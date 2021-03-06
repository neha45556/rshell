#ifndef COMMAND_H
#define COMMAND_H

#include "Base.hpp"
#include "test.h"
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
        bool flag = false;
    public:
        Command() { };
        Command(vector<string > SingleCommand);
        bool checkFlag();
        void setFlagTrue();
        bool execute(int, int);
        string at(int ); 
        int size();
        vector<string> get_data();
};

#endif
