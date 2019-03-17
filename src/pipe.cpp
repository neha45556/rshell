#include "pipe.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>

using namespace std;

Pipe::Pipe(Base* lhs, Base* rhs) {
    this->first = lhs;
    this->next = rhs;
}
bool Pipe::execute(int in, int out) {
     int fds[2];

    if(pipe(fds) == -1) {
        perror("pipe");
        return false;
    }


    if(!first->execute(in,fds[1])) {
        return false;
    }

    close(fds[1]);

    if(!next->execute(fds[0],out)) {
        return false;
    }
    close(fds[0]);
    return true;
}