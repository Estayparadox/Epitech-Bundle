##
## Makefile for  in /home/debern_d/2_rendu/cpp_indie_studio
## 
## Made by Dylan Debernard
## Login   <debern_d@epitech.net>
## 
## Started on  Wed Apr 27 15:50:07 2016 Dylan Debernard
## Last update Mon Jun  6 22:38:59 2016 Dylan Debernard
##

CC		=	g++

RM		=	rm -rf

NAME		=	Hyper_Sprint

CPPFLAGS 	=	-I./irrlicht-1.8.3/include -I/usr/X11R6/include -I./include/ -I./irrKlang-64bit-1.5.0/include 

CXXFLAGS 	=	-W -Wall -Werror -Wextra -Wno-unused-parameter

LIBSELECT	=	64

LDFLAGS 	= 	-L/usr/X11R6/lib$(LIBSELECT) -L./irrlicht-1.8.3/lib/Linux -L"/usr/lib" ./irrKlang-64bit-1.5.0/bin/linux-gcc-64/libIrrKlang.so\
			-lIrrlicht -lGL -lXxf86vm -lXext -lX11 -lXcursor -lstdc++

SOURCES		=	sources/main.cpp		\
			sources/Core.cpp		\
			sources/Cars.cpp		\
			sources/Camera.cpp		\
			sources/PowerUp.cpp		\
			sources/Menu.cpp		\
			chronoscore/Chronometer.cpp 	\
			sources/screen.cpp		\
			sources/map.cpp			\
			sources/print.cpp		\
			sources/bot.cpp

OBJS		=	$(SOURCES:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(CPPFLAGS) $(CXXFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 		all re clean fclean
