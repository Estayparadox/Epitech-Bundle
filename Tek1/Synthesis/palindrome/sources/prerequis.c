/*
** prerequis.c for prerequis in /home/pereni_j/Rendu/palindrome
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jun 26 09:38:32 2015 joseph pereniguez
** Last update Fri Jun 26 10:31:52 2015 joseph pereniguez
*/

int		my_factrec_synthese(int nb)
{
  if (nb == 0)
    return (1);
  else if (nb < 0 || nb > 12)
    return (0);
  else
    return (nb * my_factrec_synthese(nb - 1));
}

int		my_squareroot_synthese(int nb)
{
  int		i;

  i = 0;
  if (nb == 1)
    {
      return (1);
    }
  while (i <= (nb / 2))
    {
      if ((i * i) == nb)
        {
          return (i);
        }
      i = i + 1;
    }
  return (-1);
}
