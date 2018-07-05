##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Sat Jun 20 11:34:22 2015 joseph pereniguez
##

SRC    	=	sources/main.c			\
		sources/reader.c		\
		sources/my_puts.c		\
		sources/my_strtowordtab.c	\
		sources/xtrem_parser.c		\
		sources/super_finder.c		\
		sources/loop_inf.c		\
		sources/call_funct.c		\
		sources/call_funct2.c		\
		sources/ultra_tester.c

CC     	=	gcc

OBJ    	=	$(SRC:.c=.o)

NAME   	=	projTester

CFLAGS 	+=	-Werror -Wall -Wextra -W
CFLAGS	+=	-pedantic -ansi
CFLAGS	+=	-I./includes

RM     	=	rm -f

all    	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean  	:
		$(RM) $(OBJ)
		$(RM) *~

fclean 	:	clean
		$(RM) $(NAME)

re     	:	fclean all

.PHONY 	:	all clean fclean re
