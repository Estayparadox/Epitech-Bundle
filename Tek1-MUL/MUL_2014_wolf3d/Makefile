##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Sat Dec 20 16:05:33 2014 Pereniguez Joseph
##

SRC    =	main.c		\
		color.c

CC     =	gcc

CFLAGS =	-Werror -Wall -Wextra -pedantic

OBJ    =	$(SRC:.c=.o)

NAME   =	wolf3d

RM     =	rm -f

all    :	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -lmlx -lXext -lX11

clean  :
		$(RM) $(OBJ)
		$(RM) *~

fclean :	clean
		$(RM) $(NAME)

re     :	fclean all

.PHONY :	all clean fclean re
