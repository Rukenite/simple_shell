# C - Simple Shell

## Background Context
A simple UNIX command interpreter.
![The gates of shell](shell.jpeg)
^ “The Gates of Shell”, by [Spencer Cheng](https://twitter.com/spencerhcheng/status/855104635069054977), featuring [Julien Barbier](https://twitter.com/julienbarbier42)

## Resources
**Read or watch:**

* [Unix shell](https://en.m.wikipedia.org/wiki/Unix_shell)
* [Thompson shell](https://en.m.wikipedia.org/wiki/Thompson_shell)
* [Ken Thompson](https://en.m.wikipedia.org/wiki/Ken_Thompson)

`man or help: sh` (Run sh as well)

### More Info
**Output**
- Program must have the exact same output as **sh** (`/bin/sh`) as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to your default program name `argv[0]` See below..

Example of error with `sh`:
```
$ echo "qwerty" | /bin/sh 
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
Same error with program `hsh`:
```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
```
#### Compilation
Shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
#### Testing
Shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
