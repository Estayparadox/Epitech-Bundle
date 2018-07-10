##
## Makefile for  in /home/arrazo_p/Systeme_Unix/PSU_2014_minishell1
## 
## Made by pedroantonio arrazolaleon
## Login   <arrazo_p@epitech.net>
## 
## Started on  Fri Jan 23 14:35:04 2015 pedroantonio arrazolaleon
## Last update Sat May 23 22:47:08 2015 Vatinelle Maxime
##

CC	=	gcc

RM	=	rm -f

CFLAGS  +=      -Wextra -Wall -Werror
CFLAGS  +=      -ansi -pedantic
CFLAGS  +=      -lmy -L./lib/
CFLAGS  +=      -D_BSD_SOURCE
CFLAGS  +=      -I./lib/

NAME	=	42sh

SRC	=	sources/main.c					\
		sources/my_putstr.c				\
		sources/my_strlen.c				\
		sources/my_str_to_wordtab.c			\
		sources/my_putchar.c				\
		sources/my_strcmp.c				\
		sources/xputstr.c				\
		sources/xmemset.c				\
		sources/xmalloc.c				\
		sources/my_strcat.c				\
		sources/signal.c				\
		sources/my_parse_env.c				\
		sources/my_cd.c					\
		sources/my_strlen_tab.c				\
		sources/check_error_double_redi_right.c		\
		sources/check_error_redi_left.c			\
		sources/check_error_redi_right.c		\
		sources/double_redi_right.c			\
		sources/redi_left.c				\
		sources/redi_right.c				\
		sources/my_builtins.c				\
		sources/parsing.c				\
		sources/my_strcpy.c				\
		sources/epur_str.c				\
		sources/my_echo.c				\
		sources/my_exec_prog.c

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@(cd ./lib/ && $(MAKE))
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean	:
		@(cd ./lib/ && $(MAKE) clean)
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) libmy.a
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
