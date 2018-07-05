##
## Makefile for  in /home/vatine_m/PSU/PSU_2015_philo
## 
## Made by vatinelle maxime
## Login   <vatine_m@epitech.net>
## 
## Started on  Tue Mar  8 09:29:31 2016 vatinelle maxime
## Last update Sun Mar 13 16:18:26 2016 vatinelle maxime
##

GCC      = 	gcc

RM      = 	rm -rf

CFLAGS  += 	-Wextra -Wall -Werror

NAME	=	philo

LDFLAGS	=	-L. -lriceferee -lpthread

SRCS    =	philo.c	\
		algo.c

OBJS    = 	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME): 	$(OBJS)
		$(GCC) $(OBJS) -o $(NAME) $(LDFLAGS) $(CFLAGS)

clean:
		$(RM) $(OBJS)
		$(RM) *~

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
