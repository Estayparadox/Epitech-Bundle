int	    my_getnbr(char *str)
{
  int	n;
  long	nb;
  int	c;

  n = 0;
  nb = 0;
  c = 1;

  while (str[n] == '-' || str[n] == '+') {
    if (str[n] == '-')
        c = c *(-1);
    n++;
  }

  while (str[n] != '\0') {
    if (str[n] < '0' || str[n] > '9')
	    return (nb * c);
    nb = nb * 10 + (str[n] - 48);
    if (nb > 2147483647 || nb < -214783648)
	    return (0);
    n++;
  }

  return (nb * c);
}
