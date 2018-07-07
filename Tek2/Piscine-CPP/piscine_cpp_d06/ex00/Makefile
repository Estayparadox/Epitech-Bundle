##
## Makefile for Makefile in /home/pereni_j/Rendu/piscine_cpp_d06/ex00
## 
## Made by pereniguez joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Mon Jan 11 09:08:20 2016 pereniguez joseph
## Last update Mon Jan 11 10:41:41 2016 pereniguez joseph
##

SRC    =	my_cat.cpp

CC     =	g++

OBJ    =	$(SRC:.cpp=.o)

NAME   =	my_cat

CFLAGS +=	-W -Wall -Werror

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
