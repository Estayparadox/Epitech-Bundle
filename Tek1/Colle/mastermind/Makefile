##
## Makefile for Makefile in /home/pereni_j/Colle4
## 
## Made by joseph pereniguez
## Login   <pereni_j@epitech.net>
## 
## Started on  Thu May 21 20:13:41 2015 joseph pereniguez
## Last update Thu May 21 21:28:40 2015 joseph pereniguez
##

CC	=	gcc

SRC	=	main.c			\
		search_code.c		\
		my_puts.c		\
		funct_sup.c

CFLAGS	+=	-Werror -Wall -Wextra
CFLAGS	+=	-pedantic -ansi
CFLAGS	+=	-I./include

OBJ	=	$(SRC:.c=.o)

RM	=	rm -rf

NAME	=	my_mastermind

all	:	$(OBJ)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean	:
		$(RM) *~
		$(RM) *.o

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean re fclean
