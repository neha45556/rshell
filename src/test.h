#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <vector>

using namespace std;

class Test {
    private:
        vector<string> v1;
    public:
        Test(vector<string> v2){
            v1 = v2;
        };
        Test(char* ){};
        void parse();
        int flag(int loc);
};
#endif


