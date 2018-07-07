/*
** Toy.h for Toy in /home/pereni_j/Rendu/piscine_cpp_d13/ex00
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Mon Jan 18 10:47:35 2016 pereniguez joseph
** Last update Mon Jan 18 20:15:17 2016 pereniguez joseph
*/

#ifndef __TOY_H__
#define __TOY_H__

#include <iostream>
#include <fstream>
#include <string>
#include "Picture.h"

class			Toy
{
 public:
  enum			ToyType
  {
    BASIC_TOY,
    ALIEN,
    BUZZ,
    WOODY
  };
  Toy();
  Toy(ToyType, std::string const &, std::string const &);
  Toy(Toy const &);
  Toy			&operator=(Toy const &);
  ToyType               getType() const;
  std::string const     &getName() const;
  void                  setName(std::string const &);
  bool                  setAscii(const std::string &);
  std::string const     &getAscii() const;
 private:
  ToyType		_type;
  std::string		_name;
  Picture		_picture;
};

#endif /* __TOY_H__ */
