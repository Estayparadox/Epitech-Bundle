/*
** Fruit.h for Fruit in /home/pereni_j/Rendu/piscine_cpp_d14m/ex00
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jan 19 09:07:18 2016 pereniguez joseph
** Last update Tue Jan 19 19:04:14 2016 pereniguez joseph
*/

#ifndef __FRUIT_H__
#define __FRUIT_H__

#include <iostream>
#include <string>

class			Fruit
{
 protected:
  std::string		_name;
  int			_vitamins;
  Fruit();
  Fruit(std::string const, int);
 public:
  virtual ~Fruit();
  int			getVitamins() const;
  std::string const	&getName() const;
};

#endif /* __FRUIT_H__ */
