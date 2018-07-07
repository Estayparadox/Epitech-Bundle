# Automakefile
![badge1](https://img.shields.io/badge/license-MIT-brightgreen.svg)
![badge](https://img.shields.io/badge/language-Shell-b5e655.svg)

This program generate a Makefile from a configuration file.
## What's that ?
This is a shell script that generate a nice Makefile from a given configuration file for Epitech students.<br />
This Makefile contain the classic "clean", "fclean" and "re" rules.
## Configuration file ?
You need a configuration file with the flags you need to add to your project, with your personalised rules, your sources...<br />
Your configuration file can contain the following lines:
```
source_filename;dependence1 dependence2
PROJECT_DIR;name_of_the_project_root_folder
SOURCES_DIR;subfolder_containing_the_source_files
HEADERS_DIR;subfolder_containing_the_header_files
LIBS_DIR;subfolder_containing_librairies
EXEC;executable_name
CC;compilator_binary
CFLAGS;compilation_flag1 compilation_flag1...
LDFLAGS;linking_flag1 linking_flag2 ...
```
### This is a example of a configuration file:
```
main.c;fakeProj.h
EXEC;fakeProj
calc.c;calc/calc.h fakeProj.h
PROJECT_DIR;fakeProj
CC;clang
SOURCES_DIR;.
CFLAGS;-ftest-coverage -O2
LDFLAGS;
HEADERS_DIR;include
LIBS_DIR;libs
BCK_DIR;backup
ZIP;tar
ZIPFLAGS;-cvvf
UNZIP;tar
UNZIPFLAGS;-xvf
```
## How to use it ?
```
USAGE:
    ./automakefile.sh fakeProj/config
    
DESCRIPTION:
    fakeProj/config fakeProj/config is the adress of the configuration file to give as argument
```
