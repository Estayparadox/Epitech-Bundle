##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Sat Jan 10 17:05:05 2015 Pereniguez Joseph
##

SRC    =	main.c		\
		raw_mode.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_puterror.c	\
		my_buffer.c	\
		call_putchar.c

CC     =	gcc

OBJ    =	$(SRC:.c=.o)

NAME   =	my_select

CFLAGS +=	-Werror -Wall -Wextra -pedantic -ansi -W

RM     =	rm -f

all    :	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -lncurses

clean  :	
		$(RM) $(OBJ)
		$(RM) *~

fclean :	clean
		$(RM) $(NAME)

re     :	fclean all

.PHONY :	all clean fclean re
