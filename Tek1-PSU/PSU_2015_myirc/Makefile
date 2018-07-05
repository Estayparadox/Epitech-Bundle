##
## Makefile for Makefile in /home/pereni_j/Rendu/PSU_2015_myirc
## 
## Made by pereniguez joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Tue May 17 09:14:13 2016 pereniguez joseph
## Last update Tue May 17 11:30:56 2016 pereniguez joseph
##

NAME_CLIENT	=	client

NAME_SERVER	=	server

SRC_DIR		=	src/

SRC_DIR_CLIENT	=	$(SRC_DIR)client/

SRC_DIR_SERVER	=	$(SRC_DIR)server/

SRC_CLIENT	=	$(SRC_DIR_CLIENT)main.c

SRC_SERVER	=	$(SRC_DIR_SERVER)main.c

OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

CFLAGS		=	-Wall -Wextra -W -pedantic -Iincludes -g

all		:	$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT)	:	$(OBJ_CLIENT)
			$(CC) $(OBJ_CLIENT) -o $(NAME_CLIENT)


$(NAME_SERVER)	:	$(OBJ_SERVER)
			$(CC) $(OBJ_SERVER) -o $(NAME_SERVER)


clean		:
			rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean		:	clean
			rm -f $(NAME_CLIENT) $(NAME_SERVER)

re		:	fclean all

.PHONY		:	all clean fclean re
