#include "MoreOutput.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>

using namespace std;
MoreOutput::MoreOutput(Base* lhs, Base* rhs) {
    this->first = lhs;
    this->next = rhs;
}  
bool MoreOutput::execute(int in, int out) {
    //cout << "MoreOutput execute" << endl;
    string outfile = this->next->at(0);
    //cout << this->next->at(0);
    out = open(outfile.c_str(),O_WRONLY| O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    //cout << "Before execute" << endl;
    return this->first->execute(0, out);
}
bool MoreOutput::checkFlag() {
    if (first->checkFlag() || next->checkFlag()) {
        return true;
    }
    else {
        return false;
    }
}