#include "LessInput.h"

#include <stdio.h>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>
#include <string>

using namespace std;

LessInput::LessInput(Base* lhs, Base* rhs) {
    this->first = lhs;
    this->next = rhs;
}
bool LessInput::execute(int in, int out) {
    //cout << "Less input execute" << endl;
    string infile = this->next->at(0);
   // cout << this->next->at(0) << endl;
    in = open(infile.c_str(), O_RDONLY);
    return this->first->execute(in, out);
}
bool LessInput::checkFlag() {
    if (first->checkFlag() || next->checkFlag()) {
        return true;
    }
    else {
        return false;
    }
}