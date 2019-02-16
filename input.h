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
        //void populateExecute(int , int , Execute* );
    public:
        Input() { };
        // Command(vector<string > SingleCommand);
        void getInput();
        // void execute();
        string at(int );
        string ConAt(int );
        int size();
        int ConSize();
        void ConErase(int, int);
};

#endif