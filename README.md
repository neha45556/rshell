# CS 100 Programming Project
 Winter 2019 
 
> Authors: Marc Jimenez (862049962) , Neha Gupta (862049507)

# Introduction

This program will print out a command prompt from which it will read in a line of commands and connectors from standard input. It will do this through a composite pattern from which the classes known as **_execute_**, **_connector_** and **_command_** are derived from a shared base interface class known as **_base_**. We have an additional class called **_input_** which stores the client's input and parses through the char* array. It will then execute the approriate commands using **_fork_**, **_execvp_**, and **_waitpid_** . First our client will create an input through the use of the derived classes by creating specific objects through the use of the class's constructors. Those will then be read and executed upon and processed through our **_fork_**, **_execvp_**, and **_waitpid_** commands. Based on the inputs we recieve our command line will check for connectors, commands, and comments before outputting the data. Additionally, we built a parser using the strok function from the C standard library to parse through our client’s input. The tokens from the input array helps us idenitfy the connectors and commands and populate our two vectors of type string. 

# Diagram

![sample UML Diagram](https://github.com/cs100/assignment-marc-jimenez-neha-gupta/blob/master/images/Assignment2Uml.jpeg)

# Parsing

![parse](https://github.com/cs100/assignment-marc-jimenez-neha-gupta/blob/master/images/parse.jpeg)

# Classes

Our class group is **_execute_** , **_connector_** and **_command_** which all inherit from the single base class of **_base_**. On top of that we have three classes that derive from the **_connector_** class called **_and_**, **_semicolon_**, and **_or_**. 

The base class **_base_** will carry functions to help us idenity whether the client has included comments which are preceded by hastags, which indicate comments must be ignored. The base class encapsulates a bool function called flag which is used in other classes to indicate how and when to implement the connectors. 

The **_input_** class will have private a char* array, two type string vectors
 
The **_execute_** will have two private vectors type Base* called commandLine and connectors. In addtion, to the functions held by the Base class the execute class also implements populateExecute and populateExecuteConnectors type void functions. 

The class **_command_** will hold an encapsulated vector of type string named singleCommand which is iterating through the client's input and searching for hashtags. The command class is responsible for testing whether the user's commands are exectuable. The commands are exectued based on the syscalls waitpid, fork, and execvp. After each syscall perror is called in any case of an error. The final part is the exit call which exits our program if called upon.

The class **_connector_** will point to the first **_commmand_** object located after the **_connector_** in the command line. It also will hold an extra encapsulated base pointer named _first_ that will point to the first **_command_** in the command line. Then it will run its **evaluate** function in its constructors which will, depending on its encapsulated string, will do different processes. If its a "&&" then the next command is exeuted only if the first command succeeds, if its a "||" then the next command is executed only if the first one fails, and if its a ";" then the next command is always executed. 

# Prototype/Research

```C++
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string>

using namespace std;

int main() {
        pid_t childpid = fork();
        int counter = 0;
        if (childpid == 0)  {
                waitpid(childpid, NULL, WNOHANG);
                cout << "We in the child process" << endl;
                char *cmd = "echo";
                char *argv[4];
                argv[0] = "echo";
                argv[1] = "hello";
                argv[2] = "world";
                argv[3] = NULL;
                execvp(cmd, argv);
        }
        else if (childpid > 0) {
                cout << "We in the parent process" << endl;
                waitpid(childpid, NULL, WNOHANG);
                counter++;
        }
        else {
                perror("fork() failed");
                return 1;
        }
        return 0;
}
```
fork()

We found that fork allows us to clone our current parent process creating a child process. As a clone this process will hold all of the same variables and data as the parent process, but it allows us to run a different branch of the program or even execute a different program. The child process will also run in parallel with the parent process allowing any changes to stay within the child.

waitpid()

We found that waitpid() allows our parent process to stop allowing it to wait for the child process to eventually terminate. This allows us to avoid zombie children processes that eat away at our memory eventually crashing our programs.

execvp()

We found that execvp() will be how we execute commands in our shell. It takes in two arguments first being the file we wish to execute and then an array of null-terminated strings that represent the appropriate arguments to the file. 



# Development and Testing Roadmap

1. Create base class **_base_** : Marc Jimenez
2. Create derived class **_execute_** : Neha Gupta
3. Create derived class **_connector_** : Neha Gupta
4. Create derived class **_command_** : Marc Jimenez
5. Write unit test single_command_tests.sh : Marc Jimenez
6. Write unit test multiple_command_tests.sh : Neha Gupta
7. Write unit test commented_command_tests.sh : Marc Jimenez
8. Write unit test exit_command_tests.sh : Neha Gupta







