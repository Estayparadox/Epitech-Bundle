//
// ex03.hpp for ex03 in /home/pereni_j/Rendu/piscine_cpp_d15/ex03
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Wed Jan 20 12:20:20 2016 pereniguez joseph
// Last update Wed Jan 20 12:43:53 2016 pereniguez joseph
//

#ifndef __EX03_HPP__
#define __EX03_HPP__

#include <string>
#include <iostream>

template<typename T>
void	foreach(const T *tab, void (func)(const T &), int line)
{
  int	i = 0;
  while (i < line)
    {
      (*func)(tab[i]);
      i++;
    }
}

template<typename T>
void	print(const T &a)
{
  std::cout << a << std::endl;
}

#endif /* __EX03_HPP__ */
