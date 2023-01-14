# minishell
This is one of the projects in the curriculum of 42 School. It's also the first group project in curriculum. My partner: [Felix Brüggemann](https://github.com/FelixBrgm)

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

## In this project I learned about:
 - What are `signals` and how to use them
 - `Redirections` in bash
 - `Variable expansion` in bash
 - How does the bash `interpret single` and `double quotes`
 - What's a `parser`
 - How to better use bash
 - Usage of `builtin commands` of bash

## How to use it
Clone the repo and cd into it. Before running `make` make sure that you have `readline library` installed as it's used for reading input and managing the history of commands. If after running `make` readline is not found change the in `READLINE_INC` and `READLLINE_LIB` variables in the `Makefile` to include the correct paths. After compilation simply run `./minishell` and the shell will start, from that point on you're using our version of shell and the rules from [The goal of the project](https://github.com/Doush-H/minishell/edit/main/README.md#the-goal-of-the-project) apply.

_This implementation is not perfect by any means and does contain bugs. ❗_
