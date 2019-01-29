#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h> 

using namespace std;

int main() { 
	pid_t childpid = fork();
	if (childpid == 0)  {
		waitpid(childpid, NULL, WNOHANG);
		cout << "We in the child process" << endl;
		char array[]= "git status";
		char* pointer1 = 
		argv[0] = "git";
		argv[1] = "status";
		execvp(cmd, argv); 
	}
	else if (childpid > 0) {
		cout << "We in the parent process" << endl;
		string cmd = "git"; 
		string argv[2];
		argv[0] = "git";
		argv[1] = "log";
		execvp(cmd, argv);
	}
	else {
		perror("fork() failed");
		return 1;
	}
	return 0;
}
