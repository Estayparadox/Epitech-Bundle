//
// find.hpp for find in /home/pereni_j/Rendu/piscine_cpp_d17/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Fri Jan 22 09:15:42 2016 pereniguez joseph
// Last update Fri Jan 22 23:32:27 2016 pereniguez joseph
//

#ifndef __FIND_HPP__
#define __FIND_HPP__

#include <iostream>
#include <string>
#include <algorithm>

template<typename Container>
typename Container::iterator	do_find(Container &ref, int i)
{
  return std::find(ref.begin(), ref.end(), i);
}

#endif /* __FIND_HPP__ */
