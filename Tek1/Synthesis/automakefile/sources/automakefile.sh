#!/bin/bash
if [ -z $1 ]
then
    echo -e "Pas de paramètre."
else
    echo -e "##\n## Makefile for Makefile in ${PWD##/}\n## \n## Made by ${USER}\n## Login   <${USER}@epitech.net>\n## \n## Started on $(date +%c) ${USER}\n## Las update $(date +%c) ${USER}\n##\n" >> Makefile
    for line in $(cat $1);
    do
	result=$(echo "$line" | cut -d ';' -f1)
	result2=$(echo "$line" | cut -d ';' -f2)
	calcul=$(echo "$result" | wc -c)
	if [ "SOURCES" = "$result" ]
	then
	    echo -e "$result		=	$result2\n" >> Makefile
	    echo -e "OBJ		=	\$(SRC:.c=.o)\n" >> Makefile
        elif [ "CFLAGS" = $result ]||[ "LDFLAGS" = $result ]
	then
	    echo -e "$result		+=	$result2\n" >> Makefile
	elif [ "ZIPFLAGS" = $result ]||[ "UNZIPFLAGS" = $result ]
	then
	    echo -e "$result	+=	$result2\n" >> Makefile
	else
	    if [ *".c" != $result ]
	    then
		if (("$calcul" >= 9))
		then
		    echo -e "$result	=	$result2\n" >> Makefile
		else
		    echo -e "$result		=       $result2\n" >> Makefile
		fi
	    fi
	fi
    done
    echo -e "all		:	\$(EXEC)\n" >> Makefile
    echo -e "\$(EXEC)		:	\$(OBJ)" >> Makefile
    echo -e "			\$(COMP) \$(OBJ) -o \$(EXEC) \$(CFLAGS)\n" >> Makefile
    echo -e "clean		:" >> Makefile
    echo -e "			\$(RM) \$(OBJ)" >> Makefile
    echo -e "			\$(RM) *~\n" >> Makefile
    echo -e "fclean		:       clean" >> Makefile
    echo -e "			\$(RM) \$(EXEC)\n" >> Makefile
    echo -e "re		:       fclean all\n" >> Makefile
    echo -e ".PHONY		:       all clean fclean re" >> Makefile
fi
