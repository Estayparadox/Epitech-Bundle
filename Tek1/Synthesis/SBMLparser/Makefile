##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Mon Oct  2 00:32:32 2017 pereniguez joseph
##

SRC    	=	sources/main.c			\
		sources/my_puts.c		\
		sources/my_reader.c		\
		sources/prerequis.c		\
		sources/my_op.c			\
		sources/my_reade_op.c		\
		sources/my_reade_op2.c		\
		sources/my_wordtab_ofspace.c	\
		sources/my_aff_tribut.c		\
		sources/my_baliser_op.c		\
		sources/my_baliser_op2.c	\
		sources/my_takeword.c		\
		sources/my_equation.c

CC     	=	gcc

OBJ    	=	$(SRC:.c=.o)

NAME   	=	SBMLparser

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
