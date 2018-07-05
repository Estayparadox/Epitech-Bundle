##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Sun Feb  1 11:24:04 2015 Pereniguez Joseph
##

SRC    =	main.c		\
		my_puts.c	\
		my_strcmp.c	\
		search_ls.c	\
		search_oft.c	\
		search_oft2.c	\
		command.c	\
		search_cd.c

CC     =	gcc

OBJ    =	$(SRC:.c=.o)

NAME   =	mysh

CFLAGS +=	-Werror -Wall -Wextra -pedantic -ansi -W

RM     =	rm -f

all    :	$(NAME)
		@echo -e "\033[32;05m[$(NAME) has been created]\033[00m"

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

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
