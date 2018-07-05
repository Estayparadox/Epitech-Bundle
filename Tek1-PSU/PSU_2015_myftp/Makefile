##
## Makefile for Makefile in /home/pereni_j/Rendu/PSU_2015_myftp
## 
## Made by pereniguez joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Thu May 12 23:39:03 2016 pereniguez joseph
## Last update Sun May 15 23:32:28 2016 pereniguez joseph
##

NAME		=	server

SRC_DIR		=	src/

SRC		=	$(SRC_DIR)main.c		\
			$(SRC_DIR)userCommands.c	\
			$(SRC_DIR)basicCommands.c	\
			$(SRC_DIR)addClient.c		\
			$(SRC_DIR)tools.c		\
			$(SRC_DIR)navCommands.c		\
			$(SRC_DIR)PGCommands.c	

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -W -pedantic -Iincludes -g

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)

clean		:
			rm -f $(OBJ)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
