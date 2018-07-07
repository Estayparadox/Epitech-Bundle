//
// ex02.hpp for ex02 in /home/pereni_j/Rendu/piscine_cpp_d15/ex02
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Wed Jan 20 12:07:31 2016 pereniguez joseph
// Last update Wed Jan 20 12:44:35 2016 pereniguez joseph
//

#ifndef __EX02_HPP__
#define __EX02_HPP__

#include <string>
#include <iostream>

int	min(int a, int b)
{
  std::cout << "non-template min" << std::endl;
  if (a <= b)
    return a;
  return b;
}

template<typename T>
const T &min(const T &a, const T &b)
{
  std::cout << "template min" << std::endl;
  if (a <= b)
    return a;
  return b;
}

int	nonTemplateMin(int *tab, int line)
{
  int	a;
  int	b;

  a = tab[0];
  b = 1;
  while (b < line)
    {
      a = min(a, tab[b]);
      b++;
    }
  return a;
}

template<typename T>
const T &templateMin(const T *tab, int line)
{
  T	&a = const_cast<T&>(tab[0]);
  int	b;

  b = 1;
  while (b < line)
    {
      a = min<T>(a, tab[b]);
      b++;
    }
  return a;
}

#endif /* __EX02_HPP__ */
