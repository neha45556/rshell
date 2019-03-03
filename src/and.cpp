#include "and.h"

And::And(Base* lhs, Base* rhs) {
    this->first = lhs;
    this->next = rhs;
}
bool And::execute() {
    //cout << "Enter and execute" << endl;
    if(first->checkFlag()) {
        //cout << "LHS has been called" << endl;
        if(next->execute()) {
            //cout << "LHS has been called, RHS returns true" << endl;
            return true;
        }
        else {
            //cout << "LHS has been called, RHS returns false" << endl;
            next->setFlagTrue();
            return false;
        }
    }
    else {
        //cout << "LHS has not been called" << endl;
        if (!first->execute()) {
            //cout << "LHS returns false" << endl;
            next->setFlagTrue();
            return false;
        }
        else {
            //cout << "LHS returns true" << endl;
            if (next->execute()) {
               // cout << "LHS called return true, RHS returns true" << endl;
                return true;
            }
            else {
                //cout << "LHS called return true, RHS returns false" << endl;
                next->setFlagTrue();
                return false;
            }
        }
    }
}
bool And::checkFlag() {
    if (first->checkFlag() || next->checkFlag()) {
        return true;
    }
    else {
        return false;
    }
}