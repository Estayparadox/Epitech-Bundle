##
## Makefile for libmy in /home/pereni_j/libmy/src
##
## Made by joseph pereniguez
## Login   <pereni_j@epitech.net>
##
## Started on  Tue Oct 16 10:37:49 2015 joseph pereniguez
## Last update Tue Oct 16 16:27:48 2015 joseph pereniguez
##

SRC_DIR	=	src
SRC	    =   $(SRC_DIR)/my_putchar.c             \
	        $(SRC_DIR)/my_swap.c                \
      		$(SRC_DIR)/my_sort_int_array.c      \
      		$(SRC_DIR)/my_isneg.c               \
      		$(SRC_DIR)/my_put_nbr.c             \
      		$(SRC_DIR)/my_strcmp.c              \
      		$(SRC_DIR)/my_putstr.c              \
      		$(SRC_DIR)/my_strncmp.c             \
      		$(SRC_DIR)/my_strlen.c              \
      		$(SRC_DIR)/my_getnbr.c              \
      		$(SRC_DIR)/my_compute_power_rec.c   \
      		$(SRC_DIR)/my_compute_square_root.c \
      		$(SRC_DIR)/my_str_isalpha.c         \
      		$(SRC_DIR)/my_str_isnum.c           \
      		$(SRC_DIR)/my_is_prime.c            \
      		$(SRC_DIR)/my_find_prime_sup.c      \
      		$(SRC_DIR)/my_str_islower.c         \
      		$(SRC_DIR)/my_str_isupper.c         \
      		$(SRC_DIR)/my_str_isprintable.c     \
      		$(SRC_DIR)/my_showstr.c             \
      		$(SRC_DIR)/my_showmem.c             \
      		$(SRC_DIR)/my_strupcase.c           \
      		$(SRC_DIR)/my_strstr.c              \
      		$(SRC_DIR)/my_strlowcase.c          \
      		$(SRC_DIR)/my_strcapitalize.c       \
      		$(SRC_DIR)/my_strcpy.c              \
      		$(SRC_DIR)/my_strncpy.c             \
      		$(SRC_DIR)/my_revstr.c              \
      		$(SRC_DIR)/my_strcat.c              \
      		$(SRC_DIR)/my_strncat.c             \
      		$(SRC_DIR)/my_putnbr_base.c         \
            $(SRC_DIR)/my_print_hex.c           \
            $(SRC_DIR)/my_print_hex_str.c       \
            $(SRC_DIR)/my_count_nbr_digits.c    \
            $(SRC_DIR)/my_is_word_char.c        \
            $(SRC_DIR)/my_char_to_low.c         \
            $(SRC_DIR)/my_char_to_up.c          \
            $(SRC_DIR)/my_revstr_swap.c         \
            $(SRC_DIR)/my_memset.c              \
            $(SRC_DIR)/my_getnbr_base.c         \
            $(SRC_DIR)/my_get_digit_weight.c    \
            $(SRC_DIR)/my_find_first_digit.c    \
            $(SRC_DIR)/my_is_valid_digit.c      \
            $(SRC_DIR)/my_memcpy.c              \
            $(SRC_DIR)/my_puterr.c              \
            $(SRC_DIR)/my_strdup.c              \
            $(SRC_DIR)/my_xmalloc.c             \
            $(SRC_DIR)/my_strlcat.c             \
            $(SRC_DIR)/my_strndup.c             \
            $(SRC_DIR)/my_strtok.c              \
            $(SRC_DIR)/my_check_base.c          \
            $(SRC_DIR)/my_power_rec.c

NAME    =   libmy.a

OBJ	    =   $(SRC:.c=.o)

INCLUDE	=   include/my.h

all:	    $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:		clean
	rm -f $(NAME)

re:         fclean all

.PHONY:	    clean fclean re all
