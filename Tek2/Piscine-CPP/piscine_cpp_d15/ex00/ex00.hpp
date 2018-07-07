//
// ex00.hpp for ex00 in /home/pereni_j/Rendu/piscine_cpp_d15/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Wed Jan 20 10:55:34 2016 pereniguez joseph
// Last update Wed Jan 20 11:16:02 2016 pereniguez joseph
//

#ifndef __EX00_HPP__
#define __EX00_HPP__

template<typename T>
void	swap(T& a, T& b)
{
  T	c;
  
  c = a;
  a = b;
  b = c;
}

template<typename T>
const T &min(const T &a, const T &b)
{
  if (a < b)
    return a;
  if (a > b)
    return b;
  return b;
}

template<typename T>
const T &max(const T &a, const T &b)
{
  if (a > b)
    return a;
  if (a < b)
    return b;
  return b;
}

template<typename T>
T add(const T &a, const T &b)
{
  T	result = a + b;
  
  return result;
}

#endif /* __EX00_HPP__ */
