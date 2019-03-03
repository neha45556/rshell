#include "Paren.h"

using namespace std;

bool Paren::execute(){
    //cout << "Paren execute" << endl;
    if (this->Connectors.empty()) {
       // cout << "Executing on Commands" << endl;
        for (int i = 0; i < this->CommandLine.size(); i++) {
        //    cout << "Executing command" << endl;
            return this->CommandLine.at(i)->execute();
        }
    }
    for (int i = 0; i < this->Connectors.size(); i++) {
        this->Connectors.at(i)->execute();
    }
}

void Paren::addCommand(Base* input) {
    this->CommandLine.push_back(input);
}

void Paren::addConnector(Base* connector) {
    this->Connectors.push_back(connector);
}

bool Paren::checkFlag() {
    return this->CommandLine.at(CommandLine.size() - 1)->checkFlag();
}