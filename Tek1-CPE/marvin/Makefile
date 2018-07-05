##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Sun Jan  4 23:28:54 2015 georges valentin
##

SRC    =	main.c		\
		my_putchar.c	\
		my_putstr.c	\
		fonction.c	\
		my_strcomp.c	\
		check_error.c	\
		var_type.c	\
		var_name.c	\
		proto5.c	\
		param.c					

CC     =	gcc

OBJ    =	$(SRC:.c=.o)

NAME   =	marvin

CFLAGS =	-Werror -Wall -Wextra -pedantic

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
