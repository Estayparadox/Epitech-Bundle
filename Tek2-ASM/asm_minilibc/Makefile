##
## Makefile for Makefile in /home/pereni_j/Rendu/asm_minilibc
## 
## Made by pereniguez joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Sun Mar 27 17:59:37 2016 pereniguez joseph
## Last update Sun Mar 27 21:47:50 2016 pereniguez joseph
##

SRC	=	strchr.S	\
		memset.S	\
		strlen.S

CC	=	gcc

OBJ	=	$(SRC:.S=.o)

NAME	=	libasm.so

CFLAGS	=	-shared -fPIC -W -Wall

AS	=	./nasm -f elf

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean	:
		$(RM) $(OBJ)
		$(RM) *~

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
