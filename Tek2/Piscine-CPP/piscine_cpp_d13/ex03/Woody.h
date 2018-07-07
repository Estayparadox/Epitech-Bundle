/*
** Woody.h for Woody in /home/pereni_j/Rendu/piscine_cpp_d13/ex02
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Mon Jan 18 16:58:14 2016 pereniguez joseph
** Last update Mon Jan 18 20:32:40 2016 pereniguez joseph
*/

#ifndef __WOODY_H__
#define __WOODY_H__

#include <iostream>
#include <string>
#include "Toy.h"

class			Woody : public Toy
{
 public:
  Woody(std::string const &, std::string const & = "");
  virtual void          speak(std::string const&);

};

#endif /* __WOODY_H__ */
