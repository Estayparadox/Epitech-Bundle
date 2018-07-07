/*
** FruitBox.h for FruitBox in /home/pereni_j/Rendu/piscine_cpp_d14m/ex00
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jan 19 09:28:39 2016 pereniguez joseph
** Last update Tue Jan 19 19:41:10 2016 pereniguez joseph
*/

#ifndef __FRUITBOX_H__
#define __FRUITBOX_H__

#include <string>
#include <iostream>
#include "FruitNode.h"
#include "Fruit.h"

class			FruitBox
{
 protected:
  int			_size;
  int			_count;
  FruitNode		*_header;
 public:
  FruitBox(int size);
  virtual ~FruitBox();
  int			nbFruit() const;
  bool			putFruit(Fruit *);
  Fruit			*pickFruit();
  FruitNode		*head() const;
};

#endif /* __FRUITBOX_H__ */
