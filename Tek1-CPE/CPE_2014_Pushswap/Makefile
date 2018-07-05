##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Sun Dec 14 20:38:50 2014 Pereniguez Joseph
##

SRC    =        my_getnbr.c		\
		my_putchar.c		\
		main.c			\
		s_funct.c		\
		p_funct.c		\
		r_funct	.c		\
		rr_funct.c		\
		pushswap.c		\
		my_putstr.c

CFLAGS =        -Wextra -Wall -Werror -pedantic

CC     =	gcc

OBJ    =	$(SRC:.c=.o)

NAME   =	push_swap

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
