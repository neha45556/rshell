#include "input.cpp"
#include "command.cpp"
#include "Paren.cpp"
//#include "test.cpp"
#include "FullCommand.cpp"
#include "MultCmd.cpp"
#include "semicolon.cpp"
#include "and.cpp"
#include "or.cpp"
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
            if (input->at(0) == "exit") {
                userExit = true;
                exit(0);
            }
            FullCommand* command = new FullCommand();
            command->parse(0, 0, input);
            command->execute();
        }
        //char input1 [] = "butt";
        // char input2[] = "echo hello; echo hello2";
        //Input* input = new Input(input1);
        // Input* input = new Input();
        // input->getInput();
        // //cout << "Gets input" << endl;
        // FullCommand* command = new FullCommand();
        // //cout << "Creates FullCommand" << endl;
        // command->parse(0, 0, input);
        // //cout << "Exits parse" << endl;
        // command->execute();
        // Execute* execute = new Execute();
        // execute->populateExecute(0, 0, input);
        // execute->populateExecuteConnectors(input);
        // execute->execute();
        
    return 0;
}
