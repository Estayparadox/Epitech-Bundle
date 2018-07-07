/*
** FruitNode.h for FruitNode in /home/pereni_j/Rendu/piscine_cpp_d14m/ex00
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jan 19 19:36:49 2016 pereniguez joseph
** Last update Tue Jan 19 19:45:52 2016 pereniguez joseph
*/

#ifndef __FRUITNODE_H__
#define __FRUITNODE_H__

#include <string>
#include <iostream>
#include "Fruit.h"

class		FruitNode
{
 public:
  Fruit		*box;
  FruitNode	*next;
};

#endif /* __FRUITNODE_H__ */
