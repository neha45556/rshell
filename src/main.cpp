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
        
        Input* input = new Input();
        input->getInput();
        Execute* execute = new Execute();
        execute->populateExecute(0, 0, input);
        execute->populateExecuteConnectors(input);
        execute->execute();
        
    return 0;
}
