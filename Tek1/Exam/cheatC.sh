#!/usr/bin/env bash

user='exam'

cd `dirname $0`

[ $# == 0 ] && echo "Usage: $0 file [login]" >&2 && exit 1
[ $# == 2 ] && user="$2"

choice() {
    read -r choice;
    if [ "$(tr [:upper:] [:lower:] <<< ${choice:0:1})" == 'y' ] || [ "$choice" == '' ]; then
	rm -fr -- $1
	echo -e "\033[32m$2 $(basename -- $1) deleted !\033[0m"
	return 0
    fi
    return 1
}

IFS='
'
for ex in $(grep -an '^Exercise [0-9]* *: ' -- $1); do
    nb=$(cut -d' ' -f2 <<< $ex)
    name=$(tr -s ' ' <<< $ex | cut -d':' -f3)
    name=${name:1}
    fileName=$(tail -n $(expr `wc -l -- $1 | cut -d' ' -f1` - $(cut -d':' -f1 <<< $ex)) $1 | grep -a 'name' | head -n 1 | rev | cut -d' ' -f1 | rev)

    if [ -d /home/$user/rendu/ex_$nb ]; then
	echo -en "\033[33mDirectory ex_$nb already exists ! Do you want to delete it ? (Y/n)\033[0m "
	choice /home/$user/rendu/ex_$nb 'Directory' || continue
    elif [ -f /home/$user/rendu/ex_$nb ]; then
	echo -en "\033[31mFile ex_$nb exists but is not a directory. Do you want to delete it ? (Y/n)\033[0m "
	choice /home/$user/rendu/ex_$nb 'File' || continue
    fi
    echo -n $nb - $name...' '
    if [ -f "$fileName" ] || [ -f "$fileName.c" ]; then
	mkdir -- /home/$user/rendu/ex_$nb
	if [ "${fileName: -2:2}" == '.c' ]; then
	    cp -- $fileName /home/$user/rendu/ex_$nb
	else
	    echo "NAME	= $fileName" > /home/$user/rendu/ex_$nb/Makefile
	    tail Makefile -n $(expr $(wc -l Makefile | cut -d' ' -f1) - 1) >> /home/$user/rendu/ex_$nb/Makefile
	    cp -- $fileName.c /home/$user/rendu/ex_$nb/main.c
	fi
	echo -e "\033[32mFound !\033[0m"
    else
	echo -e "\033[31mNot found :'(\033[0m"
    fi
done

[ -f /home/$user/rendu/auteur ] || echo "Don't forget your auteur file !"
