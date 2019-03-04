#include "FullCommand.h"

using namespace std;

void FullCommand::parse(int startOfCommand, int endOfCommand, Input* VectorInput) {
    // cout << "Enters populate Execute function" << endl;
    //cout << VectorInput->size() << endl;
    for (int i = startOfCommand; i < VectorInput->size(); i++) {
        //cout << "Iterates through VectorInput" << endl;
        size_t foundParen = VectorInput->at(i).find("(");
        size_t foundSemi = VectorInput->at(i).find(";");
        size_t foundOr = VectorInput->at(i).find("|");
        size_t foundAnd = VectorInput->at(i).find("&");
        size_t foundQuotes = VectorInput->at(i).find("\"");
        // size_t foundHash = VectorInput->at(i).find("#");
        vector<string > SeperatedVector;
        if (foundParen != string::npos) {
            // cout << "Found Paren" << endl;
            // cout << "Quotes exist in paren" << endl;
            // Paren* paren = new Paren();
            // MultCmd* mult = new MultCmd();
            // startOfCommand = i;
            // bool foundRightParen = false;
            // // string checkIfDubQuotes = VectorInput->at(beginOfQuotes);
            // // size_t n = std::count(checkIfDubQuotes.begin(), checkIfDubQuotes.end(), '"');
            // for (int k = beginOfQuotes; k < VectorInput->size(); k++) {
            //     string beginOfQuotes = VectorInput->at(beginOfQuotes);
            //     size_t n = std::count(checkIfDubQuotes.begin(), checkIfDubQuotes.end(), '"');
            //     if (n > 1) {
            //         cout << "hello" << endl;
            //     }
            //     else {
            //         for (int a = beginOfQuotes + 1; a < VectorInput->size(); a++) {
            //             size_t endOfQuotes = VectorInput->at(k).find("\"");
            //         }
            //     }
            //     if (endOfQuotes != string::npos) {
            //         for (int m = a; m < VectorInput->size(); m++) {
            //             vector<string> SingleVector;
            //             if (m == VectorInput->size() - 1) {
            //                 for (int n = m; n < VectorInput->size(); n++) {
            //                     cout << "Input: " << VectorInput->at(m) << endl;
            //                     string str = VectorInput->at(m);
            //                     str.erase(std::remove(str.begin(), str.end(), '('), str.end());
            //                     str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
            //                     str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
            //                     SingleVector.push_back(str);
            //                 }
            //                 for (int z = 0; z < SingleVector.size(); z++) {
            //                     cout << SingleVector.at(z) << endl;
            //                 }
            //                 Command* command = new Command(SingleVector);
            //                 mult->addCommand(command);
            //                 paren->addCommand(mult);
            //                 this->CommandLine.push_back(paren);
            //                 break;
            //             }
            //             // else if () {
            //             //     cout << "Hello" << endl;
            //             // }
            //         }
            //     }
            //     else {
                    
            //     }
            // }
            Paren* paren = new Paren();
            MultCmd* mult = new MultCmd();
            startOfCommand = i;
            bool foundRightParen = false;
            for (int j = startOfCommand; j < VectorInput->size(); j++) { 
                // cout << "Searching in paren" << endl;
                size_t parenQuotes = VectorInput->at(j).find("\""); 
                size_t rightParen = VectorInput->at(j).find(")");
                size_t parenSemi = VectorInput->at(j).find(";");
                size_t parenOr = VectorInput->at(j).find("||");
                size_t parenAnd = VectorInput->at(j).find("&&");
                // if (parenQuotes != string::npos) {
                //     int endOfQuotes = 0;
                //     for (int k = j; k < VectorInput->size(); k++) {
                //         size_t quotePair = VectorInput->at(k).find("\""); 
                //         if (quotePair != string::npos) {
                //             endOfQuotes = k;
                //         }
                //     }
                //     if (VectorInput->at(endOfQuotes).find(")")) {
                        
                //     }
                    
                //     size_t parenSemi = VectorInput->at(endOfQuotes).find(";")
                //     size_t parenOr = VectorInput->at(endOfQuotes).find("||")
                //     size_t parenAnd = VectorInput->at(endOfQuotes).find("&&")
                //     for (int m = endOfQuotes; m < VectorInput->size(); m++) {
                //         if (parenSemi != string::npos) {
                            
                //         }
                //         else if (parenOr != string::npos) {
                            
                //         }
                //         else if (parenAnd != string::npos) {
                            
                //         }
                //         else {
                //         }
                //     }
                    
                // }
                // if (leftParen != string::npos) {
                //     Paren* paren2 = new Paren();
                //     MultCmd* mult2 = new Mult();
                //     bool foundRightParen2 = false;
                //     for (int k = j; k < VectorInput->size(); k++) {
                //         size_t rightParen = VectorInput->at(k).find(")");
                //         size_t parenSemi = VectorInput->at(j).find(";");
                //         size_t parenOr = VectorInput->at(j).find("||");
                //         size_t parenAnd = VectorInput->at(j).find("&&");
                //         if (rightParen != string::npos) {
                            
                //         }
                //         if (parenSemi != string::npos) {
                //             if (foundRightParen2) {
                //                 break;
                //             }
                //             cout << "Found semi" << endl;
                //             mult2->addConnector(";");
                //             vector<string> SingleVector2;
                //             for (int kk = startOfCommand; kk <= k; kk++) {
                //                 cout << "Input: " << VectorInput->at(kk) << endl;
                //                 string str = VectorInput->at(kk);
                //                 str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                //                 str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                //                 SingleVector.push_back(str);
                //             }
                //             startOfCommand = k + 1;
                //             //cout << startOfCommand << endl;
                //             SingleVector2.at(SingleVector2.size()-1).pop_back();
                //             Command* command = new Command(SingleVector2);
                //             mult2->addCommand(command);
                //         }
                //         if (parenOr != string::npos) {
                //             if (foundRightParen) {
                //                 cout << "Found paren already must break" << endl;
                //                 break;
                //             }
                //             cout << "Found Or" << endl;
                //             mult->addConnector("||");
                //             vector<string> SingleVector;
                //             for (int kk = startOfCommand; kk < k; kk++) {
                //                 cout << "Input: " << VectorInput->at(kk) << endl;
                //                 string str = VectorInput->at(kk);
                //                 str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                //                 str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                //                 SingleVector.push_back(str);
                //             }
                //             startOfCommand = k;
                //             Command* command = new Command(SingleVector2);
                //             mult->addCommand(command);
                //         }
                //         if (parenAnd != string::npos) {
                //             if (foundRightParen) {
                //                 break;
                //             }
                //             cout << "Found And" << endl;
                //             mult->addConnector("&&");
                //             vector<string> SingleVector2;
                //             for (int kk = startOfCommand; kk < k; kk++) {
                //                 cout << "Input: " << VectorInput->at(k) << endl;
                //                 string str = VectorInput->at(kk);
                //                 str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                //                 str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                //                 SingleVector2.push_back(str);
                //             }
                //             for (int z = 0; z < SingleVector2.size(); z++) {
                //                 cout << SingleVector2.at(z) << endl;;
                //             }
                //             startOfCommand = k;
                //             Command* command = new Command(SingleVector2);
                //             mult->addCommand(command);
                //         }
                //     }
                // }
                if (rightParen != string::npos) { 
                    // cout << "Found right paren" << endl;
                    if (j == VectorInput->size() - 1) {
                        for (int k = startOfCommand; k < VectorInput->size(); k++) {
                            // cout << "Input: " << VectorInput->at(k) << endl;
                            string str = VectorInput->at(k);
                            str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                            str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                            SeperatedVector.push_back(str);
                        }
                        Command* newcommand = new Command(SeperatedVector);
                        mult->addCommand(newcommand);
                        paren->addCommand(mult);
                        CommandLine.push_back(paren);
                        foundRightParen = true;
                        break;
                    }
                    else {
                        // cout << "More exists post parenthesis" << endl;
                        for (int m = j; m < VectorInput->size(); ++m) {
                            // cout << "Searching past parenthesis" << endl;
                            size_t nextSemi = VectorInput->at(m).find(";");
                            size_t nextOr = VectorInput->at(m).find("||");
                            size_t nextAnd = VectorInput->at(m).find("&&");
                            if (nextSemi != string::npos) {
                                // cout << "Finds next semi" << endl;
                                endOfCommand = m + 1;
                                for (int n = startOfCommand; n < endOfCommand; n++) {
                                    // cout << "Insert: " << VectorInput->at(n) << endl;
                                    string str = VectorInput->at(n);
                                    str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                    str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                    SeperatedVector.push_back(str);
                                }
                                SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                                // for (int z = 0; z < SeperatedVector.size(); z++) {
                                //     cout << SeperatedVector.at(z) << endl;
                                // }
                                Command* command = new Command(SeperatedVector);
                                mult->addCommand(command);
                                paren->addCommand(mult);
                                startOfCommand = endOfCommand;
                                this->StringConnectors.push_back(";");
                                this->CommandLine.push_back(paren);
                                // cout << endOfCommand << " " << startOfCommand << endl;
                                parse(startOfCommand, endOfCommand, VectorInput);
                                foundRightParen = true;
                                break;
                            }
                            else if (nextOr != string::npos) {
                                // cout << "Finds next Or" << endl;
                                endOfCommand = m;
                                for (int n = startOfCommand; n < endOfCommand; n++) {
                                    // cout << "Insert: " << VectorInput->at(n) << endl;
                                    string str = VectorInput->at(n);
                                    str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                    str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                    SeperatedVector.push_back(str);
                                }
                                // for (int z = 0; z < SeperatedVector.size(); z++) {
                                //     cout << SeperatedVector.at(z) << endl;
                                // }
                                Command* command = new Command(SeperatedVector);
                                mult->addCommand(command);
                                paren->addCommand(mult);
                                startOfCommand = endOfCommand + 1;
                                this->StringConnectors.push_back("||");
                                this->CommandLine.push_back(paren);
                                // cout << endOfCommand << " " << startOfCommand << endl;
                                foundRightParen = true;
                                parse(startOfCommand, endOfCommand, VectorInput);
                                break;
                            }
                            else if (nextAnd != string::npos) {
                                // cout << "Finds next And" << endl;
                                endOfCommand = m;
                                for (int n = startOfCommand; n < endOfCommand; n++) {
                                    // cout << "Insert: " << VectorInput->at(n) << endl;
                                    string str = VectorInput->at(n);
                                    str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                    str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                    SeperatedVector.push_back(str);
                                }
                                // for (int z = 0; z < SeperatedVector.size(); z++) {
                                //     cout << SeperatedVector.at(z) << endl;
                                // }
                                Command* command = new Command(SeperatedVector);
                                mult->addCommand(command);
                                paren->addCommand(mult);
                                startOfCommand = endOfCommand + 1;
                                this->StringConnectors.push_back("&&");
                                this->CommandLine.push_back(paren);
                                // cout << endOfCommand << " " << startOfCommand << endl;
                                foundRightParen = true;
                                parse(startOfCommand, endOfCommand, VectorInput);
                                break;
                            }
                        }
                    }
                }
                if (parenSemi != string::npos) {
                    if (foundRightParen) {
                        break;
                    }
                    bool checkQuotes = false;
                    int beginOfQuotes = 0;
                    for (int a = startOfCommand; a <= j; a++) {
                        size_t quotesInParen = VectorInput->at(a).find("\"");
                        if (quotesInParen != string::npos) {
                            // cout << "Quotes exist" << endl;
                            checkQuotes = true;
                            beginOfQuotes = a;
                            break;
                        }
                    }
                    if (checkQuotes) {
                        // cout << "START OF COMMAND = " << startOfCommand << endl;
                        for (int ii = beginOfQuotes + 1; ii < VectorInput->size(); ii++) {
                            size_t endOfQuotes = VectorInput->at(ii).find("\"");
                            if (endOfQuotes != string::npos) {
                                for (int jj = ii; jj < VectorInput->size(); jj++) {
                                    size_t nextRightParen = VectorInput->at(jj).find(")");
                                    size_t nextSemi = VectorInput->at(jj).find(";");
                                    size_t nextAnd = VectorInput->at(jj).find("&&");
                                    size_t nextOr = VectorInput->at(jj).find("||");
                                    if (nextRightParen != string::npos) {
                                        // cout << "Found right paren" << endl;
                                        if (jj == VectorInput->size() - 1) {
                                            // cout << "End of vector" << endl;
                                            for (int k = startOfCommand; k < VectorInput->size(); k++) {
                                                // cout << "Input: " << VectorInput->at(k) << endl;
                                                string str = VectorInput->at(k);
                                                str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                                str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                                str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                                                SeperatedVector.push_back(str);
                                            }
                                            Command* newcommand = new Command(SeperatedVector);
                                            mult->addCommand(newcommand);
                                            paren->addCommand(mult);
                                            CommandLine.push_back(paren);
                                            foundRightParen = true;
                                            break;
                                        }
                                        else {
                                            // cout << "More exists post parenthesis" << endl;
                                            for (int m = jj; m < VectorInput->size(); ++m) {
                                                // cout << "Searching past parenthesis" << endl;
                                                size_t nextSemi = VectorInput->at(m).find(";");
                                                size_t nextOr = VectorInput->at(m).find("||");
                                                size_t nextAnd = VectorInput->at(m).find("&&");
                                                if (nextSemi != string::npos) {
                                                    if (foundRightParen) {
                                                        // cout << "Must break" << endl;
                                                        break;
                                                    }
                                                    // cout << "Finds next semi" << endl;
                                                    endOfCommand = m + 1;
                                                    for (int n = startOfCommand; n < endOfCommand; n++) {
                                                        // cout << "Insert: " << VectorInput->at(n) << endl;
                                                        string str = VectorInput->at(n);
                                                        str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                                        SeperatedVector.push_back(str);
                                                    }
                                                    SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                                                    // for (int z = 0; z < SeperatedVector.size(); z++) {
                                                    //     cout << SeperatedVector.at(z) << endl;
                                                    // }
                                                    Command* command = new Command(SeperatedVector);
                                                    mult->addCommand(command);
                                                    paren->addCommand(mult);
                                                    startOfCommand = endOfCommand;
                                                    this->StringConnectors.push_back(";");
                                                    this->CommandLine.push_back(paren);
                                                    // cout << endOfCommand << " " << startOfCommand << endl;
                                                    parse(startOfCommand, endOfCommand, VectorInput);
                                                    foundRightParen = true;
                                                    break;
                                                }
                                                else if (nextOr != string::npos) {
                                                    if (foundRightParen) {
                                                        // cout << "Must break" << endl;
                                                        break;
                                                    }
                                                    // cout << "Finds next Or" << endl;
                                                    endOfCommand = m;
                                                    for (int n = startOfCommand; n < endOfCommand; n++) {
                                                        // cout << "Insert: " << VectorInput->at(n) << endl;
                                                        string str = VectorInput->at(n);
                                                        str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                                        SeperatedVector.push_back(str);
                                                    }
                                                    // for (int z = 0; z < SeperatedVector.size(); z++) {
                                                        // cout << SeperatedVector.at(z) << endl;
                                                    // }
                                                    Command* command = new Command(SeperatedVector);
                                                    mult->addCommand(command);
                                                    paren->addCommand(mult);
                                                    startOfCommand = endOfCommand + 1;
                                                    this->StringConnectors.push_back("||");
                                                    this->CommandLine.push_back(paren);
                                                    // cout << endOfCommand << " " << startOfCommand << endl;
                                                    foundRightParen = true;
                                                    parse(startOfCommand, endOfCommand, VectorInput);
                                                    break;
                                                }
                                                else if (nextAnd != string::npos) {
                                                    if (foundRightParen) {
                                                        // cout << "Must break" << endl;
                                                        break;
                                                    }
                                                    // cout << "Finds next And" << endl;
                                                    endOfCommand = m;
                                                    for (int n = startOfCommand; n < endOfCommand; n++) {
                                                        // cout << "Insert: " << VectorInput->at(n) << endl;
                                                        string str = VectorInput->at(n);
                                                        str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                                        SeperatedVector.push_back(str);
                                                    }
                                                    // for (int z = 0; z < SeperatedVector.size(); z++) {
                                                    //     cout << SeperatedVector.at(z) << endl;
                                                    // }
                                                    Command* command = new Command(SeperatedVector);
                                                    mult->addCommand(command);
                                                    paren->addCommand(mult);
                                                    startOfCommand = endOfCommand + 1;
                                                    this->StringConnectors.push_back("&&");
                                                    this->CommandLine.push_back(paren);
                                                    // cout << endOfCommand << " " << startOfCommand << endl;
                                                    foundRightParen = true;
                                                    parse(startOfCommand, endOfCommand, VectorInput);
                                                    break;
                                                }
                                            }
                                            //break;
                                        }
                                        break;
                                    }
                                    if (nextSemi != string::npos) {
                                        if (foundRightParen) {
                                            // cout << "Must break" << endl;
                                            break;
                                        }
                                        // cout << "Found semi" << endl;
                                        mult->addConnector(";");
                                        vector<string> SingleVector;
                                        for (int kk = startOfCommand; kk <= jj; kk++) {
                                            // cout << "Input: " << VectorInput->at(kk) << endl;
                                            string str = VectorInput->at(kk);
                                            str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
                                            SingleVector.push_back(str);
                                        }
                                        startOfCommand = jj + 1;
                                        // cout << startOfCommand << endl;
                                        SingleVector.at(SingleVector.size()-1).pop_back();
                                        Command* command = new Command(SingleVector);
                                        mult->addCommand(command);
                                    }
                                    if (nextAnd != string::npos) {
                                        if (foundRightParen) {
                                            // cout << "Must break" << endl;
                                            break;
                                        }
                                        // cout << "Found And" << endl;
                                        mult->addConnector("&&");
                                        vector<string> SingleVector;
                                        for (int kk = startOfCommand; kk < jj; kk++) {
                                            // cout << "Input: " << VectorInput->at(kk) << endl;
                                            string str = VectorInput->at(kk);
                                            str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
                                            SingleVector.push_back(str);
                                        }
                                        startOfCommand = jj + 1;
                                        // cout << startOfCommand << endl;
                                        Command* command = new Command(SingleVector);
                                        mult->addCommand(command);
                                    }
                                    if (nextOr != string::npos) {
                                        if (foundRightParen) {
                                            // cout << "Must break" << endl;
                                            break;
                                        }
                                        // cout << "Found Or" << endl;
                                        mult->addConnector("||");
                                        vector<string> SingleVector;
                                        for (int kk = startOfCommand; kk < jj; kk++) {
                                            // cout << "Input: " << VectorInput->at(kk) << endl;
                                            string str = VectorInput->at(kk);
                                            str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
                                            SingleVector.push_back(str);
                                        }
                                        startOfCommand = jj + 1;
                                        // cout << startOfCommand << endl;
                                        Command* command = new Command(SingleVector);
                                        mult->addCommand(command);
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                    else {
                        // cout << "Found semi" << endl;
                        mult->addConnector(";");
                        vector<string> SingleVector;
                        for (int k = startOfCommand; k <= j; k++) {
                            // cout << "Input: " << VectorInput->at(k) << endl;
                            string str = VectorInput->at(k);
                            str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                            str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                            SingleVector.push_back(str);
                        }
                        startOfCommand = j + 1;
                        // cout << startOfCommand << endl;
                        SingleVector.at(SingleVector.size()-1).pop_back();
                        Command* command = new Command(SingleVector);
                        mult->addCommand(command);
                    }
                }
                if (parenOr != string::npos) {
                    if (foundRightParen) {
                        break;
                    }
                    bool checkQuotes = false;
                    int beginOfQuotes = 0;
                    for (int a = startOfCommand; a <= j; a++) {
                        size_t quotesInParen = VectorInput->at(a).find("\"");
                        if (quotesInParen != string::npos) {
                            checkQuotes = true;
                            beginOfQuotes = a;
                            break;
                        }
                    }
                    if (checkQuotes) {
                        // cout << "START OF COMMAND = " << startOfCommand << endl;
                        for (int ii = beginOfQuotes + 1; ii < VectorInput->size(); ii++) {
                            size_t endOfQuotes = VectorInput->at(ii).find("\"");
                            if (endOfQuotes != string::npos) {
                                for (int jj = ii; jj < VectorInput->size(); jj++) {
                                    size_t nextRightParen = VectorInput->at(jj).find(")");
                                    size_t nextSemi = VectorInput->at(jj).find(";");
                                    size_t nextAnd = VectorInput->at(jj).find("&&");
                                    size_t nextOr = VectorInput->at(jj).find("||");
                                    if (nextRightParen != string::npos) {
                                        // cout << "Found right paren" << endl;
                                        if (jj == VectorInput->size() - 1) {
                                            for (int k = startOfCommand; k < VectorInput->size(); k++) {
                                                // cout << "Input: " << VectorInput->at(k) << endl;
                                                string str = VectorInput->at(k);
                                                str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                                                str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                                str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                                SeperatedVector.push_back(str);
                                            }
                                            Command* newcommand = new Command(SeperatedVector);
                                            mult->addCommand(newcommand);
                                            paren->addCommand(mult);
                                            CommandLine.push_back(paren);
                                            foundRightParen = true;
                                            break;
                                        }
                                        else {
                                            // cout << "More exists post parenthesis" << endl;
                                            for (int m = jj; m < VectorInput->size(); ++m) {
                                                // cout << "Searching past parenthesis" << endl;
                                                size_t nextSemi = VectorInput->at(m).find(";");
                                                size_t nextOr = VectorInput->at(m).find("||");
                                                size_t nextAnd = VectorInput->at(m).find("&&");
                                                if (nextSemi != string::npos) {
                                                    // cout << "Finds next semi" << endl;
                                                    endOfCommand = m + 1;
                                                    for (int n = startOfCommand; n < endOfCommand; n++) {
                                                        // cout << "Insert: " << VectorInput->at(n) << endl;
                                                        string str = VectorInput->at(n);
                                                        str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                                        SeperatedVector.push_back(str);
                                                    }
                                                    SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                                                    // for (int z = 0; z < SeperatedVector.size(); z++) {
                                                        // cout << SeperatedVector.at(z) << endl;
                                                    // }
                                                    Command* command = new Command(SeperatedVector);
                                                    mult->addCommand(command);
                                                    paren->addCommand(mult);
                                                    startOfCommand = endOfCommand;
                                                    this->StringConnectors.push_back(";");
                                                    this->CommandLine.push_back(paren);
                                                    // cout << endOfCommand << " " << startOfCommand << endl;
                                                    parse(startOfCommand, endOfCommand, VectorInput);
                                                    foundRightParen = true;
                                                    break;
                                                }
                                                else if (nextOr != string::npos) {
                                                    // cout << "Finds next Or" << endl;
                                                    endOfCommand = m;
                                                    for (int n = startOfCommand; n < endOfCommand; n++) {
                                                        // cout << "Insert: " << VectorInput->at(n) << endl;
                                                        string str = VectorInput->at(n);
                                                        str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                                        SeperatedVector.push_back(str);
                                                    }
                                                    // for (int z = 0; z < SeperatedVector.size(); z++) {
                                                        // cout << SeperatedVector.at(z) << endl;
                                                    // }
                                                    Command* command = new Command(SeperatedVector);
                                                    mult->addCommand(command);
                                                    paren->addCommand(mult);
                                                    startOfCommand = endOfCommand + 1;
                                                    this->StringConnectors.push_back("||");
                                                    this->CommandLine.push_back(paren);
                                                    // cout << endOfCommand << " " << startOfCommand << endl;
                                                    foundRightParen = true;
                                                    parse(startOfCommand, endOfCommand, VectorInput);
                                                    break;
                                                }
                                                else if (nextAnd != string::npos) {
                                                    // cout << "Finds next And" << endl;
                                                    endOfCommand = m;
                                                    for (int n = startOfCommand; n < endOfCommand; n++) {
                                                        // cout << "Insert: " << VectorInput->at(n) << endl;
                                                        string str = VectorInput->at(n);
                                                        str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                                        SeperatedVector.push_back(str);
                                                    }
                                                    // for (int z = 0; z < SeperatedVector.size(); z++) {
                                                    //     cout << SeperatedVector.at(z) << endl;
                                                    // }
                                                    Command* command = new Command(SeperatedVector);
                                                    mult->addCommand(command);
                                                    paren->addCommand(mult);
                                                    startOfCommand = endOfCommand + 1;
                                                    this->StringConnectors.push_back("&&");
                                                    this->CommandLine.push_back(paren);
                                                    // cout << endOfCommand << " " << startOfCommand << endl;
                                                    foundRightParen = true;
                                                    parse(startOfCommand, endOfCommand, VectorInput);
                                                    break;
                                                }
                                            }
                                        }
                                        break;
                                    }
                                    if (nextSemi != string::npos) {
                                        if (foundRightParen) {
                                            // cout << "Must break" << endl;
                                            break;
                                        }
                                        // cout << "Found semi" << endl;
                                        mult->addConnector(";");
                                        vector<string> SingleVector;
                                        for (int kk = startOfCommand; kk <= jj; kk++) {
                                            // cout << "Input: " << VectorInput->at(kk) << endl;
                                            string str = VectorInput->at(kk);
                                            str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                            SingleVector.push_back(str);
                                        }
                                        startOfCommand = jj + 1;
                                        // cout << startOfCommand << endl;
                                        SingleVector.at(SingleVector.size()-1).pop_back();
                                        Command* command = new Command(SingleVector);
                                        mult->addCommand(command);
                                    }
                                    if (nextAnd != string::npos) {
                                        if (foundRightParen) {
                                            // cout << "Must break" << endl;
                                            break;
                                        }
                                        // cout << "Found And" << endl;
                                        mult->addConnector("&&");
                                        vector<string> SingleVector;
                                        for (int kk = startOfCommand; kk < jj; kk++) {
                                            // cout << "Input: " << VectorInput->at(kk) << endl;
                                            string str = VectorInput->at(kk);
                                            str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                            SingleVector.push_back(str);
                                        }
                                        startOfCommand = jj;
                                        // cout << startOfCommand << endl;
                                        Command* command = new Command(SingleVector);
                                        mult->addCommand(command);
                                    }
                                    if (nextOr != string::npos) {
                                        if (foundRightParen) {
                                            // cout << "Must break" << endl;
                                            break;
                                        }
                                        // cout << "Found Or" << endl;
                                        mult->addConnector("||");
                                        vector<string> SingleVector;
                                        for (int kk = startOfCommand; kk < jj; kk++) {
                                            // cout << "Input: " << VectorInput->at(kk) << endl;
                                            string str = VectorInput->at(kk);
                                            str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                            SingleVector.push_back(str);
                                        }
                                        startOfCommand = jj;
                                        // cout << startOfCommand << endl;
                                        Command* command = new Command(SingleVector);
                                        mult->addCommand(command);
                                    }
                                }
                            }
                        }
                        break;
                    }
                    else {
                        // cout << "Found Or" << endl;
                        mult->addConnector("||");
                        vector<string> SingleVector;
                        for (int k = startOfCommand; k < j; k++) {
                            // cout << "Input: " << VectorInput->at(k) << endl;
                            string str = VectorInput->at(k);
                            str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                            str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                            SingleVector.push_back(str);
                        }
                        startOfCommand = j + 1;
                        Command* command = new Command(SingleVector);
                        mult->addCommand(command);
                    }
                }
                if (parenAnd != string::npos) {
                    if (foundRightParen) {
                        break;
                    }
                    bool checkQuotes = false;
                    int beginOfQuotes = 0;
                    for (int a = startOfCommand; a <= j; a++) {
                        size_t quotesInParen = VectorInput->at(a).find("\"");
                        if (quotesInParen != string::npos) {
                            checkQuotes = true;
                            beginOfQuotes = a;
                            break;
                        }
                    }
                    if (checkQuotes) {
                        // cout << "START OF COMMAND = " << startOfCommand << endl;
                        for (int ii = beginOfQuotes + 1; ii < VectorInput->size(); ii++) {
                            size_t endOfQuotes = VectorInput->at(ii).find("\"");
                            if (endOfQuotes != string::npos) {
                                for (int jj = ii; jj < VectorInput->size(); jj++) {
                                    size_t nextRightParen = VectorInput->at(jj).find(")");
                                    size_t nextSemi = VectorInput->at(jj).find(";");
                                    size_t nextAnd = VectorInput->at(jj).find("&&");
                                    size_t nextOr = VectorInput->at(jj).find("||");
                                    if (nextRightParen != string::npos) {
                                        // cout << "Found right paren" << endl;
                                        if (jj == VectorInput->size() - 1) {
                                            for (int k = startOfCommand; k < VectorInput->size(); k++) {
                                                // cout << "Input: " << VectorInput->at(k) << endl;
                                                string str = VectorInput->at(k);
                                                str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                                                str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                                str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                                SeperatedVector.push_back(str);
                                            }
                                            Command* newcommand = new Command(SeperatedVector);
                                            mult->addCommand(newcommand);
                                            paren->addCommand(mult);
                                            CommandLine.push_back(paren);
                                            foundRightParen = true;
                                            break;
                                        }
                                        else {
                                            // cout << "More exists post parenthesis" << endl;
                                            for (int m = jj; m < VectorInput->size(); ++m) {
                                                // cout << "Searching past parenthesis" << endl;
                                                size_t nextSemi = VectorInput->at(m).find(";");
                                                size_t nextOr = VectorInput->at(m).find("||");
                                                size_t nextAnd = VectorInput->at(m).find("&&");
                                                if (nextSemi != string::npos) {
                                                    // cout << "Finds next semi" << endl;
                                                    endOfCommand = m + 1;
                                                    for (int n = startOfCommand; n < endOfCommand; n++) {
                                                        // cout << "Insert: " << VectorInput->at(n) << endl;
                                                        string str = VectorInput->at(n);
                                                        str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                                        SeperatedVector.push_back(str);
                                                    }
                                                    SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                                                    // for (int z = 0; z < SeperatedVector.size(); z++) {
                                                        // cout << SeperatedVector.at(z) << endl;
                                                    // }
                                                    Command* command = new Command(SeperatedVector);
                                                    mult->addCommand(command);
                                                    paren->addCommand(mult);
                                                    startOfCommand = endOfCommand;
                                                    this->StringConnectors.push_back(";");
                                                    this->CommandLine.push_back(paren);
                                                    // cout << endOfCommand << " " << startOfCommand << endl;
                                                    parse(startOfCommand, endOfCommand, VectorInput);
                                                    foundRightParen = true;
                                                    break;
                                                }
                                                else if (nextOr != string::npos) {
                                                    // cout << "Finds next Or" << endl;
                                                    endOfCommand = m;
                                                    for (int n = startOfCommand; n < endOfCommand; n++) {
                                                        // cout << "Insert: " << VectorInput->at(n) << endl;
                                                        string str = VectorInput->at(n);
                                                        str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                                        SeperatedVector.push_back(str);
                                                    }
                                                    // for (int z = 0; z < SeperatedVector.size(); z++) {
                                                        // cout << SeperatedVector.at(z) << endl;
                                                    // }
                                                    Command* command = new Command(SeperatedVector);
                                                    mult->addCommand(command);
                                                    paren->addCommand(mult);
                                                    startOfCommand = endOfCommand + 1;
                                                    this->StringConnectors.push_back("||");
                                                    this->CommandLine.push_back(paren);
                                                    // cout << endOfCommand << " " << startOfCommand << endl;
                                                    foundRightParen = true;
                                                    parse(startOfCommand, endOfCommand, VectorInput);
                                                    break;
                                                }
                                                else if (nextAnd != string::npos) {
                                                    // cout << "Finds next And" << endl;
                                                    endOfCommand = m;
                                                    for (int n = startOfCommand; n < endOfCommand; n++) {
                                                        // cout << "Insert: " << VectorInput->at(n) << endl;
                                                        string str = VectorInput->at(n);
                                                        str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                                        str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                                        SeperatedVector.push_back(str);
                                                    }
                                                    // for (int z = 0; z < SeperatedVector.size(); z++) {
                                                        // cout << SeperatedVector.at(z) << endl;
                                                    // }
                                                    Command* command = new Command(SeperatedVector);
                                                    mult->addCommand(command);
                                                    paren->addCommand(mult);
                                                    startOfCommand = endOfCommand + 1;
                                                    this->StringConnectors.push_back("&&");
                                                    this->CommandLine.push_back(paren);
                                                    // cout << endOfCommand << " " << startOfCommand << endl;
                                                    foundRightParen = true;
                                                    parse(startOfCommand, endOfCommand, VectorInput);
                                                    break;
                                                }
                                            }
                                        }
                                        break;
                                    }
                                    if (nextSemi != string::npos) {
                                        if (foundRightParen) {
                                            // cout << "Must break" << endl;
                                            break;
                                        }
                                        // cout << "Found semi" << endl;
                                        mult->addConnector(";");
                                        vector<string> SingleVector;
                                        for (int kk = startOfCommand; kk <= jj; kk++) {
                                            // cout << "Input: " << VectorInput->at(kk) << endl;
                                            string str = VectorInput->at(kk);
                                            str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                            SingleVector.push_back(str);
                                        }
                                        startOfCommand = jj + 1;
                                        // cout << startOfCommand << endl;
                                        SingleVector.at(SingleVector.size()-1).pop_back();
                                        Command* command = new Command(SingleVector);
                                        mult->addCommand(command);
                                    }
                                    if (nextAnd != string::npos) {
                                        if (foundRightParen) {
                                            // cout << "Must break" << endl;
                                            break;
                                        }
                                        // cout << "Found And" << endl;
                                        mult->addConnector("&&");
                                        vector<string> SingleVector;
                                        for (int kk = startOfCommand; kk < jj; kk++) {
                                            // cout << "Input: " << VectorInput->at(kk) << endl;
                                            string str = VectorInput->at(kk);
                                            str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                            SingleVector.push_back(str);
                                        }
                                        startOfCommand = jj;
                                        // cout << startOfCommand << endl;
                                        Command* command = new Command(SingleVector);
                                        mult->addCommand(command);
                                    }
                                    if (nextOr != string::npos) {
                                        if (foundRightParen) {
                                            // cout << "Must break" << endl;
                                            break;
                                        }
                                        // cout << "Found Or" << endl;
                                        mult->addConnector("||");
                                        vector<string> SingleVector;
                                        for (int kk = startOfCommand; kk < jj; kk++) {
                                            // cout << "Input: " << VectorInput->at(kk) << endl;
                                            string str = VectorInput->at(kk);
                                            str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                                            str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                                            SingleVector.push_back(str);
                                        }
                                        startOfCommand = jj;
                                        // cout << startOfCommand << endl;
                                        Command* command = new Command(SingleVector);
                                        mult->addCommand(command);
                                    }
                                }
                                break;
                            }
                        }
                        break; 
                    }
                    else {
                        // cout << "Found And" << endl;
                        mult->addConnector("&&");
                        vector<string> SingleVector;
                        for (int k = startOfCommand; k < j; k++) {
                            // cout << "Input: " << VectorInput->at(k) << endl;
                            string str = VectorInput->at(k);
                            str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                            str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
                            SingleVector.push_back(str);
                        }
                        // for (int z = 0; z < SingleVector.size(); z++) {
                            // cout << SingleVector.at(z) << endl;;
                        // }
                        startOfCommand = j + 1;
                        Command* command = new Command(SingleVector);
                        mult->addCommand(command);
                    }
                }
            }
            break;
        }
        else if (foundSemi != string::npos) {
            bool foundQuotes = false;
            int endOfQuotes = 0;
            for (int j = startOfCommand; j <= i; j++) {
                size_t quotesBeforeSemi = VectorInput->at(j).find("\"");
                if (quotesBeforeSemi != string::npos) {
                    for (int jj = j + 1; jj < VectorInput->size(); jj++) {
                        size_t quotesAfterSemi = VectorInput->at(jj).find("\"");
                        if (quotesAfterSemi != string::npos) {
                            foundQuotes = true;
                            endOfQuotes = jj;
                            break;
                        }
                    }
                }
            }
            if (!foundQuotes) {
                // cout << "No quotes exist" << endl;
                // cout << "Finds semi" << endl;
                endOfCommand = i + 1;
                // cout << "Sets new EC" << endl;
                for (int j = startOfCommand; j < endOfCommand; j++) {
                    // cout << "Input: " << VectorInput->at(j);
                    string str = VectorInput->at(j);
                    // str.erase(std::remove(str.begin(), str.end(), '\"'));
                    SeperatedVector.push_back(str);
                }
                // for (int z = 0; z < SeperatedVector.size(); z++) {
                    // cout << SeperatedVector.at(z) << endl;
                // }
                // cout << "Creates new vector" << endl;
                startOfCommand = endOfCommand;
                SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                Command* command = new Command(SeperatedVector);
                CommandLine.push_back(command); 
                StringConnectors.push_back(";");
                parse(startOfCommand, endOfCommand, VectorInput);
                break;
            }
            else {
                // / << "Quotes do exist" << endl;
                //if (the next element or current element equals connectors)                
                for (int k = endOfQuotes; k < VectorInput->size(); k++) {
                    size_t foundSemi2 = VectorInput->at(k).find(";");
                    size_t foundAnd2 = VectorInput->at(k).find("&&");
                    size_t foundOr2 = VectorInput->at(k).find("||");
                    if (foundSemi2 != string::npos) {
                        // cout << "Finds next semi" << endl;
                        endOfCommand = k + 1;
                        for (int k = startOfCommand; k < endOfCommand; k++) {
                            // cout << "Insert: " << VectorInput->at(k) << endl;
                            string str = VectorInput->at(k);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                            SeperatedVector.push_back(str);
                        }
                        // for (int z = 0; z < SeperatedVector.size(); z++) {
                            // cout << SeperatedVector.at(z) << endl;
                        // }
                        startOfCommand = endOfCommand;
                        SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = endOfCommand;
                        StringConnectors.push_back(";");
                        // cout << endOfCommand << " " << startOfCommand << endl;
                        parse(startOfCommand, endOfCommand, VectorInput);
                        break;
                    }
                    else if (foundAnd2 != string::npos) {
                        // cout << "Finds next &&" << endl;
                        endOfCommand = k + 1;
                        for (int k = startOfCommand; k < endOfCommand - 1; k++) {
                            // cout << "Insert: " << VectorInput->at(k) << endl;
                            string str = VectorInput->at(k);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                            SeperatedVector.push_back(str);
                        }
                        // for (int z = 0; z < SeperatedVector.size(); z++) {
                            // cout << SeperatedVector.at(z) << endl;
                        // }
                        startOfCommand = endOfCommand;
                        //SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = endOfCommand;
                        StringConnectors.push_back("&&");
                        // cout << endOfCommand << " " << startOfCommand << endl;
                        parse(startOfCommand, endOfCommand, VectorInput);
                        break;
                    }
                    else if (foundOr2 != string::npos) {
                        // cout << "Finds next ||" << endl;
                        endOfCommand = k + 1;
                        for (int k = startOfCommand; k < endOfCommand - 1; k++) {
                            // cout << "Insert: " << VectorInput->at(k) << endl;
                            string str = VectorInput->at(k);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                            SeperatedVector.push_back(str);
                        }
                        // for (int z = 0; z < SeperatedVector.size(); z++) {
                            // cout << SeperatedVector.at(z) << endl;
                        // }
                        startOfCommand = endOfCommand;
                        //SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = endOfCommand;
                        StringConnectors.push_back("||");
                        // cout << endOfCommand << " " << startOfCommand << endl;
                        parse(startOfCommand, endOfCommand, VectorInput);
                        break;
                    }
                    else if (k == VectorInput->size()- 1) {
                        // cout << "Reached the end of the Vector" << endl;
                        //vector<string > SeperatedVector;
                        for(int m = startOfCommand; m < VectorInput->size(); m++) {
                            // cout << VectorInput->at(m) << endl;
                            string str = VectorInput->at(m);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        // for (int z = 0; z < SeperatedVector.size(); z++) {
                            // cout << SeperatedVector.at(z) << endl;
                        // }
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        // cout << "Pushed in one command" << endl;
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
        else if (foundOr != string::npos) {
            // cout << "Found or" << endl;
            bool foundQuotes = false;
            int endOfQuotes = 0;
            for (int j = startOfCommand; j <= i; j++) {
                size_t quotesBeforeSemi = VectorInput->at(j).find("\"");
                if (quotesBeforeSemi != string::npos) {
                    for (int jj = j + 1; jj < VectorInput->size(); jj++) {
                        size_t quotesAfterSemi = VectorInput->at(jj).find("\"");
                        if (quotesAfterSemi != string::npos) {
                            foundQuotes = true;
                            endOfQuotes = jj;
                            break;
                        }
                    }
                }
            }
            if (!foundQuotes) {
                // cout << "No quotes exist" << endl;
                endOfCommand = i;
                for (int j = startOfCommand; j < endOfCommand; j++) {
                    // cout << "Input: " << VectorInput->at(j) << endl;
                    string str = VectorInput->at(j);
                    // str.erase(std::remove(str.begin(), str.end(), '\"'));
                    SeperatedVector.push_back(str);
                }
                // for (int z = 0; z < SeperatedVector.size(); z++) {
                    // cout << SeperatedVector.at(z) << endl;
                // }
                // cout << "Creates new vector" << endl;
                startOfCommand = endOfCommand + 1;
                Command* command = new Command(SeperatedVector);
                CommandLine.push_back(command);
                StringConnectors.push_back("||");
                parse(startOfCommand, endOfCommand, VectorInput);
                break; 
            }
            else {
                // cout << "Quotes do exist" << endl;
                //if (the next element or current element equals connectors)                
                for (int k = endOfQuotes; k < VectorInput->size(); k++) {
                    size_t foundSemi2 = VectorInput->at(k).find(";");
                    size_t foundAnd2 = VectorInput->at(k).find("&&");
                    size_t foundOr2 = VectorInput->at(k).find("||");
                    if (foundSemi2 != string::npos) {
                        // cout << "Finds next or" << endl;
                        endOfCommand = k + 1;
                        for (int k = startOfCommand; k < endOfCommand; k++) {
                            // cout << "Insert: " << VectorInput->at(k) << endl;
                            string str = VectorInput->at(k);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                            SeperatedVector.push_back(str);
                        }
                        // for (int z = 0; z < SeperatedVector.size(); z++) {
                            // cout << SeperatedVector.at(z) << endl;
                        // }
                        startOfCommand = endOfCommand;
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = endOfCommand;
                        StringConnectors.push_back(";");
                        // cout << endOfCommand << " " << startOfCommand << endl;
                        parse(startOfCommand, endOfCommand, VectorInput);
                        break;
                    }
                    else if (foundAnd2 != string::npos) {
                        // cout << "Finds next &&" << endl;
                        endOfCommand = k + 1;
                        for (int k = startOfCommand; k < endOfCommand - 1; k++) {
                            // cout << "Insert: " << VectorInput->at(k) << endl;
                            string str = VectorInput->at(k);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                            SeperatedVector.push_back(str);
                        }
                        // for (int z = 0; z < SeperatedVector.size(); z++) {
                        //     cout << SeperatedVector.at(z) << endl;
                        // }
                        startOfCommand = endOfCommand;
                        //SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = endOfCommand;
                        StringConnectors.push_back("&&");
                        //cout << endOfCommand << " " << startOfCommand << endl;
                        parse(startOfCommand, endOfCommand, VectorInput);
                        break;
                    }
                    else if (foundOr2 != string::npos) {
                        //cout << "Finds next ||" << endl;
                        endOfCommand = k + 1;
                        for (int k = startOfCommand; k < endOfCommand - 1; k++) {
                            //cout << "Insert: " << VectorInput->at(k) << endl;
                            string str = VectorInput->at(k);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                            SeperatedVector.push_back(str);
                        }
                        // for (int z = 0; z < SeperatedVector.size(); z++) {
                        //     cout << SeperatedVector.at(z) << endl;
                        // }
                        startOfCommand = endOfCommand;
                        //SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = endOfCommand;
                        StringConnectors.push_back("||");
                        //cout << endOfCommand << " " << startOfCommand << endl;
                        parse(startOfCommand, endOfCommand, VectorInput);
                        break;
                    }
                    else if (k == VectorInput->size()- 1) {
                        //cout << "Reached the end of the Vector" << endl;
                        vector<string > SeperatedVector;
                        for(int m = startOfCommand; m < VectorInput->size(); m++) {
                            //cout << VectorInput->at(m) << endl;
                            string str = VectorInput->at(m);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        // for (int z = 0; z < SeperatedVector.size(); z++) {
                        //     cout << SeperatedVector.at(z) << endl;
                        // }
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        //cout << "Pushed in one command" << endl;
                        break; 
                    }
                    else {
                        
                    }
                }
            }
            break;
        }
        else if (foundAnd != string::npos) {
            //cout << "Found &&" << endl;
            bool foundQuotes = false;
            int endOfQuotes = 0;
            for (int j = startOfCommand; j <= i; j++) {
                size_t quotesBeforeSemi = VectorInput->at(j).find("\"");
                if (quotesBeforeSemi != string::npos) {
                    for (int jj = j + 1; jj < VectorInput->size(); jj++) {
                        size_t quotesAfterSemi = VectorInput->at(jj).find("\"");
                        if (quotesAfterSemi != string::npos) {
                            foundQuotes = true;
                            endOfQuotes = jj;
                            break;
                        }
                    }
                }
            }
            if (!foundQuotes) {
                endOfCommand = i;
                for (int j = startOfCommand; j < endOfCommand; j++) {
                    //cout << "Input: " << VectorInput->at(j) << endl;
                    string str = VectorInput->at(j);
                    // str.erase(std::remove(str.begin(), str.end(), '\"'));
                    SeperatedVector.push_back(str);
                }
                // for (int z = 0; z < SeperatedVector.size(); z++) {
                    // cout << SeperatedVector.at(z) << endl;
                // }
                startOfCommand = endOfCommand + 1;
                Command* command = new Command(SeperatedVector);
                CommandLine.push_back(command);
                StringConnectors.push_back("&&");
                parse(startOfCommand, endOfCommand, VectorInput);
                break;
            }
            else {
                //cout << "Quotes do exist" << endl;
                //if (the next element or current element equals connectors)                
                for (int k = endOfQuotes; k < VectorInput->size(); k++) {
                    size_t foundSemi2 = VectorInput->at(k).find(";");
                    size_t foundAnd2 = VectorInput->at(k).find("&&");
                    size_t foundOr2 = VectorInput->at(k).find("||");
                    if (foundSemi2 != string::npos) {
                        //cout << "Finds next semi" << endl;
                        endOfCommand = k + 1;
                        for (int k = startOfCommand; k < endOfCommand; k++) {
                            //cout << "Insert: " << VectorInput->at(k) << endl;
                            string str = VectorInput->at(k);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                            SeperatedVector.push_back(str);
                        }
                        // for (int z = 0; z < SeperatedVector.size(); z++) {
                        //     cout << SeperatedVector.at(z) << endl;
                        // }
                        SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                        startOfCommand = endOfCommand;
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = endOfCommand;
                        StringConnectors.push_back(";");
                        //cout << endOfCommand << " " << startOfCommand << endl;
                        parse(startOfCommand, endOfCommand, VectorInput);
                        break;
                    }
                    else if (foundAnd2 != string::npos) {
                        //cout << "Finds next &&" << endl;
                        endOfCommand = k + 1;
                        for (int k = startOfCommand; k < endOfCommand - 1; k++) {
                            //cout << "Insert: " << VectorInput->at(k) << endl;
                            string str = VectorInput->at(k);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                            SeperatedVector.push_back(str);
                        }
                        // for (int z = 0; z < SeperatedVector.size(); z++) {
                            // cout << SeperatedVector.at(z) << endl;
                        // }
                        startOfCommand = endOfCommand;
                        //SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = endOfCommand;
                        StringConnectors.push_back("&&");
                        //cout << endOfCommand << " " << startOfCommand << endl;
                        parse(startOfCommand, endOfCommand, VectorInput);
                        break;
                    }
                    else if (foundOr2 != string::npos) {
                        //cout << "Finds next ||" << endl;
                        endOfCommand = k + 1;
                        for (int k = startOfCommand; k < endOfCommand - 1; k++) {
                            //cout << "Insert: " << VectorInput->at(k) << endl;
                            string str = VectorInput->at(k);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                            SeperatedVector.push_back(str);
                        }
                        // for (int z = 0; z < SeperatedVector.size(); z++) {
                            // cout << SeperatedVector.at(z) << endl;
                        // }
                        startOfCommand = endOfCommand;
                        //SeperatedVector.at(SeperatedVector.size()-1).pop_back();
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        startOfCommand = endOfCommand;
                        StringConnectors.push_back("||");
                        //cout << endOfCommand << " " << startOfCommand << endl;
                        parse(startOfCommand, endOfCommand, VectorInput);
                        break;
                    }
                    else if (k == VectorInput->size()- 1) {
                        //cout << "Reached the end of the Vector" << endl;
                        //vector<string > SeperatedVector;
                        for(int m = startOfCommand; m < VectorInput->size(); m++) {
                            cout << VectorInput->at(m) << endl;
                            string str = VectorInput->at(m);
                            str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());    
                            SeperatedVector.push_back(str);
                        }
                        // for (int z = 0; z < SeperatedVector.size(); z++) {
                            // cout << SeperatedVector.at(z) << endl;
                        // }
                        Command* command = new Command(SeperatedVector);
                        this->CommandLine.push_back(command);
                        //cout << "Pushed in one command" << endl;
                        break; 
                    }
                    else {
                    }
                }
            }
            break;
        }
        else if (i == VectorInput->size() - 1) {
            //cout << "Reached the end of the Vector" << endl;
            vector<string > SeperatedVector;
            for(int m = startOfCommand; m < VectorInput->size(); m++) {
                cout << VectorInput->at(m) << endl;
                string str = VectorInput->at(m);
                str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                str.erase(std::remove(str.begin(), str.end(), '('), str.end());
                str.erase(std::remove(str.begin(), str.end(), ')'), str.end());    
                SeperatedVector.push_back(str);
            }
            // for (int z = 0; z < SeperatedVector.size(); z++) {
            //     cout << SeperatedVector.at(z) << endl;
            // }
            Command* command = new Command(SeperatedVector);
            this->CommandLine.push_back(command);
            //cout << "Pushed in one command" << endl;
            break;
            //cout << "Pushed in very last command" << endl;
        }
        else {
            //cout << "Found nothing" << endl;
        }
    }
}
        

bool FullCommand::execute() {
    //cout << "Enters full command execute" << endl;
    if (this->StringConnectors.empty()) {
        //cout << "No connectors" << endl;
        for (int i = 0; i < CommandLine.size(); i++) {
            CommandLine.at(i)->execute();
        }    
    }
    else {
        int counter = 0;
        //cout << StringConnectors.size() << endl;
        //cout << "-------------------------------------------------------------" << endl;
        for (int a = 0; a < StringConnectors.size(); a++) {
            //cout << StringConnectors.at(a) << endl;
        }
        //cout << "-------------------------------------------------------------" << endl;
        for (int i = 0; i < StringConnectors.size(); i++) {
            //cout << "Connectors exist" << endl;
            if (StringConnectors.at(i) == ";") {
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
            else if (StringConnectors.at(i) == "||") {
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
            else if (StringConnectors.at(i) == "&&") {
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
        for (int j = 0; j < Connectors.size(); ++j) {
           //cout << "Executing connector: " << endl;
            Connectors.at(j)->execute();
        }
    }
}

void FullCommand::addCommand(Base* command) {
    CommandLine.push_back(command);    
}