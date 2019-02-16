#include "command.h"
#include <algorithm>

using namespace std;

Command::Command(vector<string > enteredVector) {
    for(int i = 0; i < enteredVector.size(); i++) {
        this->SingleCommand.push_back(enteredVector.at(i));
    }
}
bool Command::findHashtag() {
    for (int i = 0; i < SingleCommand.size(); i++) {
        //cout << "Iterating through findHashtag" << endl;
        size_t foundHashtag = SingleCommand.at(i).find("#");
        if (foundHashtag != string::npos) {
            return true;
        }
    }
}
void Command::deleteHashtag() {
    //cout << "Enters deleteHashtag" << endl;
    for(int j = 0; j < SingleCommand.size(); j++) {
        //cout << "Iterating" << endl;
        size_t foundHashtag = SingleCommand.at(j).find("#");
        if (foundHashtag != string::npos) {
            //cout << "Found hashtag" << endl;
            for (int k = SingleCommand.size() - 1; k > j; k--) {
                //cout << "pop" << endl;
                SingleCommand.pop_back();
            }
            //cout << j << endl;
            string str = SingleCommand.at(j);
            //cout << str << endl;
            //boost::erase_all(str, "#");
            SingleCommand.at(j).erase(std::remove(SingleCommand.at(j).begin(), SingleCommand.at(j).end(), '#'), SingleCommand.at(j).end());
            //cout << SingleCommand.at(j) << endl;
            // str.erase(foundHashtag, string::npos);
        }
    }
}
void Command::printCommand() {
    for (int i = 0; i < this->SingleCommand.size(); i++) {
        //cout << "Iterated through SingleCommand" << endl;
        // cout << this->SingleCommand.at(i) << endl;
    }
}
bool Command::execute() {
    //cout << "Enter Single Execute" << endl;
    // //cout << this->SingleCommand.size() << endl;
    // for (int i = 0; i < this->SingleCommand.size(); i++) {
    //     cout << "Iterated through SingleCommand" << endl;
    //     cout << this->SingleCommand.at(i) << endl;
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
    char *argv[1000];
    for (unsigned i = 0; i < this->SingleCommand.size(); i++) {
        argv[i] = &this->SingleCommand.at(i)[0];
    }
    argv[this->SingleCommand.size()] == NULL;
    pid_t childpid = fork();
    if (childpid < 0) {
        perror("fork() failed");
        exit(-1);
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
    else {
        if (-1 == execvp(cmd, argv)) {
            perror("Command not found");
            exit(-1);
        }
        exit(0);
        // else {
        //     this->flag = true;
        //     return true;
        // }
    }
    // if (childpid == 0) {
    //     //cout << "In child process: " << endl;
    //     waitpid(childpid, NULL, 0);
    //     execvp(cmd, argv);
    // }
    // if (childpid > 0) {
    //     int status;
    //     //cout << "In parent process: " << endl;
    //     waitpid(childpid, &status, 0);
    // }
    // else if (childpid == -1) {
    //     perror("fork() failed");
    //     //return false;
    // }
    // else {
    //     if (-1 == execvp(cmd, argv)) {
    //         perror("Command not found");
    //         return false;
    //         exit(1);
    //     }
    //     else {
    //         this->flag = true;
    //         return true;
    //     }
    // }
    //out << "end of the function lol" << endl;
    // this->flag = true;
    // return true;
    
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
