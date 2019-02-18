#include "input.h"
#include "command.h"
#include "execute.h"
#include "semicolon.h"
#include "and.h"
#include "or.h"
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
	Execute* execute = new Execute();
        execute->populateExecute(0, 0, input);
        execute->populateExecuteConnectors(input);
        execute->execute();
        }
    return 0;
}
