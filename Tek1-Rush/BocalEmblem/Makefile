##
## Makefile for Makefile in /home/pereni_j/rendu/MUL_2014_wolf3d
## 
## Made by Pereniguez Joseph
## Login   <pereni_j@epitech.net>
## 
## Started on  Wed Dec  3 11:10:40 2014 Pereniguez Joseph
## Last update Sun May 17 13:36:12 2015 Jade Kadri
##

D1	=	I\ \:\ The\ Sacred\ Stones/

D2	=	II\ \:\ Path\ of\ Radiance/

CFLAGS	+=	-Werror -Wall -Wextra -I;/include
CFLAGS	+=	-ansi -pedantic

all    	:
		make -C $(D1)
		make -C $(D2)

clean  	:
		make clean -C $(D1)
		make clean -C $(D2)

fclean 	:
		make fclean -C $(D1)
		make fclean -C $(D2)

re     	:	fclean all

.PHONY 	:	all clean re fclean
