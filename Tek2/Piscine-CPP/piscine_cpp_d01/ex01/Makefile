##
## Makefile for Makefile in /home/pereni_j/Rendu/piscine_cpp_d01/ex01
## 
## Made by pereniguez joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Jan  6 13:28:49 2016 pereniguez joseph
## Last update Wed Jan  6 15:00:29 2016 pereniguez joseph
##

SRC    =	main.c	\
		menger.c

CC     =	gcc

OBJ    =	$(SRC:.c=.o)

NAME   =	menger

CFLAGS +=	-Wextra -Werror -Wall -std=gnu99

RM     =	rm -f

all    :	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean  :
		$(RM) $(OBJ)
		$(RM) *~

fclean :	clean
		$(RM) $(NAME)

re     :	fclean all

.PHONY :	all clean fclean re
