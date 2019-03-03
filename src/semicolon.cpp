#include "semicolon.h"

Semicolon::Semicolon(Base* lhs, Base* rhs) {
    this->first = lhs;
    this->next = rhs;
}
bool Semicolon::execute() {
    //cout << "Enters semicolon execute:" << endl; 
    if(first->checkFlag()) {
        //cout << "First command has been executed" << endl;
        if(next->execute()) {
            //cout << "Next command successfully executed" << endl;
            return true;
        }
        else {
            //cout << "Next command not executed" << endl;
            next->setFlagTrue();
            return false;
        }
    }
    else {
        //cout << "First command hasn't been executed" << endl;
        if(first->execute()) {
            //cout << "First command executed successfully" << endl;
            if(next->execute()) {
                //cout << "Next command successfully executed" << endl;
                return true;
            }
            else {
                //cout << "Next Command Fails to execute" << endl;
                next->setFlagTrue();
                return false;
            }
        }
        else {
            //cout << "first command failed to execute" << endl;
            if(next->execute()) {
                //cout << "Next command successfully executed" << endl;
                return true;
            }
            else {
                //cout << "Next Command failed to execute" << endl;
                next->setFlagTrue();
                return false;
            }
        }
    }
}
bool Semicolon::checkFlag() {
    if (first->checkFlag() || next->checkFlag()) {
        return true;
    }
    else {
        return false;
    }
}