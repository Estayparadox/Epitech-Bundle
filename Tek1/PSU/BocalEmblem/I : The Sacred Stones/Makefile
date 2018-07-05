##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Sat May 16 19:43:09 2015 Jade Kadri
##

SRC    	=	main.c			\
		map_data.c		\
		aff_elem.c		\
		count_x_y.c		\
		xmalloc.c		\
		lib.c			\
		my_str_to_wordtab.c	\
		my_str_to_wordtab_2.c

CC     	=	gcc

OBJ    	=	$(SRC:.c=.o)

NAME   	=	../binaries/strategic

CFLAGS 	+=	-Werror -Wall -Wextra -I./include
CFLAGS	+=	-ansi -pedantic

RM	=	rm -rf

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
