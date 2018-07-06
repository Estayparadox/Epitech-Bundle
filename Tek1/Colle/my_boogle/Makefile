##
## Makefile for Makefile in /home/pereni_j/Colle_6
## 
## Made by joseph pereniguez
## Login   <pereni_j@epitech.net>
## 
## Started on  Tue Jun  2 18:07:26 2015 joseph pereniguez
## Last update Tue Jun  2 21:42:32 2015 joseph pereniguez
##

SRC	=	main.c		\
		boogle.c	\
		my_boogle.c	\
		puts.c		\
		the_grid.c

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

RM	=	rm -rf

CFLAGS	+=	-Werror -Wextra -Wall -W
CFLAGS	+=	-pedantic -ansi
CFLAGS	+=	-I./include

NAME	=	my_boogle

all	:	$(OBJ)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean	:
		$(RM) *~
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean re fclean
