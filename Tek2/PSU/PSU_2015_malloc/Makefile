##
## Makefile for  in /home/vatine_m/PSU/PSU_2015_malloc/tp
## 
## Made by vatinelle maxime
## Login   <vatine_m@epitech.net>
## 
## Started on  Thu Jan 28 14:09:11 2016 vatinelle maxime
## Last update Sun Feb 14 21:00:34 2016 pereniguez joseph
##

GCC      = 	gcc

RM      = 	rm -rf

CFLAGS  += 	-Wextra -Wall -Werror
CFLAGS  += 	-I.

NAME	=	libmy_malloc.so

SRCS    =	list.c			\
		malloc.c		\
		realloc.c		\
		show_alloc_mem.c	\
		free.c

OBJS    = 	$(SRCS:.c=.o)

CMP_LIB=	gcc -c -fPIC $(SRCS)

CREATE_LIB=	gcc -shared -fPIC -o $(NAME) $(OBJS)

all:		$(NAME)

$(NAME): 	$(OBJS)
		$(CMP_LIB)
		$(CREATE_LIB)

clean:
		$(RM) $(OBJS)
		$(RM) *~

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
