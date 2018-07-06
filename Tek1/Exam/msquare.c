#include <unistd.h>

static char	square[9] = {0};
static int	sum = 0;

static int	my_strlen(char *s)
{
  int		i;

  i = -1;
  while (s[++i]);
  return i;
}

static int	fill_square(char *s)
{
  int		i;

  i = -2;
  while (i < my_strlen(s))
    {
      i += 2;
      if (s[i] == '?')
	continue ;
      if (s[i] < '1' || s[i] > '9')
	return (1);
      square[i / 2] = s[i] - '0';
    }
  return (1);
}

static int	check_diag()
{
  if (square[0] && square[4] && square[8])
    sum = square[0] + square[4] + square[8];
  if (square[2] && square[4] && square[6])
    {
      if (sum)
	return (sum == square[2] + square[4] + square[6]);
      else
	return (sum = square[2] + square[4] + square[6]);
    }
  return (1);
}

static int	check_row()
{
  int		i;

  for (i = 0; i < 9; i += 3)
    {
      if (square[i] && square[i + 1] && square[i + 2])
	{
	  if (sum &&
	      sum != square[i] + square[i + 1] + square[i + 2])
	    return (0);
	  else
	    sum = square[i] + square[i + 1] + square[i + 2];
	}
    }
  return (1);
}

static int	check_col()
{
  int		i;

  for (i = 0; i < 3; ++i)
    {
      if (square[i] && square[i + 3] && square[i + 6])
	{
	  if (sum &&
	      sum != square[i] + square[i + 3] + square[i + 6])
	    return (0);
	  else
	    sum = square[i] + square[i + 3] + square[i + 6];
	}
    }
  return (1);
}

static int	check_by_line(int i)
{
  int		j;
  int		val;

  val = 0;
  for (j = i - i % 3; j < i - i % 3 + 3; ++j)
    {
      if (j != i && !square[j])
	return (0);
      else
	val += square[j];
    }
  return (sum - val);
}

static int	check_by_col(int i)
{
  int		j;
  int		val;

  val = 0;
  for (j = i % 3; (unsigned)j < sizeof(square); j += 3)
    {
      if (j != i && !square[j])
	return (0);
      else
	val += square[j];
    }
  return (sum - val);
}

static int		check_first_diag(int i)
{
  int		j;
  int		val;

  val = 0;
  for (j = 0; (unsigned)j < sizeof(square); j += 4)
    {
      if (j != i && !square[j])
	return (0);
      else
	val += square[j];
    }
  return (sum - val);
}

static int	check_sec_diag(int i)
{
  int		j;
  int		val;

  val = 0;
  for (j = 2; j < 7; j += 2)
    {
      if (j != i && !square[j])
	return (0);
      else
	val += square[j];
    }
  return (sum - val);
}

static int	check_by_diag(int i)
{
  if (i == 0 || i == 8)
    return (check_sec_diag(i));
  else if (i == 2 || i == 6)
    return (check_first_diag(i));
  else if (i == 4)
    return (check_sec_diag(i) || check_first_diag(i));
  return (0);
}

static int	get_a_case(int i)
{
  if (!(square[i] = check_by_line(i))
      && !(square[i] = check_by_col(i))
      && !(square[i] = check_by_diag(i)))
    return (0);
  return (1);
}

static int	check_square()
{
  return (check_diag()
	  && check_row()
	  && check_col()
	  && sum);
}

static int	is_completed()
{
  int		i;

  for (i = 0; (unsigned)i < sizeof(square); ++i)
    if (!square[i])
      return (0);
  return (1);
}

static int	resolve_square()
{
  int		i;
  int		j;

  for (i = 0; (unsigned)i < sizeof(square); ++i)
    for (j = 0; (unsigned)j < sizeof(square); ++j)
      if (!square[j])
	get_a_case(j);
  return (is_completed());
}

static int	print_square()
{
  int		i;
  char		s[] = "0 ";

  for (i = 0; (unsigned)i < sizeof(square); ++i)
    {
      *s = square[i] + '0';
      if (write(1, s, sizeof(s) - 1) != sizeof(s) - 1)
	return (0);
    }
  return (write(1, "OK\n", 3) == 3);
}

int	main(int ac, char **av)
{
  if (ac != 2
      || my_strlen(av[1]) != 17
      || !fill_square(av[1])
      || !check_square()
      || !resolve_square()
      || !print_square())
    return (write(1, "KO\n", 3) && 1);
  return (0);
}
