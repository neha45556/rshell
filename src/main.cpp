#include "input.h"
#include "command.h"
#include "Paren.h"
//#include "test.h"
#include "SymbolTree.h"
#include "LessInput.h"
#include "MoreOutput.h"
#include "pipe.h"
#include "DoubleOut.h"
#include "FullCommand.h"
#include "MultCmd.h"
#include "semicolon.h"
#include "and.h"
#include "or.h"
#include "pipe.h"
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
