##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Sun Dec 14 20:38:50 2014 Pereniguez Joseph
##

SRC    =        sources/my_getnbr.c		\
                sources/my_putchar.c	\
                sources/my_putstr.c     \
		        sources/main.c			\
		        sources/actions.c       \
		        sources/my_power_rec.c  \
		        sources/pushswap.c


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
