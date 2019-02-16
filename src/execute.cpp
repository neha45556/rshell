#include "execute.h"

using namespace std;

void Execute::printCommand() {
    for (int j = 0; j < CommandLine.size(); j++) {
        CommandLine.at(j)->printCommand();
    }
}
bool Execute::execute() {
    if (CommandLine.size() <= 1) {
        //cout << "Executing CommandLine" << endl;
        for (int i = 0; i < CommandLine.size(); i++) {
           //cout << "Iterating through CommandLine" << endl;
            CommandLine.at(i)->execute();
        }
    }
    else {
        //cout << "Executing on Connectors" << endl;
        for (int i = 0; i < Connectors.size(); i++) {
            //cout << "Iterating through connectors" << endl;
            Connectors.at(i)->execute();
        }
    }
    // cout << "Executing CommandLine" << endl;
    // vector<Command* > dummyVector;
    // for (int j = (CommandLine.size() - 1); j >= 0; j--) {
    //     dummyVector.push_back(CommandLine.at(j));
    // }
    // for (int k = 0; k < dummyVector.size(); k++) {
    //     dummyVector.at(k)->execute();
    // }
    // for (int i = 0; i < CommandLine.size(); i++) {
    //     cout << "Iterating through CommandLine" << endl;
    //     CommandLine.at(i)->execute();
    // }
}
void Execute::printExecute() {
    //cout << "Inside function" << endl;
    for (int i = 0; i < CommandLine.size(); i++) {
        //cout << "Element" << i << ": " << endl;
        CommandLine.at(i)->execute();
    }
}
void Execute::populateExecute(int startOfCommand, int EndOfCommand, Input* VectorInput) {
    //cout << "Enters populate Execute function" << endl;
    //cout << VectorInput->size() << endl;
    for (int i = startOfCommand; i < VectorInput->size(); i++) {
        //cout << "Iterates through VectorInput" << endl;
        size_t foundSemi = VectorInput->at(i).find(";");
        size_t foundOr = VectorInput->at(i).find("|");
        size_t foundAnd = VectorInput->at(i).find("&");
        size_t foundHash = VectorInput->at(i).find("#");
        vector<string > SeperatedVector;
        if (foundHash != string::npos) {
            //cout << "found hash" << endl;
            bool foundQuotes = false;
            for (int y = startOfCommand; y < VectorInput->size(); y++) {
                size_t quotes = VectorInput->at(y).find("\"");
                if (quotes != string::npos) {
                    foundQuotes = true;
                }
            }
            if (foundQuotes) {
                //cout << "Found quotes" << endl;
                for (int x = i + 1; x < VectorInput->size(); x++) {
                    //cout << "Second Iterate through VectorInput" << endl;
                    size_t nextSemi = VectorInput->at(x).find(";");
                    size_t nextOr = VectorInput->at(x).find("|");
                    size_t nextAnd = VectorInput->at(x).find("&");
                    vector<string > SeperatedVector;
                    if (nextSemi != string::npos) {
                        //cout << "found the next semi" << endl;
                        EndOfCommand = x + 1;;
                        for (int ii = startOfCommand; ii < EndOfCommand; ii++) {
                            //cout << VectorInput->at(ii) << endl;
                            string str = VectorInput->at(ii);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = EndOfCommand;
                        populateExecute(startOfCommand, EndOfCommand, VectorInput);
                        break;
                    }
                    else if (nextAnd != string::npos) {
                        //cout << "found the next and" << endl;
                        EndOfCommand = x;
                        for (int ii = startOfCommand; ii < EndOfCommand; ii++) {
                            //cout << VectorInput->at(ii) << endl;
                            string str = VectorInput->at(ii);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = EndOfCommand + 1;
                        //cout << "Start: " << startOfCommand << endl;
                        //cout << "End: " << EndOfCommand << endl;
                        populateExecute(startOfCommand, EndOfCommand, VectorInput);
                        break;
                    }
                    else if (nextOr != string::npos) {
                        //cout << "found the next or" << endl;
                        EndOfCommand = x;
                        for (int ii = startOfCommand; ii < EndOfCommand; ii++) {
                            //cout << VectorInput->at(ii) << endl;
                            string str = VectorInput->at(ii);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = EndOfCommand + 1;
                        populateExecute(startOfCommand, EndOfCommand, VectorInput);
                        break;
                    }
                    else if (x == VectorInput->size() - 1) { 
                        //cout << "End of command second iterate" << endl;
                        for (int ii = startOfCommand; ii < VectorInput->size(); ii++) {
                            //cout << VectorInput->at(ii) << endl;
                            string str = VectorInput->at(ii);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        break;
                    }
                    else {
                        //cout << "Reaches end of second iterate" << endl;
                    }
                }
                break;
            }
        }
        else if (foundSemi != string::npos) {
            //cout << "Found semicolon" << endl;
            bool foundQuotes = false;
            for (int y = startOfCommand; y < VectorInput->size(); y++) {
                size_t quotes = VectorInput->at(y).find("\"");
                if (quotes != string::npos) {
                    foundQuotes = true;
                }
            }
            if (foundQuotes) {
                //cout << "Found quotes" << endl;
                for (int x = i + 1; x < VectorInput->size(); x++) {
                    //cout << "Second Iterate through VectorInput" << endl;
                    size_t nextSemi = VectorInput->at(x).find(";");
                    size_t nextOr = VectorInput->at(x).find("|");
                    size_t nextAnd = VectorInput->at(x).find("&");
                    vector<string > SeperatedVector;
                    if (nextSemi != string::npos) {
                       // cout << "found the next semi" << endl;
                        EndOfCommand = x + 1;
                        for (int ii = startOfCommand; ii < EndOfCommand; ii++) {
                            //cout << VectorInput->at(ii) << endl;
                            string str = VectorInput->at(ii);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = EndOfCommand;
                        populateExecute(startOfCommand, EndOfCommand, VectorInput);
                        break;
                    }
                    else if (nextAnd != string::npos) {
                        //cout << "found the next and" << endl;
                        EndOfCommand = x;
                        for (int ii = startOfCommand; ii < EndOfCommand; ii++) {
                            //cout << VectorInput->at(ii) << endl;
                            string str = VectorInput->at(ii);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = EndOfCommand + 1;
                        //cout << "Start: " << startOfCommand << endl;
                        //cout << "End: " << EndOfCommand << endl;
                        populateExecute(startOfCommand, EndOfCommand, VectorInput);
                        break;
                    }
                    else if (nextOr != string::npos) {
                        //cout << "found the next or" << endl;
                        EndOfCommand = x;
                        for (int ii = startOfCommand; ii < EndOfCommand; ii++) {
                            //cout << VectorInput->at(ii) << endl;
                            string str = VectorInput->at(ii);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = EndOfCommand + 1;
                        populateExecute(startOfCommand, EndOfCommand, VectorInput);
                        break;
                    }
                    else if (x == VectorInput->size() - 1) { 
                        //cout << "End of command second iterate" << endl;
                        for (int ii = startOfCommand; ii < VectorInput->size(); ii++) {
                            //cout << VectorInput->at(ii) << endl;
                            string str = VectorInput->at(ii);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        break;
                    }
                    else {
                        //cout << "Reaches end of second iterate" << endl;
                    }
                }
                break;
            }
            else {
                EndOfCommand = i + 1;
                vector<string > SeperatedVector;
                for (int j = startOfCommand; j < EndOfCommand; j++) {
                    //cout << VectorInput->at(j) << endl;
                    //cout << VectorInput->at(j) << endl;
                    string str = VectorInput->at(j);
                    str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                    SeperatedVector.push_back(str);
                }
                SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                Command* command = new Command(SeperatedVector);
                //cout << "Created a new command" << endl;
                this->CommandLine.push_back(command);
                //cout << "Pushed into vector new command" << endl;
                startOfCommand = EndOfCommand;
                populateExecute(startOfCommand, EndOfCommand, VectorInput);
                //cout << "Exited the recursive statement" << endl;
                break;
            }
        }
        else if (foundOr != string::npos) {
            //cout << "Found or" << endl;
            bool foundQuotes = false;
            for (int y = startOfCommand; y < VectorInput->size(); y++) {
                size_t quotes = VectorInput->at(y).find("\"");
                if (quotes != string::npos) {
                    foundQuotes = true;
                }
            }
            if (foundQuotes) {
                //cout << "Found quotes" << endl;
                for (int x = i + 1; x < VectorInput->size(); x++) {
                    //cout << "Second Iterate through VectorInput" << endl;
                    size_t nextSemi = VectorInput->at(x).find(";");
                    size_t nextOr = VectorInput->at(x).find("|");
                    size_t nextAnd = VectorInput->at(x).find("&");
                    vector<string > SeperatedVector;
                    if (nextSemi != string::npos) {
                        // << "found the next semi" << endl;
                        EndOfCommand = x + 1;
                        for (int ii = startOfCommand; ii < EndOfCommand; ii++) {
                            //cout << VectorInput->at(ii) << endl;
                            string str = VectorInput->at(ii);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = EndOfCommand;
                        populateExecute(startOfCommand, EndOfCommand, VectorInput);
                        break;
                    }
                    else if (nextAnd != string::npos) {
                        //cout << "found the next and" << endl;
                        EndOfCommand = x;
                        for (int ii = startOfCommand; ii < EndOfCommand; ii++) {
                            //cout << VectorInput->at(ii) << endl;
                            string str = VectorInput->at(ii);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = EndOfCommand + 1;
                        //cout << "Start: " << startOfCommand << endl;
                        //cout << "End: " << EndOfCommand << endl;
                        populateExecute(startOfCommand, EndOfCommand, VectorInput);
                        break;
                    }
                    else if (nextOr != string::npos) {
                        //cout << "found the next or" << endl;
                        EndOfCommand = x;
                        for (int ii = startOfCommand; ii < EndOfCommand; ii++) {
                            //cout << VectorInput->at(ii) << endl;
                            string str = VectorInput->at(ii);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = EndOfCommand + 1;
                        populateExecute(startOfCommand, EndOfCommand, VectorInput);
                        break;
                    }
                    else if (x == VectorInput->size() - 1) { 
                        //cout << "End of command second iterate" << endl;
                        for (int ii = startOfCommand; ii < VectorInput->size(); ii++) {
                            //cout << VectorInput->at(ii) << endl;
                            string str = VectorInput->at(ii);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        break;
                    }
                    else {
                        //cout << "Reaches end of second iterate" << endl;
                    }
                }
                break;
            }
            else {
                EndOfCommand = i;
                vector<string > SeperatedVector;
                for (int k = startOfCommand; k < EndOfCommand; k++) {
                    //cout << VectorInput->at(k) << endl;
                    string str = VectorInput->at(k);
                    str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                    SeperatedVector.push_back(str);
                }
                Command* command = new Command(SeperatedVector);
                this->CommandLine.push_back(command);
                startOfCommand = EndOfCommand + 1;
                //cout << "Pushed in one command" << endl;
                populateExecute(startOfCommand, EndOfCommand, VectorInput);
                break;
            }
        }
        else if (foundAnd != string::npos) {;
            //cout << "Found and" << endl;
            bool foundQuotes = false;
            for (int y = startOfCommand; y < VectorInput->size(); y++) {
                size_t quotes = VectorInput->at(y).find("\"");
                if (quotes != string::npos) {
                    foundQuotes = true;
                }
            }
            if (foundQuotes) {
                //cout << "Found quotes" << endl;
                for (int x = i + 1; x < VectorInput->size(); x++) {
                    //cout << "Second Iterate through VectorInput" << endl;
                    size_t nextSemi = VectorInput->at(x).find(";");
                    size_t nextOr = VectorInput->at(x).find("|");
                    size_t nextAnd = VectorInput->at(x).find("&");
                    vector<string > SeperatedVector;
                    if (nextSemi != string::npos) {
                        //cout << "found the next semi" << endl;
                        EndOfCommand = x + 1;
                        for (int ii = startOfCommand; ii < EndOfCommand; ii++) {
                            //cout << VectorInput->at(ii) << endl;
                            string str = VectorInput->at(ii);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = EndOfCommand;
                        populateExecute(startOfCommand, EndOfCommand, VectorInput);
                        break;
                    }
                    else if (nextAnd != string::npos) {
                        //cout << "found the next and" << endl;
                        EndOfCommand = x;
                        for (int ii = startOfCommand; ii < EndOfCommand; ii++) {
                            //cout << VectorInput->at(ii) << endl;
                            string str = VectorInput->at(ii);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);;
                        }
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = EndOfCommand + 1;
                        //cout << "Start: " << startOfCommand << endl;
                        //cout << "End: " << EndOfCommand << endl;
                        populateExecute(startOfCommand, EndOfCommand, VectorInput);
                        break;
                    }
                    else if (nextOr != string::npos) {
                        //cout << "found the next or" << endl;
                        EndOfCommand = x;
                        for (int ii = startOfCommand; ii < EndOfCommand; ii++) {
                            //cout << VectorInput->at(ii) << endl;
                            string str = VectorInput->at(ii);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = EndOfCommand + 1;
                        populateExecute(startOfCommand, EndOfCommand, VectorInput);
                        break;
                    }
                    else if (x == VectorInput->size() - 1) { 
                        //cout << "End of command second iterate" << endl;
                        for (int ii = startOfCommand; ii < VectorInput->size(); ii++) {
                            //cout << VectorInput->at(ii) << endl;
                            string str = VectorInput->at(ii);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        break;
                    }
                    else {
                        //cout << "Reaches end of second iterate" << endl;
                    }
                }
                break;
            }
            else {
                //cout << "After break" << endl;
                EndOfCommand = i;
                // cout << startOfCommand << " " << EndOfCommand << endl;
                vector<string > SeperatedVector;
                for (int l = startOfCommand; l < EndOfCommand; l++) {
                    //cout << VectorInput->at(l) << endl;
                    string str = VectorInput->at(l);
                    str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                    SeperatedVector.push_back(str);
                }
                Command* command = new Command(SeperatedVector);
                this->CommandLine.push_back(command);
                startOfCommand = EndOfCommand + 1;
                //cout << "Pushed in one command" << endl;
                populateExecute(startOfCommand, EndOfCommand, VectorInput);
                break;
            }
        }
        else if (i == VectorInput->size() - 1) {
            //cout << "Reached the end of the Vector" << endl;
            vector<string > SeperatedVector;
            for(int m = startOfCommand; m < VectorInput->size(); m++) {
                //cout << VectorInput->at(m) << endl;
                string str = VectorInput->at(m);
                str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                SeperatedVector.push_back(str);
            }
            Command* command = new Command(SeperatedVector);
            this->CommandLine.push_back(command);
            //cout << "Pushed in one command" << endl;
            break;
            //cout << "Pushed in very last command" << endl;
        }
        else {
            //cout << "Reaches else" << endl;
        }
    }
    for (int j = 0; j < CommandLine.size(); j++) {
        //cout << "Looking for hashtags" << endl;
        bool foundHashtag = CommandLine.at(j)->findHashtag();
        if (foundHashtag) {
            //cout << "Found hashtag" << endl;
            for (int k = CommandLine.size() - 1; k > j; k--) {
                //cout << "Popback a command" << endl;
                CommandLine.pop_back();
            }
            // cout << j << endl;
            CommandLine.at(j)->deleteHashtag();
            //cout << "Exits deletehashtag" << endl;
            break;
        }
    }
}
void Execute::populateExecuteConnectors(Input* ConnectorVector) {
    // << "Enter populateConnectors" << endl;
    // for (int a = 0; a < ConnectorVector->ConSize(); a++) {
    //     cout << ConnectorVector->ConAt(a) << endl;
    // }
    //cout << "----------------" << endl;
    if (ConnectorVector->ConSize() > 2) {
        for (int b = 0; b < ConnectorVector->ConSize(); b++) {
            if (ConnectorVector->ConAt(b) == "&&") {
                if ((ConnectorVector->ConAt(b-1)) == "\"" && ConnectorVector->ConAt(b+1) == "\"") {
                    ConnectorVector->ConErase(b-1, b+1);
                }
            }
            else if (ConnectorVector->ConAt(b) == "||") {
                if ((ConnectorVector->ConAt(b-1)) == "\"" && ConnectorVector->ConAt(b+1) == "\"") {
                    ConnectorVector->ConErase(b-1, b+1);
                } 
            }
            else if (ConnectorVector->ConAt(b) == ";") {
                if ((ConnectorVector->ConAt(b-1)) == "\"" && ConnectorVector->ConAt(b+1) == "\"") {
                    ConnectorVector->ConErase(b-1, b+1);
                }
            }
            // else if (ConnectorVector->ConAt(b) == "#") {
            //     cout << "Found the #" << endl;
            //     if ((ConnectorVector->ConAt(b-1)) == "\"" && ConnectorVector->ConAt(b+1) == "\"") {
            //         ConnectorVector->ConErase(b -1, b+1);
            //         cout << "Erased" << endl;
            //     }
            // }
        }
        // cout << "----------------" << endl;
        // for (int a = 0; a < ConnectorVector->ConSize(); a++) {
        //     cout << ConnectorVector->ConAt(a) << endl;
        // }
        // cout << CommandLine.size() << endl;
        // cout << ConnectorVector->ConSize() << endl;
    }
    int counter = 0;
    for (int i = 0; i < ConnectorVector->ConSize(); i++) {
//cout << "Iterates through vector" << endl;
        if (ConnectorVector->ConAt(i) == ";") {
            //cout << "Found semicolon" << endl;
            Base* lhs = CommandLine.at(counter);
            Base* rhs = nullptr;
            if ((counter+1) > CommandLine.size() - 1) {
                rhs = nullptr;
            }
            else {
                rhs = CommandLine.at(counter + 1);
            }
            Semicolon* semi = new Semicolon(lhs, rhs);
            this->Connectors.push_back(semi);
            counter++;
        }
        else if (ConnectorVector->ConAt(i) == "||") {
            //cout << "Found OR" << endl;
            Base* lhs = CommandLine.at(counter);
            Base* rhs = nullptr;
            if ((counter+1) > CommandLine.size() - 1) {
                rhs = nullptr;
            }
            else {
                rhs = CommandLine.at(counter + 1);
            }
            Or* OR = new Or(lhs, rhs);
            this->Connectors.push_back(OR);
            counter++;
        }
        else if (ConnectorVector->ConAt(i) == "&&") {
            //cout << "Found AND" << endl;
            Base* lhs = CommandLine.at(counter);
            //cout << "Set LHS" << endl;
            Base* rhs = nullptr;
            //cout << "Set RHS" << endl;
            if ((counter+1) > CommandLine.size() - 1) {
                rhs = nullptr;
            }
            else {
                rhs = CommandLine.at(counter + 1);
            }
            And* AND = new And(lhs, rhs);
            //cout << "Created New And" << endl;
            this->Connectors.push_back(AND);
            //cout << "Pushed it in Connectors vector" << endl;
            counter++;
        }
    }
    //cout << "Finished populating connectors" << endl;
}
bool Execute::checkFlag() {
    for(int i = 0; i < CommandLine.size(); i++) {
        this->CommandLine.at(i)->checkFlag();
    } 
}
