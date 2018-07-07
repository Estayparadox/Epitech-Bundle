##
## Makefile for  in /home/guarni_l/cpp_santa
## 
## Made by Luca GUARNIERI
## Login   <guarni_l@epitech.net>
## 
## Started on  Sun Jan 17 06:37:25 2016 Luca GUARNIERI
## Last update Sun Jan 17 07:13:05 2016 Luca GUARNIERI
##

NAME = Santal_Goya

SRC = 	main.cpp			\
	Box.cpp				\
	ConveyorBeltPepeNoel.cpp	\
	ElfOfPePeNoel.cpp		\
	GiftPaper.cpp			\
	LittlePony.cpp			\
	Object.cpp			\
	TablePepeNoel.cpp		\
	Teddy.cpp			\
	Toy.cpp				\
	Wrap.cpp			\
	IElf.cpp			\
	ITable.cpp			\
	IConveyorBelt.cpp		\

CC = 		g++

RM =            rm -rf

OBJ =		$(SRC:.cpp=.o)

CXXFLAGS += -Wall -Werror -Wextra -W

all:     	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
		$(RM) $(OBJ)

fclean:         clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
