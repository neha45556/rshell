#include "DoubleOut.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>

using namespace std;
DoubleOut::DoubleOut(Base* lhs, Base* rhs) {
    this->first = lhs;
    this->next = rhs;
}  
bool DoubleOut::execute(int in, int out) {
    //cout << "DoubleOut execute" << endl;
    string outfile = this->next->at(0);
    //cout << this->next->at(0);    
    out = open(outfile.c_str(), O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    return this->first->execute(0, out);
}
bool DoubleOut::checkFlag() {
    if (first->checkFlag() || next->checkFlag()) {
        return true;
    }
    else {
        return false;
    }
}