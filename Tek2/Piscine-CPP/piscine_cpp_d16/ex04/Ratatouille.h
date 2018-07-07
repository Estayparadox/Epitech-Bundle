/*
** Ratatouille.h for Ratatouille in /home/pereni_j/Rendu/piscine_cpp_d16/ex04
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jan 21 20:03:56 2016 pereniguez joseph
** Last update Thu Jan 21 20:16:39 2016 pereniguez joseph
*/

#ifndef __RATATOUILLE_H__
#define __RATATOUILLE_H__

#include <iostream>
#include <sstream>
#include <string>

class			Ratatouille
{
 public:
  Ratatouille();
  Ratatouille(const Ratatouille &);
  virtual ~Ratatouille();
  Ratatouille		&addVegetable(unsigned char);
  Ratatouille		&addCondiment(unsigned int);
  Ratatouille		&addSpice(double);
  Ratatouille		&addSauce(std::string);
  std::string		kooc(void);
  Ratatouille		&operator=(const Ratatouille &);
 protected:
  std::stringstream	pot;
};

#endif /* __RATATOUILLE_H__ */
