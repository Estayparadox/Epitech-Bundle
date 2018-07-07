/*
** koalanurse.h for koalanurse in /home/pereni_j/Rendu/piscine_cpp_d06/ex03
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Mon Jan 11 22:39:50 2016 pereniguez joseph
** Last update Tue Jan 12 08:22:01 2016 pereniguez joseph
*/

#ifndef __KOALANURSE_H__
#define __KOALANURSE_H__

#include <iostream>
#include <string>
#include "sickkoala.h"

class	KoalaNurse 
{
 private:
  int	id;
 public:
  KoalaNurse(int);
  ~KoalaNurse();
  void	giveDrug(std::string, SickKoala*);
  void	timeCheck();
  std::string readReport(std::string);
};

#endif /* __KOALANURSE_H__ */
