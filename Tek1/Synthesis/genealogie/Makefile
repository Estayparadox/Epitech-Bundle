##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Fri Jul  3 10:19:59 2015 joseph pereniguez
##

SRC    	=	sources/main.c			\
		sources/tools.c			\
		sources/str_to_wordtab.c	\
		sources/str_to_wordtab2.c	\
		sources/str_to_wordtab3.c	\
		sources/op1.c			\
		sources/op2.c			\
		sources/op2_2.c

CC     	=	gcc

OBJ    	=	$(SRC:.c=.o)

NAME   	=	genealogie

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
