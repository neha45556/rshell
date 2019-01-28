# CS 100 Programming Project
 Winter 2019 
 
> Authors: Marc Jimenez (862049962) , Neha Gupta (862049507)

# Introduction

This program will print out a command prompt from which it will read in a line of commands and connectors from standard input. It will do this through a composite pattern from which the classes known as **_argumentList_** , **_connector_** and **_command_** are derived from a shared base interface class known as **_cmdline_** . It will then execute the approriate commands using **_fork**_, **_execvp**_, and **_waitpid**_. First our client will create an input through the use of the derived classes by creating specific objects through the use of the class's constructors. Those will then be read and executed upon and processed through our **_fork**_, **_execvp**_, and **_waitpid**_ commands.

# Diagram


# Classes

Our class group is **_argumentList_** , **_connector_** and **_command_** which all inherit from the single base class of **_cmdline_** . 

The base class **_cmdline_** will carry an encapsulated input represents the name of the command, argument list, or connector. It will also hold a standardized print function which the derived class will use. 

Each of the derived classes will hold an encapsulated pointer of type **_cmdline_** that will be used to help interact amongst each other. Not only that but each derived class will have their own constructor that will take in a base pointer. 

The class **_command_** will hold an extra encapsulated base pointer named _prev_ which will help us determine if a connector had been written in the command line before it. In its constructors it will first check if the _prev_ pointer exists and if so, then it will then run the **evaluate** function located in the **_connector_** class. 

The class **_connector_** will point to the first **_commmand_** object located after the **_connector_** in the command line. It also will hold an extra encapsulated base pointer named _first_ that will point to the first **_command_** in the commandThen it will run its **evaluate** function which will, depending on its encapsulated string, will do different processes. If its a "&&" then the next command is exeuted only if the first command succeeds, if its a "||" then the next command is executed only if the first one fails, and if its a ";" then the next command is always executed. 

The class **_


