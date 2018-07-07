//
// ex01.hpp for ex01 in /home/pereni_j/Rendu/piscine_cpp_d15/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Wed Jan 20 10:56:36 2016 pereniguez joseph
// Last update Wed Jan 20 12:23:47 2016 pereniguez joseph
//

#ifndef __EX01_HPP__
#define __EX01_HPP__

#include <string>
#include <cstring>

template<typename T>
int	compare(const T &a, const T &b)
{
  if (a > b)
    return 1;
  if (a == b)
    return 0;
  return -1;
}

template<>
int	compare<const char*>(const char* const &a, const char* const &b)
{
  int	res;

  res = strcmp(a, b);
  if (res < 0)
    return -1;
  else if (res > 0)
    return 1;
  return 0;
}

#endif /* __EX01_HPP__ */
