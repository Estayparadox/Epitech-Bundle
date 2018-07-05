##
## Makefile for Makefile in /home/pereni_j/rendu/PSU_2014_my_printf/sources
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Sun Nov 16 14:35:04 2014 Pereniguez Joseph
## Last update Sun Nov 16 18:59:37 2014 Pereniguez Joseph
##

SRC=	my_putchar.c \
	my_put_nbr.c \
	my_putnbr_base.c \
	my_putstr.c \
	my_strlen.c \
	fonctions_printf.c \
	fonctions_printf2.c \
	my_printf.c

OBJ=	$(SRC:.c=.o)

NAME=	libmy.a

RM= rm -f

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
