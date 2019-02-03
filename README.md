# CS 100 Programming Project
 Winter 2019 
 
> Authors: Marc Jimenez (862049962) , Neha Gupta (862049507)

# Introduction

This program will print out a command prompt from which it will read in a line of commands and connectors from standard input. It will do this through a composite pattern from which the classes known as **_argumentList_**, **_connector_** and **_command_** are derived from a shared base interface class known as **_cmdline_** . It will then execute the approriate commands using **_fork_**, **_execvp_**, and **_waitpid_** . First our client will create an input through the use of the derived classes by creating specific objects through the use of the class's constructors. Those will then be read and executed upon and processed through our **_fork_**, **_execvp_**, and **_waitpid_** commands.

# Diagram

![sample UML Diagram](https://github.com/cs100/assignment-marc-jimenez-neha-gupta/blob/master/images/assignment%201%20diagram.jpeg)

# Classes

Our class group is **_argumentList_** , **_connector_** and **_command_** which all inherit from the single base class of **_cmdline_** . 

The base class **_cmdline_** will carry an encapsulated input represents the name of the command, argument list, or connector. It will also hold a standardized print function which the derived class will use. 

Each of the derived classes will hold an encapsulated pointer of type **_cmdline_** that will be used to help interact amongst each other. Not only that but each derived class will have their own constructor that will take in a base pointer. 

The class **_command_** will hold an extra encapsulated base pointer named _prev_ which will help us determine if a connector had been written in the command line before it. In its constructors it will first check if the _prev_ pointer exists and if so, then it will then run the **evaluate** function located in the **_connector_** class. 

The class **_connector_** will point to the first **_commmand_** object located after the **_connector_** in the command line. It also will hold an extra encapsulated base pointer named _first_ that will point to the first **_command_** in the command line. Then it will run its **evaluate** function which will, depending on its encapsulated string, will do different processes. If its a "&&" then the next command is exeuted only if the first command succeeds, if its a "||" then the next command is executed only if the first one fails, and if its a ";" then the next command is always executed. 

The class **_argumentList_** will hold many of the same things as the base class but in addition have a constructor that passes in a string. From that string we will set the encapsulated string variable equal to it.

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

# Development and Testing Roadmap

1. Create base class **_cmdline_** : Marc Jimenez
2. Create derived class **_argumentList_** : Neha Gupta
3. Create derived class **_connector_** : Neha Gupta
4. Create derived class **_command_** : Marc Jimenez
5. Write unit test single_command_tests.sh : Marc Jimenez
6. Write unit test multiple_command_tests.sh : Neha Gupta
7. Write unit test commented_command_tests.sh : Marc Jimenez
8. Write unit test exit_command_tests.sh : Neha Gupta







