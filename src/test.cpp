#include "test.h"

using namespace std;
// Test :: Test(vector<string> v2){
//             v1 = v2;
// };
// Test :: Test(char* ){ };
void Test::parse(){ 
    int loc;
    for(int i = 0; i < v1.size(); i++) {
        if(v1.at(i) == "[" || v1.at(i) == "test" ){
            loc = i;
        }
    }
        if(flag(loc) == 1){
            cout << "(TRUE)" << endl;
         }
        else{
            cout << "(FALSE)" << endl;
        }
}
int Test::flag(int loc){
    if(v1.at(loc + 1) == "-e"){
        char* argv = &v1.at(2)[0];
        struct stat path_stat;
        stat(argv, &path_stat);
        if(S_ISREG(path_stat.st_mode) || S_ISDIR(path_stat.st_mode)){
            return 1;
        }
            return 0;
        }
        else if(v1.at(loc + 1) == "-f"){
            //cout << "-f" << endl;
            char*argv = &v1.at(2)[0];
            struct stat path_stat;
            stat(argv, &path_stat);
            return S_ISREG(path_stat.st_mode);   
                
            }
            else if(v1.at(loc + 1) == "-d"){
            //cout << "-d" << endl;
                char* argv = &v1.at(2)[0];
                struct stat path_stat;
                stat(argv, &path_stat);
                return S_ISDIR(path_stat.st_mode);
        }
        else {//if(v1.at(loc + 1) != "-d" || v1.at(loc + 1) != "-f" || v1.at(loc + 1) != "-e"  ){
            //cout << "none" << endl;
            char* argv = &v1.at(1)[0];
            struct stat path_stat;
            stat(argv, &path_stat);
            if(S_ISREG(path_stat.st_mode) || S_ISDIR(path_stat.st_mode)){
                return 1;
        }
        return 0;
    }
}

