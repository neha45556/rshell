# CS 100 Programming Project
 Winter 2019 
 
> Authors: Marc Jimenez (862049962) , Neha Gupta (862049507)

# Introduction

This program will print out a command prompt from which it will read in a line of commands and connectors from standard input. It will do this through a composite pattern from which the classes known as **_argumentList_** , **_connector_** and **_command_** are derived from a shared base interface class known as **_cmdline_** . It will then execute the approriate commands using **_fork**_, **_execvp**_, and **_waitpid**_. First our client will create an input through the use of the derived classes by creating specific objects through the use of the class's constructors. Those will then be read and executed upon and processed through our **_fork**_, **_execvp**_, and **_waitpid**_ commands.

# Diagram


# Classes

Our class group is **_argumentList_** , **_connector_** and **_command_** which all inherit from the single base class of **_cmdline_** . 

The base class **_interface_** will carry an encapsulated input represents the name of the command, argument list, or connector. It will also hold a standardized print function which the derived class will use. 

Each of the derived class will hold a encapsulated pointer of type base that will be used to help interact amongst each other. 

The derived class **_command_** will have a constructor to determine 


