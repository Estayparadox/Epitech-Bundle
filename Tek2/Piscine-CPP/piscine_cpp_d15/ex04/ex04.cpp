//
// ex04.cpp for ex04 in /home/pereni_j/Rendu/piscine_cpp_d15/ex04
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Wed Jan 20 13:25:12 2016 pereniguez joseph
// Last update Wed Jan 20 19:29:36 2016 pereniguez joseph
//

#include <iostream>
#include <string>
#include "ex04.hpp"

template<typename T>
bool	equal(const T &a, const T &b)
{
  return a == b;
}

template<typename T>
bool	Tester<T>::equal(const T &a, const T &b)
{
  return a == b;
}

template bool	equal<int>(const int &a, const int &b);
template bool	Tester<int>(const int &a, const int &b);

template bool	equal<double>(const double &a, const double &b);
template bool	Tester<double>(const double &a, const double &b);

template bool	equal<float>(const float &a, const float &b);
template bool	Tester<float>(const float &a, const flaot &b);

template bool	equal<std::string>(const std::string &a, const std::string &b);
template bool   Tester<std::string>(const std::string &a, const std::string &b);
