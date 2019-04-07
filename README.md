# 0x15. C - Simple Shell

## Description
This team project is part of the first year curriculum of Holberton School.
Simple Shell is a command line interpreter that replicates the **sh** program.

What we learnt:
* How a shell works and finds commands
* Creating, forking and working with processes
* Executing another program from a program
* Pair programming and team work
* Building a test suite to check our own code

---

## Run
```./shell```

## Usage
* Prints a prompt and waits for a command from the user
* Creates a child process in which the command is checked
* Checks for built-ins, aliases in the PATH, and local executable programs
* The child process is replaced by the command, which accepts arguments
* When the command is done, the program returns to the parent process and prints the prompt
* The program is ready to receive a new command
* To exit: press Ctrl-D, Ctrl-C or enter "exit"
* Works also in non interactive mode

## Examples
```bash
($) /bin/ls
foo main.c README.md tests
```
```bash
($) pwd 
/home/vagrant/simple_shell
```
```bash
($) ls -l
total 60
drwxrwxr-x 7 vagrant vagrant  4096 Apr  7 01:48 0x15
-rw-rw-r-- 1 vagrant vagrant   148 Apr  7 00:00 free.c
-rwxrw-r-- 1 vagrant vagrant    28 Apr  7 15:35 ls.sh
```
```bash
($) potato
./shell: No such file or directory
```

## Authors

* **Laura Roudge** - [laura.derohan@gmail.com](https://github.com/lroudge)
* **Scout Curry** - [scurry222@gmail.com](https://github.com/scurry222)
