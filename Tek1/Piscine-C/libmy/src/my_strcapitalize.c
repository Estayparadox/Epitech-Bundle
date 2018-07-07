/*
** my_strcapitalize.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "../include/my.h"

char		*my_strcapitalize(char *str)
{
  int		i;
  int		first_letter;
  int		word;

  i = 0;
  first_letter = 0;
  word = 0;
  while (str[i] != '\0')
    {
      if (!word && my_is_word_char(str[i]))
	{
	  word = 1;
	  str[i] = my_char_to_up(str[i]);
	}
      else if (word && my_is_word_char(str[i]))
	  str[i] = my_char_to_low(str[i]);
      else
	word = 0;
      i += 1;
    }
  return (str);
}
