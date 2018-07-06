##
## Makefile for Makefile in /home/pereni_j/Rendu/piscine_cpp_d01/ex01
## 
## Made by pereniguez joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Jan  6 13:28:49 2016 pereniguez joseph
## Last update Sun Feb 28 19:29:29 2016 pereniguez joseph
##

SRCOBJDUMP	=	objdump/main.c		\
			objdump/checker.c	\
			objdump/printer.c	\
			objdump/reader.c

SRCNM		=	nm/main.c

CC		=	gcc

OBJOBJDUMP	=	$(SRCOBJDUMP:.c=.o)

OBJNM		=	$(SRCNM:.c=.o)

NAMEOBJDUMP	=	my_objdump

NAMENM		=	my_nm

CFLAGS		+=	-Wextra -Werror -Wall

RM		=	rm -f

all		:	$(NAMEOBJDUMP) $(NAMENM)

$(NAMEOBJDUMP)	:	$(OBJOBJDUMP)
			$(CC) $(OBJOBJDUMP) -o $(NAMEOBJDUMP) $(CFLAGS)

$(NAMENM)	:	$(OBJNM)
			$(CC) $(OBJNM) -o $(NAMENM) $(CFLAGS)

objdump		:	$(OBJOBJDUMP)
			$(CC) $(OBJOBJDUMP) -o $(NAMEOBJDUMP) $(CFLAGS)

nm		:	$(OBJNM)
			$(CC) $(OBJNM) -o $(NAMENM) $(CFLAGS)

clean		:
			$(RM) $(OBJOBJDUMP) $(OBJNM)
			$(RM) *~

fclean		:	clean
			$(RM) $(NAMEOBJDUMP) $(NAMENM)

re		:	fclean all

.PHONY		:	all clean fclean re
