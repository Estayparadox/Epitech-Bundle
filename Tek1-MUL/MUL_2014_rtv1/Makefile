##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Thu Mar 12 16:09:58 2015 Pereniguez Joseph
##

SRC    =	main.c		\
		my_sphere.c	\
		my_put_pixel.c	\
		my_puts.c

CC     =	gcc

CFLAGS =	-Werror -Wall -Wextra -pedantic

OBJ    =	$(SRC:.c=.o)

NAME   =	rtv1

RM     =	rm -f

all    :	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -lmlx -lXext -lX11 -lm

clean  :
		$(RM) $(OBJ)
		$(RM) *~

fclean :	clean
		$(RM) $(NAME)

re     :	fclean all

.PHONY :	all clean fclean re
