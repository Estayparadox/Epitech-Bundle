/*
** Buzz.h for Buzz in /home/pereni_j/Rendu/piscine_cpp_d13/ex02
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Mon Jan 18 15:52:06 2016 pereniguez joseph
** Last update Mon Jan 18 20:32:43 2016 pereniguez joseph
*/

#ifndef __BUZZ_H__
#define __BUZZ_H__

#include <string>
#include <iostream>
#include "Toy.h"
#include "Picture.h"

class			Buzz : public Toy
{
 public:
  Buzz(std::string const &, std::string const & = "");
  virtual void		speak(std::string const &);
};

#endif /* __BUZZ_H__ */
