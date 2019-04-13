# 0x15. C - Simple Shell


		        	           _.-''|''-._
	        			.-'     |     `-.
				      .'\       |       /`.
				    .'   \      |      /   `.
     _          _ _ 		    \     \     |     /     /
    | |        | | |		     `\    \    |    /    /'
 ___| |__   ___| | |		       `\   \   |   /   /'
/ __| '_ \ / _ \ | |		         `\  \  |  /  /'
\__ \ | | |  __/ | |		        _.-`\ \ | / /'-._
|___/_| |_|\___|_|_|		       {_____`\\|//'_____}
		    		               `-'

## Description
This team project is part of the first year curriculum of Holberton School.
Simple Shell is a command line interpreter that replicates the **sh** program.

What we learned:
* How a shell works and finds commands
* Creating, forking and working with processes
* Executing a program from another program
* Handling dynamic memory allocation in a large program
* Pair programming and team work
* Building a test suite to check our own code

---

## Compile and run
```gcc -Wall -Werror -Wextra -pedantic *.c -o hsh```
```./hsh```

## Usage
* Prints a prompt and waits for a command from the user
* Creates a child process in which the command is checked
* Checks for built-ins, aliases in the PATH, and local executable programs
* The child process is replaced by the command, which accepts arguments
* When the command is done, the program returns to the parent process and prints the prompt
* The program is ready to receive a new command
* To exit: press Ctrl-D or enter "exit" (with or without a status)
* Works also in non interactive mode

## Examples
```bash
$ /bin/ls
foo main.c coquille.c README.md tests croissant.c
```
```bash
$ pwd 
/home/vagrant/simple_shell
```
```bash
$ ls -l
total 60
drwxrwxr-x 7 vagrant vagrant  4096 Apr  7 01:48 foo
-rw-rw-r-- 1 vagrant vagrant   148 Apr  7 00:00 main.c
-rwxrw-r-- 1 vagrant vagrant    28 Apr  7 15:35 coquille.c
```
```bash
$ baguette
./hsh: No such file or directory
```
```bash
$ echo "cat testfile" | ./hsh
This is a test file
```
## Files

File | Content
---- | -----------
[main.c](./main.c) | entry point, executing function
[shell.h](./shell.h) | function protoypes, standard libraries
[print_funcs.c](./print_funcs.c) | printing functions
[string_funcs.c](./string_funcs.c) | string-handling functions
[tokenize.c](./tokenize.c) | string to tokens parsing functions
[path_finder.c](./path_finder.c) | functions that check the PATH for commands
[builtins.c](./builtins.c) | functions dealing with the shell builtins
[helper_funcs.c](./helper_funcs.c) | memory and signal handling functions
[convert_funcs.c](./convert_funcs.c) | conversion between string and number functions
[man_1_simple_shell](./man_1_simple_shell) | Simple Shell man page (```man ./man_1_simple_shell```)

## Authors

* **Laura Roudge** - [laura.derohan@gmail.com](https://github.com/lroudge)
* **Scout Curry** - [scurry222@gmail.com](https://github.com/scurry222)
