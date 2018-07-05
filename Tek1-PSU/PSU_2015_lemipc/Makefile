##
## Makefile for  in /home/vatine_m/PSU/PSU_2015_lemipc
## 
## Made by vatinelle maxime
## Login   <vatine_m@epitech.net>
## 
## Started on  Sat Mar 26 14:03:26 2016 vatinelle maxime
## Last update Sat Mar 26 14:03:29 2016 vatinelle maxime
##

CC 	= 	gcc

RM 	=	rm -f

NAME 	=	lemipc

CFLAGS	+=	-Wextra -Wall -Werror -W

SRCS1 	= 	main.c		\
		my_error.c	\
		my_semaphore.c	\
		aff.c

OBJS 	= 	$(SRCS1:.c=.o)

all	: 	$(NAME)

$(NAME)	: 	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean	:
		$(RM) $(OBJS)

fclean	: 	clean	
		$(RM) $(NAME) *~

re	: 	fclean all

.PHONY	: 	all clean fclean re
