##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Thu Jun 25 09:11:34 2015 joseph pereniguez
##

SRC    	=	sources/FASTAtools.c		\
		sources/tools.c			\
		sources/op1.c			\
		sources/op2.c			\
		sources/op3.c			\
		sources/op4.c			\
		sources/str_to_wordtab.c

CC     	=	gcc

OBJ    	=	$(SRC:.c=.o)

NAME   	=	FASTAtools

CFLAGS 	+=	-Werror -Wall -Wextra -W
CFLAGS	+=	-pedantic -ansi
CFLAGS	+=	-I./includes

RM     	=	rm -f

all    	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean  	:
		$(RM) $(OBJ)
		$(RM) *~

fclean 	:	clean
		$(RM) $(NAME)

re     	:	fclean all

.PHONY 	:	all clean fclean re
