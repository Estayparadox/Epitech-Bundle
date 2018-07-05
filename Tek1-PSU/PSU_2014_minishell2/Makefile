##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Sun Mar  8 18:38:37 2015 Pereniguez Joseph
##

SRC    =	main.c		\
		my_puts.c	\
		my_strcmp.c	\
		search_ls.c	\
		search_oft.c	\
		search_oft2.c	\
		command.c	\
		search_cd.c	\
		search_more.c	\
		search_pipe.c	\
		exe_pipe.c

CC     =	gcc

OBJ    =	$(SRC:.c=.o)

NAME   =	mysh

CFLAGS +=	-Werror -Wall -Wextra -pedantic -ansi -W

RM     =	rm -f

all    :	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean  :
		$(RM) $(OBJ)
		$(RM) *~

fclean :	clean
		$(RM) $(NAME)

re     :	fclean all

.PHONY :	all clean fclean re
