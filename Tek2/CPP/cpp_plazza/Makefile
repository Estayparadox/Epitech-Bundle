##
## Makefile for  in /home/rosset_p/Piscine/piscine_cpp_d01/ex01
## 
## Made by Paul Rosset
## Login   <rosset_p@epitech.net>
## 
## Started on  Wed Jan  6 13:08:46 2016 Paul Rosset
## Last update Sun Apr 24 15:17:27 2016 vatinelle maxime
##

CC      =	g++

RM      =	rm -f

CFLAGS  +=	-Wextra -Wall -Werror -W -lpthread
CXXFLAGS  +=	-std=c++11

NAME    =	plazza

SRCS    =	main.cpp	\
		Thread.cpp	\
		email_validator.cpp	\
		email.cpp	\
		Namedpipe.cpp	\
		Mutex.cpp	\
		Process.cpp

OBJS    =	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
