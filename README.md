# minishell
This is one of the projects in the curriculum of 42 School.

## The goal of the school
The schools concept relies on you teaching yourself by learning how to do research and ask for help of your peers when needed. There are no teachers nor lectures. The curriculum includes planty of projects that you need to finish in order to progress and finish the school. The projects increase in difficulty as you go. Main programming language used in the school is `C` and on later stages of the curriculum `C++` besides these two you also learn about other stuff like: `Docker`, `Virtual Machines`, `networking` and more.

## The goal of the project
This project was about creating a simple shell with the following features:
 - Display a promt while waiting for a new command
 - Have a working history
 - Search and launch the right executable *(based on the PATH variable or using a
   relative or an absolute path)*.
 - Support of single *(')* and double *(")* quotes
 - Implement redirections *(<, >, <<, >>)*
 - Implement pipes *(|)*
 - Support enviroment variables *(example: $HOME)*
 - Handle $? *(exit code of the last executed foreground pipeline)*
 - Handle ctrl-C, ctrl-D, ctrl-\
 
We also were required to implement the following built in commands:
 - `echo` with option -n
 - `cd` with only a relative or absolute path
 - `pwd` with no options
 - `export` with no options
 - `unset` with no options
 - `env` with no options or arguments
 - `exit` with no options
