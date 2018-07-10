##
## Makefile for  in /home/pereni_j/Rendu/asm_minilibc
##
## Made by joseph pereniguez
## Login   <pereni_j@epitech.net>
##
## Started on  Sat Mar  5 19:12:10 2016 pereniguez joseph
## Last update Sun Mar 27 16:55:54 2016 pereniguez joseph
##

SRC	= strlen.S 	\
	  strncmp.S	\
	  strcmp.S	\
	  strcasecmp.S	\
	  memset.S	\
	  memcpy.S	\
	  memmove.S	\
	  putchar.S	\
	  putstr.S	\
	  strchr.S	\
	  strstr.S	\
	  rindex.S	\
	  strcspn.S	\
	  strpbrk.S

OBJ	= $(addprefix $(OBJDIR), $(SRC:.S=.o))

RM	= rm -f

NASM	= nasm
CC	= gcc

NAME	= libasm.so

OBJDIR	= obj/
SRCDIR	= src/
INCDIR	= -I includes/

MAKEOBJ		= obj

SFLAGS	= -f elf64
CFLAGS	= -W -Wall -Wextra -Werror -shared -fPIC

$(OBJDIR)%.o: $(SRCDIR)%.S
	@mkdir -p $(MAKEOBJ)
	$(NASM) $(SFLAGS) -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

all:
	@make --no-print-directory $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) -R $(OBJDIR)

re: fclean all
