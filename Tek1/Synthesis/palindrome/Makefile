##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Sat Jun 27 09:59:48 2015 joseph pereniguez
##

SRC    	=	sources/tools.c			\
		sources/main.c			\
		sources/find_dec.c		\
		sources/find_base.c		\
		sources/my_putnbr_base.c	\
		sources/my_getnbr_base.c

CC     	=	gcc

OBJ    	=	$(SRC:.c=.o)

NAME   	=	palindrome

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
