# Epitech-Norme-Checker
![badge1](https://img.shields.io/badge/license-MIT-brightgreen.svg)
![badge2](https://img.shields.io/badge/language-Python-01B0F0.svg)
## What's that ?
This program is an Epitech norme checker that provide you an overview of your potential mistakes in your files.
## How to use it ?
```
USAGE:
    norme.py file [-nocheat] [-verbose] [-score] [-libc]

DESCRIPTION:
    file        the file you want to check
    -verbose    show "unable to open" messages
    -nocheat    disable cheat detection
    -score      display the number of mistake
    -libc       activates verification of libc
    -malloc     disable malloc verification
    -printline  display the line where is the mistake
    -return     activates function returns
    -comment    disable comment verification
```
## Some tips ?

So you can put norme.py in /usr/bin/ and make an alias to call it.
### Exemple:

Write this code in a file called norme.sh:
```
#!/bin/bash
norme.py $1 -nocheat -verbose -score
```
Then create a alias:
```
alias norme='~/aBasicFolder/norme.sh'
```
So 'norme.sh' is gonna call 'norme.py' when you'll call 'norme' like that:
```
>>>norme yourFile
```
