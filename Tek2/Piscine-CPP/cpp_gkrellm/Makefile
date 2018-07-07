##
## Makefile for Makefile in /home/pereni_j/Rendu/cpp_gkrellm
## 
## Made by pereniguez joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Sat Jan 23 14:33:48 2016 pereniguez joseph
## Last update Sun Jan 24 06:13:31 2016 vatinelle maxime
##

SRC    =        IMonitorModule.cpp			\
		Time.cpp				\
		IMonitorDisplay.cpp			\
		OperatingModule.cpp			\
		MachineName.cpp				\
		Core.cpp				\
		Swap.cpp

SRC_FLY	=	dispFly.cpp

CC     =        g++

OBJ    =        $(SRC:.cpp=.o)

OBJ_FLY	=	$(SRC_FLY:.cpp=.o)

NAME   =	GKrellM

NAME_FLY =	DanAnimal

CFLAGS +=       -W -Wall -Werror -lncurses

CFLAGS_FLY +=       -W -Wall -Werror

RM     =        rm -f

all    :        $(NAME) $(NAME_FLY)

$(NAME):        $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

$(NAME_FLY):	$(OBJ_FLY)
		$(CC) $(OBJ_FLY) -o $(NAME_FLY) $(CFLAGS_FLY)

clean  :
		$(RM) $(OBJ) $(OBJ_FLY)
		$(RM) *~

fclean :	clean
		$(RM) $(NAME) $(NAME_FLY)

re     :	fclean all

.PHONY :	all clean fclean re
