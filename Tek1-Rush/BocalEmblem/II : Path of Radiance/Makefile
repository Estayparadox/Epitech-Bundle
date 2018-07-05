##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Sun May 17 16:28:51 2015 joseph pereniguez
##

SRC    	=	main.c			\
		puts.c			\
		puts2.c			\
		verify.c		\
		count_x_y.c		\
		my_str_to_wordtab.c	\
		my_str_to_wordtab_2.c	\
		commands.c		\
		rule.c			\
		aff_map.c		\
		aff_map2.c		\
		move.c

CC     	=	gcc

OBJ    	=	$(SRC:.c=.o)

NAME   	=	../binaries/playRadiance

CFLAGS 	+=	-Werror -Wall -Wextra -I./include
CFLAGS	+=	-ansi -pedantic

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
