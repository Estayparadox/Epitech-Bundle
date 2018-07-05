##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Fri Feb 20 10:03:15 2015 Pereniguez Joseph
##

SRC    =	main.c		\
		my_allum.c	\
		my_puts.c	\
		my_param_c.c	\
		my_pyramid.c	\
		my_check_tab.c	\
		my_funct.c	\
		my_funct2.c	\
		my_funct3.c	\
		my_funct4.c	\
		my_recap_aff.c

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
