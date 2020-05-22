##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Fri Feb 20 10:03:15 2015 Pereniguez Joseph
##

SRC    =	sources/main.c		    \
		    sources/player.c	    \
		    sources/my_prints.c	    \
		    sources/my_getnbr.c	    \
		    sources/my_put_nbr.c	\
		    sources/get_next_line.c	\
		    sources/bot.c	        \
		    sources/check.c	        \
		    sources/display.c

CC     =	gcc

OBJ    =	$(SRC:.c=.o)

NAME   =	allum1

CFLAGS +=	-Werror -Wall -Wextra -pedantic -ansi -W

RM     =	rm -f

all    :	$(NAME)
		@echo -e "\033[32;05m[$(NAME) has been created]\033[00m"

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -lncurses

clean  :
		@echo -e "\033[32;05m[Deleting object files]\033[00m"
		$(RM) $(OBJ)
		@echo -e "\033[32;05m[Removing copy]\033[00m"
		$(RM) *~

fclean :	clean
		$(RM) $(NAME)
		@echo -e "\033[32;05m[$(NAME) has been deleted]\033[00m"

re     :	fclean all

.PHONY :	all clean fclean re
