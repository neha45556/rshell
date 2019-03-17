#include "input.cpp"
#include "command.cpp"
#include "Paren.cpp"
//#include "test.cpp"
#include "SymbolTree.cpp"
#include "LessInput.cpp"
#include "MoreOutput.cpp"
//#include "pipe.cpp"
#include "DoubleOut.cpp"
#include "FullCommand.cpp"
#include "MultCmd.cpp"
#include "semicolon.cpp"
#include "and.cpp"
#include "or.cpp"
#include "pipe.cpp"
#include "Base.hpp"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main () {
        bool userExit = false;
        while (!userExit) {
            Input* input = new Input();
            input->getInput();
            if (input->size() == 0) {
                
            }
            else {
                if (input->at(0) == "exit") {
                    userExit = true;
                    exit(0);
                }
            }
            FullCommand* command = new FullCommand();
            command->parse(0, 0, input);
            command->execute(0, 1);
        }
        
        
        // char inputArray[] = "echo \"1; 2\"; echo \"3 && 4\"; echo \"5 || 6\"";
        // Input* input = new Input(inputArray);
        // FullCommand* command = new FullCommand();
        // command->parse(0, 0, input);
        // command->execute();
        
        
    return 0;
}
