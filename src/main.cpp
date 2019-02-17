#include "input.cpp"
#include "command.cpp"
#include "execute.cpp"
#include "semicolon.cpp"
#include "and.cpp"
#include "or.cpp"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main () {
        
        char input1 [] = "butt";
        // char input2[] = "echo hello; echo hello2";
        Input* input = new Input(input1);
        //input->parse();
        //input->getInput();
        // input->parse();
        Execute* execute = new Execute();
        execute->populateExecute(0, 0, input);
        execute->populateExecuteConnectors(input);
        execute->execute();
        
    return 0;
}
