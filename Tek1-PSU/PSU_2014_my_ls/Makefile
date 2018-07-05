##
## Makefile for Makefile in /home/pereni_j/rendu/PSU_2014_my_ls
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Sun Nov 30 16:55:37 2014 Pereniguez Joseph
## Last update Sun Nov 30 17:39:43 2014 Pereniguez Joseph
##

SRC    =	my_ls.c \
		my_strlen.c \
		my_putchar.c \
		my_putnbr_base.c \
		my_putstr.c \
		my_put_nbr.c

NAME   =	my_ls

RM     =	rm -f

all    :	$(NAME)

$(NAME):	$(SRC)
		cc -o $(NAME) $(SRC) -lm

clean  :	
		$(RM) $(NAME)

fclean :	clean
		rm -f *~

re     :	fclean all

.PHONY :	all clean fclean re
