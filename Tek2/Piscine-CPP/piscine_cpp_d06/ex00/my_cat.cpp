//
// my_cat.cpp for my_cat in /home/pereni_j/Rendu/piscine_cpp_d06/ex00
//
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
//
// Started on  Mon Jan 11 11:38:34 2016 pereniguez joseph
// Last update Tue Feb 16 10:40:41 2016 pereniguez joseph
//

#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
  int i = 1;
  if (argc >= 2)
    {
      while (argv[i])
	{
	  std::ifstream file (argv[i]);
	  if (file.is_open())
	    {
	      char c = file.get();
	      while (file.good())
		{
		  std::cout << c;
		  c = file.get();
		}
	    }
	  else
	    std::cout << "my_cat: <file>: No such file or directory" << std::endl;
	  i++;
	}
    }
  else
    std::cout << "my_cat: Usage : ./my_cat file [...]" << std::endl;
  return (0);
}
