#include "allum.h"

int	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	my_putcharerror(char c)
{
  if (write(2, &c, 1) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	my_putstr(char *str)
{
  if (str) {
    while (*str) {
	  if (my_putchar(*str++) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
  }
  return (EXIT_FAILURE);
}

int	my_putstrerror(char *str)
{
  if (str) {
    while (*str) {
	  if (my_putcharerror(*str++) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
    return (EXIT_SUCCESS);
  }
  return (EXIT_FAILURE);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str) {
    while (*str++)
	    ++i;
    }
  return (i);
}
