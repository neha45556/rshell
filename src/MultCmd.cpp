#include "MultCmd.h"

using namespace std;

void MultCmd::addConnector(string connector) {
    this->StringConnectors.push_back(connector);
}
void MultCmd::addCommand(Base* command) {
    this->CommandLine.push_back(command);
}
void MultCmd::addManyCommands(int startOfCommand, int endOfCommand, vector<string> SeperatedVector) {
    for (int i = 0; i < SeperatedVector.size(); i++) {
        size_t foundSemi = SeperatedVector.at(i).find(";");
        size_t foundOr = SeperatedVector.at(i).find("|");
        size_t foundAnd = SeperatedVector.at(i).find("&");
        vector<string> SingleVector;
        if (foundSemi != string::npos) {
            bool foundQuotes = false;
            int endOfQuotes = 0;
            for (int j = i + 1; j < SeperatedVector.size(); j++) {
                size_t quotesAfterSemi = SeperatedVector.at(j).find("\"");
                if (quotesAfterSemi != string::npos) {
                   // cout << "quotes = true" << endl;
                    foundQuotes = true;
                    endOfQuotes = j;
                    break;
                }
            }
            if (!foundQuotes) {
                //cout << "No quotes exist" << endl;
                //cout << "Finds semi" << endl;
                endOfCommand = i + 1;
                //cout << "Sets new EC" << endl;
                for (int j = startOfCommand; j < endOfCommand; j++) {
                    //cout << "Input: " << SeperatedVector.at(j);
                    string str = SeperatedVector.at(j);
                    // str.erase(std::remove(str.begin(), str.end(), '\"'));
                    SingleVector.push_back(str);
                }
                // for (int z = 0; z < SingleVector.size(); z++) {
                //     cout << SingleVector.at(z) << endl;
                // }
                //cout << "Creates new vector" << endl;
                startOfCommand = endOfCommand;
                SingleVector.at(SingleVector.size()-1).pop_back();
                Command* command = new Command(SingleVector);
                CommandLine.push_back(command); 
                StringConnectors.push_back(";");
                addManyCommands(startOfCommand, endOfCommand, SeperatedVector);
                break;
            }
            else {
                //cout << "Quotes do exist" << endl;
                //if (the next element or current element equals connectors)                
                for (int k = endOfQuotes; k < SeperatedVector.size(); k++) {
                    size_t foundSemi2 = SeperatedVector.at(k).find(";");
                    size_t foundAnd2 = SeperatedVector.at(k).find("&&");
                    size_t foundOr2 = SeperatedVector.at(k).find("||");
                    if (foundSemi2 != string::npos) {
                        //cout << "Finds next semi" << endl;
                        endOfCommand = k + 1;
                        for (int k = startOfCommand; k < endOfCommand; k++) {
                            //cout << "Insert: " << SeperatedVector.at(k) << endl;
                            string str = SeperatedVector.at(k);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                            SingleVector.push_back(str);
                        }
                        // for (int z = 0; z < SingleVector.size(); z++) {
                        //     cout << SingleVector.at(z) << endl;
                        // }
                        startOfCommand = endOfCommand;
                        SingleVector.at(SingleVector.size()-1).pop_back();
                        Command* command = new Command(SingleVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = endOfCommand;
                        StringConnectors.push_back(";");
                        cout << endOfCommand << " " << startOfCommand << endl;
                        addManyCommands(startOfCommand, endOfCommand, SeperatedVector);
                        break;
                    }
                    else if (foundAnd2 != string::npos) {
                        //cout << "Finds next &&" << endl;
                        endOfCommand = k + 1;
                        for (int k = startOfCommand; k < endOfCommand - 1; k++) {
                           // cout << "Insert: " << SeperatedVector.at(k) << endl;
                            string str = SeperatedVector.at(k);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                            SingleVector.push_back(str);
                        }
                        // for (int z = 0; z < SingleVector.size(); z++) {
                        //     cout << SingleVector.at(z) << endl;
                        // }
                        startOfCommand = endOfCommand;
                        //SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                        Command* command = new Command(SingleVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = endOfCommand;
                        StringConnectors.push_back("&&");
                        cout << endOfCommand << " " << startOfCommand << endl;
                        addManyCommands(startOfCommand, endOfCommand, SeperatedVector);
                        break;
                    }
                    else if (foundOr2 != string::npos) {
                        //cout << "Finds next ||" << endl;
                        endOfCommand = k + 1;
                        for (int k = startOfCommand; k < endOfCommand - 1; k++) {
                            //cout << "Insert: " << SeperatedVector.at(k) << endl;
                            string str = SeperatedVector.at(k);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                            SingleVector.push_back(str);
                        }
                        // for (int z = 0; z < SingleVector.size(); z++) {
                        //     cout << SingleVector.at(z) << endl;
                        // }
                        startOfCommand = endOfCommand;
                        //SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                        Command* command = new Command(SingleVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = endOfCommand;
                        StringConnectors.push_back("||");
                        //cout << endOfCommand << " " << startOfCommand << endl;
                        addManyCommands(startOfCommand, endOfCommand, SeperatedVector);
                        break;
                    }
                    else if (k == SeperatedVector.size()- 1) {
                        //cout << "Reached the end of the Vector" << endl;
                        //vector<string > SeperatedVector;
                        for(int m = startOfCommand; m < SeperatedVector.size(); m++) {
                            //cout << SeperatedVector.at(m) << endl;
                            string str = SeperatedVector.at(m);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SingleVector.push_back(str);
                        }
                        // for (int z = 0; z < SingleVector.size(); z++) {
                        //     cout << SingleVector.at(z) << endl;
                        // }
                        Command* command = new Command(SingleVector);
                        this->CommandLine.push_back(command);
                        //cout << "Pushed in one command" << endl;
                        break; 
                    }
                    else {
                        
                    }
                    // startOfCommand = j;
                    // endOfCommand = startOfCommand;
                    // parse(startOfCommand, endOfCommand, VectorInput);
                    // break;
                }
            }
            break;
        }
    }
}

bool MultCmd::checkFlag() {
    return this->CommandLine.at(CommandLine.size() - 1)->checkFlag();
}

bool MultCmd::execute(int in, int out) {
    //cout << "Mult Commands" << endl;
    if (this->StringConnectors.empty()) {
        //cout << "No connectors" << endl;
        for (int i = 0; i < CommandLine.size(); i++) {
            CommandLine.at(i)->execute(0, 1);
        }    
    }
    else {
        int counter = 0;
        // cout << StringConnectors.size() << endl;
        // cout << "-------------------------- -----------------------------------" << endl;
        // for (int a = 0; a < StringConnectors.size(); a++) {
        //     cout << StringConnectors.at(a) << endl;
        // }
        // cout << "-------------------------------------------------------------" << endl;
        for (int i = 0; i < StringConnectors.size(); i++) {
            //cout << "Connectors exist" << endl;
            if (StringConnectors.at(i) == ";") {
                //cout << "Found SEMI" << endl;
                Base* lhs = CommandLine.at(counter);
                Base* rhs = nullptr;
                if ((counter+1) > CommandLine.size() - 1) {
                    //cout << "SET RHS TO NULL" << endl;
                    rhs = nullptr;
                }
                else {
                    //cout << "SET RHS" << endl;
                    rhs = CommandLine.at(counter + 1);
                }
                Semicolon* semi = new Semicolon(lhs, rhs);
                this->Connectors.push_back(semi);
                counter++;
            }
            else if (StringConnectors.at(i) == "||") {
                //cout << "Found OR" << endl;
                Base* lhs = CommandLine.at(counter);
                Base* rhs = nullptr;
                if ((counter+1) > CommandLine.size() - 1) {
                    //cout << "SET RHS TO NULL" << endl;
                    rhs = nullptr;
                }
                else {
                    //cout << "SET RHS" << endl;
                    rhs = CommandLine.at(counter + 1);
                }
                Or* OR = new Or(lhs, rhs);
                this->Connectors.push_back(OR);
                counter++;
            }
            else if (StringConnectors.at(i) == "&&") {
                //cout << "Found AND" << endl;
                Base* lhs = CommandLine.at(counter);
                //cout << "Set LHS" << endl;
                Base* rhs = nullptr;
                if ((counter+1) > CommandLine.size() - 1) {
                    //cout << "SET RHS TO NULL" << endl;
                    rhs = nullptr;
                }
                else {
                    //cout << "SET RHS" << endl;
                    rhs = CommandLine.at(counter + 1);
                }
                And* AND = new And(lhs, rhs);
                //cout << "Created New And" << endl;
                this->Connectors.push_back(AND);
                //cout << "Pushed it in Connectors vector" << endl;
                counter++;
            }
        }
        for (int j = 0; j < this->Connectors.size(); ++j) {
            //cout << "Executing on multCmd connectors" << endl;
            this->Connectors.at(j)->execute(0, 1);
            
        }
    }
}