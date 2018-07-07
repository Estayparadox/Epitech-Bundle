##
## Makefile for for eval_expr in /home/pereni_j/Piscine-C-eval_expr/
##
## Made by joseph pereniguez
## Login   <pereni_j@epitech.net>
##
## Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
## Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
##

CC	= gcc

RM	= rm -f

LIB     =   libmy.a

CFLAGS  +=  -Wextra -Werror -Wall
CFLAGS  +=  -pedantic

NAME	=   eval_expr

SRCS	=   doop.c \
	        my_format_str.c \
	        main.c \
	        my_fun.c \
	        my_int_to_string.c \
	        my_nbr.c \
	        my_parenth.c \
	        my_str.c \
	        my_wordtab_fun.c \
	        operations.c

OBJS	=   $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(LIB) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) *~

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all