##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Sun Mar 22 10:57:29 2015 Pereniguez Joseph
##

SRCSERVER	=	server/main.c		\
			server/my_getnbr.c	\
			server/my_put_nbr.c	\
			server/my_puts.c	\
			server/my_pow.c

SRCCLIENT	=	client/main.c		\
			client/my_getnbr.c	\
			client/my_pow.c		\
			client/my_puts.c

CC		=	gcc

RM		=	rm -f

OBJSERVER	=	$(SRCSERVER:.c=.o)

OBJCLIENT	=	$(SRCCLIENT:.c=.o)

NAMESERVER	=	server/server

NAMECLIENT	=	client/client

CFLAGS		+=	-Werror -Wall -Wextra -pedantic -ansi -W -D_XOPEN_SOURCE -D_POSIX_C_SOURCE -D_POSIX_SOURCE -D_BSD_SOURCE

all		:	$(NAMESERVER) $(NAMECLIENT)

$(NAMESERVER)	:	$(OBJSERVER)
			$(CC) $(OBJSERVER) -o $(NAMESERVER) $(CFLAGS)

$(NAMECLIENT)	:	$(OBJCLIENT)
			$(CC) $(OBJCLIENT) -o $(NAMECLIENT) $(CFLAGS)

clean		:
			$(RM) $(OBJSERVER) $(OBJCLIENT)
			$(RM) *~

fclean		:	clean
			$(RM) $(NAMESERVER) $(NAMECLIENT)

re		:	fclean all

.PHONY		:	all clean fclean re
