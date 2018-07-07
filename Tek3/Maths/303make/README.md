# 303make
## What's that ?
303make is a Python program that displays an adjacency matrix from a Makefile.
This matrix represent the degree of adjacence between rules and file in a makefile.
## How to use it ?
```
USAGE:
    ./303make makefile [file] [-h]
DESCRIPTION:
    file  the makefile you want to use.
    -h    help command.
```
### Example:
You have to use a particular synthax for your makefile:
```
>>> cat MakefileTest
tty: tty.o fc.o
cc -o tty tty.o fc.o

tty.o:  tty.c fc.h
cc -c tty.c

fc.o:  fc.c fc.h
cc -c fc.c
```
So here you can see the rules: tty, tty.o, fc.o; and the linked files to these rules: fc.c, fc.h, fc.o, tty.c, tty.h, tty.o.
If you run the program you will obtain:

```
>>> ./303make MakefileTest
[0 0 0 0 0 0]
[0 0 0 0 0 0]
[1 1 0 0 0 0]
[0 0 1 0 0 1] 
[0 0 0 0 0 0] 
[0 1 0 0 1 0]
```

    
