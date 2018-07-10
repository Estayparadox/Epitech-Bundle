##
## Makefile for Makefile in /home/arrazo_p/PSU_2014_my_printf
## 
## Made by pedroantonio arrazolaleon
## Login   <arrazo_p@epitech.net>
## 
## Started on  Fri Nov 14 18:23:52 2014 pedroantonio arrazolaleon
## Last update Tue Jan 27 15:14:02 2015 pedroantonio arrazolaleon
##

CFLAGS  +=      -Wextra -Wall -Werror
CFLAGS  +=      -ansi -pedantic
CFLAGS  +=      -I.

NAME	=	libmy.a

SRCS	=	my_printf.c		\
		my_fct.c		\
		my_count.c		\
		my_putchar_print.c	\
		my_put_nbr_print.c	\
		my_putstr_print.c	\
		my_putnbr_base.c	\
		my_fct2.c		\
		my_fct3.c		\
		my_putchar.c		\
		my_put_nbr.c

OBJ	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		ar -rc $(NAME) $(OBJ)
		ranlib $(NAME)
		cp $(NAME) ../
clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
