#include "SymbolTree.h"
#include <algorithm>

using namespace std;

SymbolTree::SymbolTree(vector<string> VectorString) {
    for(int i = 0; i < VectorString.size(); i++) {
        this->SingleCommand.push_back(VectorString.at(i));
        //cout << this->SingleCommand.at(i) << endl;
    }
}
void SymbolTree::SymbolParse(int startOfCommand, int endOfCommand) {
    for(int i = startOfCommand; i < this->SingleCommand.size(); i++) {
        //cout << "SymbolParse loop: " << SingleCommand.at(i) << endl;
        size_t foundSymbolLeft = this->SingleCommand.at(i).find("<");
        size_t foundSymbolDouble = this->SingleCommand.at(i).find(">>");
        size_t foundSymbolRight = this->SingleCommand.at(i).find(">");
        size_t foundSymbolPipe = this->SingleCommand.at(i).find("|");
        vector<string > SeperatedVector;
        if (foundSymbolLeft != string::npos) {
            //cout << "Found symbol left" << endl;
            endOfCommand = i;
            for (int j = startOfCommand; j < endOfCommand; j++) {
                string str = this->SingleCommand.at(j);
                SeperatedVector.push_back(str);
            }
            startOfCommand = endOfCommand + 1;
            Command* command = new Command(SeperatedVector);
            SymbolCommands.push_back(command);
            StringSymbols.push_back("<");
            SymbolParse(startOfCommand, endOfCommand);
            break;
        }
        else if (foundSymbolDouble != string::npos) {
            endOfCommand = i;
            //cout << "hello" << endl;
            for (int j = startOfCommand; j < endOfCommand; j++) {
                string str = this->SingleCommand.at(j);
                SeperatedVector.push_back(str);
            }
            startOfCommand = endOfCommand + 1;
            Command* command = new Command(SeperatedVector);
            SymbolCommands.push_back(command);
            StringSymbols.push_back(">>");
            SymbolParse(startOfCommand, endOfCommand);
            break;
        }
        else if (foundSymbolRight != string::npos) {
            //cout << "Found symbol right" << endl;
            endOfCommand = i;
            for (int j = startOfCommand; j < endOfCommand; j++) {
                string str = this->SingleCommand.at(j);
                SeperatedVector.push_back(str);
            }
            startOfCommand = endOfCommand + 1;
            Command* command = new Command(SeperatedVector);
            SymbolCommands.push_back(command);
            StringSymbols.push_back(">");
            SymbolParse(startOfCommand, endOfCommand);
            break;
        }
        else if (foundSymbolPipe != string::npos) {
            endOfCommand = i;
            for (int j = startOfCommand; j < endOfCommand; j++) {
                string str = this->SingleCommand.at(j);
                SeperatedVector.push_back(str);
            }
            startOfCommand = endOfCommand + 1;
            Command* command = new Command(SeperatedVector);
            SymbolCommands.push_back(command);
            StringSymbols.push_back("|");
            SymbolParse(startOfCommand, endOfCommand);
            break;
        }
        else if (i == this->SingleCommand.size() - 1) {
            //cout << "nothing" << endl;
            for (int j = startOfCommand; j < this->SingleCommand.size(); j++) {
                string str = this->SingleCommand.at(j);
                SeperatedVector.push_back(str);
            }
            Command* command = new Command(SeperatedVector);
            this->SymbolCommands.push_back(command);
            break;
        }
    }
    
}
bool SymbolTree::execute(int in, int out) {
    // cout << "testing" << endl;
    // cout << SingleCommand.size() << endl;
    // for (int ii = 0; ii < this->SingleCommand.size(); ii++) {
    //     cout << "helo" << endl;
    //     cout << SingleCommand.at(ii) << endl;
    // }
    // cout << "Enters Symbol Command execute" << endl;
    if (this->StringSymbols.empty()) {
        //cout << "No connectors" << endl;
        for (int i = 0; i < SymbolCommands.size(); i++) {
            SymbolCommands.at(i)->execute(0, 1);
        }    
    }
    else {
        int counter = 0;
        // cout << StringSymbols.size() << endl;
        // cout << "-------------------------------------------------------------" << endl;
        // for (int a = 0; a < StringSymbols.size(); a++) {
        //     cout << StringSymbols.at(a) << endl;
        // }
        // cout << "-------------------------------------------------------------" << endl;
        for (int i = 0; i < StringSymbols.size(); i++) {
            //cout << "Enters symbol execute for loop" << endl;
            if (StringSymbols.at(i) == ">") {
                if (i == 0) {
                    Base* lhs = SymbolCommands.at(counter);
                    //cout << "Set LHS" << endl;
                    Base* rhs = nullptr;
                    //cout << "Set RHS" << endl;
                    if ((counter+1) > SymbolCommands.size() - 1) {
                        rhs = nullptr;
                    }
                    else {
                        rhs = SymbolCommands.at(counter + 1);
                    }
                    MoreOutput* MO = new MoreOutput(lhs, rhs);
                    //cout << "Created New And" << endl;
                    this->Symbols.push_back(MO);
                    //cout << "Pushed it in Connectors vector" << endl;
                    counter++;
                }
                else {
                    //cout << "Enters else" << endl;
                    Base* lhs = this->Symbols.at(i - 1);
                    //cout << "Set lhs" << endl;
                    Base* rhs = nullptr;
                    if ((counter + 1) > SymbolCommands.size() - 1) {
                        rhs = nullptr;
                    }
                    else {
                        //cout << "Set rhs" << endl;
                        rhs = SymbolCommands.at(counter + 1);
                    }
                    MoreOutput* MO = new MoreOutput(lhs, rhs);
                    this->Symbols.push_back(MO);
                    //cout << "Hello" << endl;
                    counter++;
                }
            }
            else if (StringSymbols.at(i) == "<") {
                if (i == 0) {
                    Base* lhs = SymbolCommands.at(counter);
                    //cout << "Set LHS" << endl;
                    Base* rhs = nullptr;
                    //cout << "Set RHS" << endl;
                    if ((counter+1) > SymbolCommands.size() - 1) {
                        rhs = nullptr;
                    }
                    else {
                        rhs = SymbolCommands.at(counter + 1);
                    }
                    LessInput* LI = new LessInput(lhs, rhs);
                    //cout << "Created New And" << endl;
                    this->Symbols.push_back(LI);
                    //cout << "Pushed it in Connectors vector" << endl;
                    counter++;
                }
                else {
                    Base* lhs = this->Symbols.at(i - 1);
                    Base* rhs = nullptr;
                    if ((counter + 1) > SymbolCommands.size() - 1) {
                        rhs = nullptr;
                    }
                    else {
                        rhs = SymbolCommands.at(counter + 1);
                    }
                    LessInput* LI = new LessInput(lhs, rhs);
                    this->Symbols.push_back(LI);
                    counter++;
                }
            }
            else if (StringSymbols.at(i) == "|") {
                if (i == 0) {
                    Base* lhs = SymbolCommands.at(counter);
                    //cout << "Set LHS" << endl;
                    Base* rhs = nullptr;
                    //cout << "Set RHS" << endl;
                    if ((counter+1) > SymbolCommands.size() - 1) {
                        rhs = nullptr;
                    }
                    else {
                        rhs = SymbolCommands.at(counter + 1);
                    }
                    Pipe* pipe = new Pipe(lhs, rhs);
                    //cout << "Created New And" << endl;
                    this->Symbols.push_back(pipe);
                    //cout << "Pushed it in Connectors vector" << endl;
                    counter++;
                }
                else {
                    Base* lhs = this->Symbols.at(i - 1);
                    Base* rhs = nullptr;
                    if ((counter + 1) > SymbolCommands.size() - 1) {
                        rhs = nullptr;
                    }
                    else {
                        rhs = SymbolCommands.at(counter + 1);
                    }
                    Pipe* pipe = new Pipe(lhs, rhs);
                    this->Symbols.push_back(pipe);
                    counter++;
                }
            }
            if (StringSymbols.at(i) == ">>") {
                if (i == 0) {
                    Base* lhs = SymbolCommands.at(counter);
                    //cout << "Set LHS" << endl;
                    Base* rhs = nullptr;
                    //cout << "Set RHS" << endl;
                    if ((counter+1) > SymbolCommands.size() - 1) {
                        rhs = nullptr;
                    }
                    else {
                        rhs = SymbolCommands.at(counter + 1);
                    }
                    DoubleOut* DO = new DoubleOut(lhs, rhs);
                    //cout << "Created New And" << endl;
                    this->Symbols.push_back(DO);
                    //cout << "Pushed it in Connectors vector" << endl;
                    counter++;
                }
                else {
                    //cout << "Enters else" << endl;
                    Base* lhs = this->Symbols.at(i - 1);
                    //cout << "Set lhs" << endl;
                    Base* rhs = nullptr;
                    if ((counter + 1) > SymbolCommands.size() - 1) {
                        rhs = nullptr;
                    }
                    else {
                        //cout << "Set rhs" << endl;
                        rhs = SymbolCommands.at(counter + 1);
                    }
                    DoubleOut* DO = new DoubleOut(lhs, rhs);
                    this->Symbols.push_back(DO);
                    //cout << "Hello" << endl;
                    counter++;
                }
            }
        }
        Symbols.at(Symbols.size() - 1)->execute(0, 1);
    }
}
bool SymbolTree::checkFlag() {
    if (this->flag) {
        return true;
    }
    else {
        return false;
    }
}
void SymbolTree::setFlagTrue() {
    this->flag = true;
}