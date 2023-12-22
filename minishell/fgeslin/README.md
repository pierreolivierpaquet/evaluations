# minishell

<p align="center">
  <img src="/screenshot.png" width="100%" />
</p>

## Description

Project from 42 School
A simple re-creation of Bash in C and [Readline library](https://tiswww.case.edu/php/chet/readline/rltop.html)

## Installation

```
git clone git@github.com:Dot-kpp/minishell.git
make
```

## Features

- Draw a waiting prompt
- Have a dynamic history that can be used with arrow up and down
- Handle any executable file relatively or via $PATH
- Process the single a double quotes
- Possess its own environment variables that can be called with $
- Handle Redirections and Pipes
- Handle signals from ctrl-C ctrl-D and ctrl-/ according to Bash
- Have its own builtins commands :
    - **echo** with -n flag
    - **cd** only with 1 argument
    - **pwd** without flag
    - **export** without flag
    - **unset** without flag
    - **env** without flag, nor argument
    - **exit** without flag

## Usage

```
./minishell
```
leak check:
```
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --suppressions=./minishell.sup ./minishell
```
Same usage as Bash

## Credits

[fgeslin](https://github.com/KayzaFlo)</br>
[jpilotte](https://github.com/Dot-kpp)</br>

https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf</br>
https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html</br>
