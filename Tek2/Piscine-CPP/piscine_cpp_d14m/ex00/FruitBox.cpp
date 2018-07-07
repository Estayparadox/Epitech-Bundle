//
// FruitBox.cpp for FruitBox.cpp in /home/pereni_j/Rendu/piscine_cpp_d14m/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Tue Jan 19 19:09:48 2016 pereniguez joseph
// Last update Tue Jan 19 19:47:15 2016 pereniguez joseph
//

#include "FruitBox.h"

FruitBox::FruitBox(int size) : _size(size), _header(NULL)
{
}

FruitBox::~FruitBox()
{
}

int			FruitBox::nbFruit() const
{
  return _count;
}

bool			FruitBox::putFruit(Fruit *fruit)
{
  if (_count < _size)
    {  
      FruitNode * current = _header;
      FruitNode * node = new FruitNode();
      node->box = fruit;
      if (!_header)
	_header = node;
      else
	{
	  while (current->next)
	    {
	      if (current->box == fruit)
		return false;
	      current = current->next;
	    }
	  current->next = node;
	}
      _count++;
      return true;
    }
  return false;
}

Fruit			*FruitBox::pickFruit()
{
  if (_count)
    {
      Fruit * fruit = _header->box;
      FruitNode * del = _header;
      _header = _header->next;
      delete del;
      _count--;
      return fruit;
    }
  return NULL;
}

FruitNode		*FruitBox::head() const
{
  return _header;
}
