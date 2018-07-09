##
## Makefile for  in /home/arrazo_p/tek2/trade
## 
## Made by pedroantonio arrazolaleon
## Login   <arrazo_p@epitech.net>
## 
## Started on  Sat Jun  4 10:22:46 2016 pedroantonio arrazolaleon
## Last update Sun Jun  5 21:58:09 2016 pereniguez joseph
##

NAME		=	trade

SRC		=	main.cpp	\
			Action.cpp	\
			SetGet.cpp	\
			Trade.cpp

OBJ		=	$(SRC:.cpp=.o)

RM		=	rm -rf

CC		=	g++

CFLAGS		=	-W -Wall -Wextra

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
