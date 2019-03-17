#ifndef INPUT_H
#define INPUT_H

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

class Input {
    private:
        char input[100];
        vector<string> VectorInput;
        vector<string> Connectors;
        void populateVector();
        void populateConnectors(char []);
        //bool flag = false;
    public:
        Input() { };
        Input(char []);
        //void parse(int, int);
        void getInput();
        //bool checkFlag();
        //void setFlagFalse();
        string at(int );
        string ConAt(int );
        int size();
        int ConSize();
        void ConErase(int, int);
        
};

#endif