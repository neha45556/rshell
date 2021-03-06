#include "command.h"
#include <algorithm>

using namespace std;

Command::Command(vector<string > enteredVector) {
    for(int i = 0; i < enteredVector.size(); i++) {
        this->SingleCommand.push_back(enteredVector.at(i));
    }
}
// bool Command::findHashtag() {
//     for (int i = 0; i < SingleCommand.size(); i++) {
//         //cout << "Iterating through findHashtag" << endl;
//         size_t foundHashtag = SingleCommand.at(i).find("#");
//         if (foundHashtag != string::npos) {
//             return true;
//         }
//     }
// }
// void Command::deleteHashtag() {
//     //cout << "Enters deleteHashtag" << endl;
//     for(int j = 0; j < SingleCommand.size(); j++) {
//         //cout << "Iterating" << endl;
//         size_t foundHashtag = SingleCommand.at(j).find("#");
//         if (foundHashtag != string::npos) {
//             //cout << "Found hashtag" << endl;
//             for (int k = SingleCommand.size() - 1; k > j; k--) {
//                 //cout << "pop" << endl;
//                 SingleCommand.pop_back();
//             }
//             //cout << j << endl;
//             string str = SingleCommand.at(j);
//             //cout << str << endl;
//             //boost::erase_all(str, "#");
//             SingleCommand.at(j).erase(std::remove(SingleCommand.at(j).begin(), SingleCommand.at(j).end(), '#'), SingleCommand.at(j).end());
//             //cout << SingleCommand.at(j) << endl;
//             // str.erase(foundHashtag, string::npos);
//         }
//     }
// }
// void Command::printCommand() {
//     for (int i = 0; i < this->SingleCommand.size(); i++) {
//         //cout << "Iterated through SingleCommand" << endl;
//         // cout << this->SingleCommand.at(i) << endl;
//     }
// }
bool Command::execute(int in, int out) {
    // cout << "Enter Single Execute" << endl;
    // //cout << this->SingleCommand.size() << endl;
    // for (int i = 0; i < this->SingleCommand.size(); i++) {
    //     cout << "Iterated through SingleCommand" << endl;
    //     cout << this->SingleCommand.at(i) << endl;
    // }
    // for (int x = 0; x < SymbolCommands.size(); x++) {
    //     cout << SymbolCommands.at(x) << endl;
    // }
    for (int j = 0; j < SingleCommand.size(); j++) {
        if (SingleCommand.at(j) == "exit") {
            exit(0);
        }
    }
    if (SingleCommand.at(0) == "exit") {
        //cout << "Exiting execution" << endl;
        exit(0);
    }
    char *cmd = &this->SingleCommand.at(0)[0];
    char *argv[this->SingleCommand.size()+1];
    for (unsigned i = 0; i < this->SingleCommand.size(); i++) {
        argv[i] = &this->SingleCommand.at(i)[0];
    }
    if(SingleCommand.at(0) == "[" || SingleCommand.at(0) == "test"){
        //cout << "this" << endl;
        Test* t1 = new Test(SingleCommand); 
        t1->parse();
    }
    argv[this->SingleCommand.size()] = NULL;
    pid_t childpid = fork();
    if (childpid < 0) {
        perror("fork() failed");
        exit(-1);
    }
    else if (childpid == 0) {
        //cout << "Child process" << endl;
        if (dup2(in,0) == -1) {
            //cout << "dup in" << endl;
            perror("dup2");
            return false;
        }
        if (dup2(out,1) == -1) {
            //cout << "dup out" << endl;
            perror("dup2");
            return false;
        }
        if (-1 == execvp(cmd, argv)) {
            perror("Command not found");
            return false;
            exit(-1);
        }
    }
    else if (childpid > 0) {
        //cout << "Parent" << endl;
        int status;
        waitpid(childpid, &status, 0);
        if (status == -1) {
            return false;
        }
        if (status == 0) {
            this->flag = true;
            return true;
        }
    }
}
bool Command::checkFlag() {
    if (this->flag) {
        return true;
    }
    else {
        return false;
    }
}
void Command::setFlagTrue() {
    this->flag = true;
}
string Command::at(int num) {
    return this->SingleCommand.at(num);
}
int Command::size() {
    return this->SingleCommand.size();
} 
vector<string> Command::get_data() {
    return this->SingleCommand;
}
