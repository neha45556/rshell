#include "or.h"

Or::Or(Base* lhs, Base* rhs) {
    this->first = lhs;
    this->next = rhs;
}
bool Or::execute() {
    //cout << "Enters or execute" << endl; 
    if (first->checkFlag()) {
       // cout << "First command has been called. RHS will not be executed" << endl;
        next->setFlagTrue();
        return false;
    }
    else {
        //cout << "First command has not been called" << endl;
        if (!first->execute()) {
            //cout << "LHS returns false." << endl;
            if (next->execute()) {
              //  cout << "RHS returns true" << endl;
                return true;
            }
            else {
              //  cout << "RHS returns false" << endl;
                next->setFlagTrue();
                return false;
            }
        }
        else {
           // cout << "LHS returns true" << endl;
            next->setFlagTrue();
            return false;
        }
    }
}
bool Or::checkFlag() {
    if (first->checkFlag() || next->checkFlag()) {
        return true;
    }
    else {
        return false;
    }
}