##
## Makefile for  in /home/rosset_p/Piscine/piscine_cpp_d01/ex01
## 
## Made by Paul Rosset
## Login   <rosset_p@epitech.net>
## 
## Started on  Wed Jan  6 13:08:46 2016 Paul Rosset
## Last update Sun Jun 26 23:34:59 2016 Luca Guarnieri
##

CC_CLIENT	=	g++

CC_SERVER	=	gcc

RM		=	rm -f

CFLAGS		+=	-Wextra -Wall -Werror -W

NAME_CLIENT	=	zappy_ai

NAME_SERVER	=	zappy_server

SRCS_CLIENT	=	src_client/client.cpp		\
			src_client/Core.cpp		\
			src_client/Socket.cpp		\
			src_client/AI.cpp		\
			src_client/Inventaire.cpp

SRCS_SERVER	=	src_server/server.c		\
			src_server/socket.c		\
			src_server/main.c		\
			src_server/xfunct.c		\
			src_server/options.c		\
			src_server/check_opt.c		\
			src_server/setter.c		\
			src_server/setter_list.c	\
			src_server/funct.c		\
			src_server/fill_map.c		\
			src_server/aff_map.c

OBJS_CLIENT	=	$(SRCS_CLIENT:.cpp=.o)

OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)

all:			$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT)	:	$(OBJS_CLIENT)
			$(CC_CLIENT) $(OBJS_CLIENT) -o $(NAME_CLIENT) $(CFLAGS)

$(NAME_SERVER)	:	$(OBJS_SERVER)
			$(CC_SERVER) $(OBJS_SERVER) -o $(NAME_SERVER) $(CFLAGS)

clean		:
			$(RM) $(OBJS_CLIENT)
			$(RM) $(OBJS_SERVER)

fclean		:	clean
			$(RM) $(NAME_CLIENT)
			$(RM) $(NAME_SERVER)

re		:	fclean all

.PHONY		:	all clean fclean re
