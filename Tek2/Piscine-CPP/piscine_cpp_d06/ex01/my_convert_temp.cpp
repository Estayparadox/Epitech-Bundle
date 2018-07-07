#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

void		calc_fahrenheit(double nb)
{
  std::cout.width(16); std::cout << std::right << std::fixed << (nb * 9 / 5) + 32;
  std::cout.width(16); std::cout << std::right << std::fixed << "Fahrenheit" << std::endl;
}

void		calc_celsius(double nb)
{
  std::cout.width(16); std::cout << std::right << std::fixed << 5.0 / 9.0 * (nb - 32);
  std::cout.width(16); std::cout << std::right << std::fixed << "Celsius" << std::endl;
}

int		main(int argc, char **argv)
{
  double	nb;
  std::string	scale;

  std::cin >> nb >> scale;
  std::cout.precision(3);
  if (scale == "Celsius")
    calc_fahrenheit(nb);
  else if (scale == "Fahrenheit")
    calc_celsius(nb);
  return 0;
}
