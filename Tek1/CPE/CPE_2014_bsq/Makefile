##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Sun Jan 18 19:24:32 2015 Pereniguez Joseph
##

SRC    =	main.c		\
		my_puterror.c	\
		my_putstr.c	\
		my_strlen.c

CC     =	gcc

OBJ    =	$(SRC:.c=.o)

NAME   =	bsq

CFLAGS +=	-Werror -Wall -Wextra -pedantic -ansi -W

RM     =	rm -f

all    :	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean  :	
		$(RM) $(OBJ)
		$(RM) *~

fclean :	clean
		$(RM) $(NAME)

re     :	fclean all

.PHONY :	all clean fclean re
