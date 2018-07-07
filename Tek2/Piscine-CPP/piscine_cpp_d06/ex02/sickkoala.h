/*
** sickkoala.h for sickkoala in /home/pereni_j/Rendu/piscine_cpp_d06/ex02
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Mon Jan 11 15:48:52 2016 pereniguez joseph
** Last update Mon Jan 11 22:15:17 2016 pereniguez joseph
*/

#ifndef __SICKKOALA_H__
#define __SICKKOALA_H__

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <string>

class SickKoala
{
 private:
  std::string	name;
 public:
  SickKoala(std::string);
  ~SickKoala();
  void		poke();
  bool		takeDrug(std::string);
  void		overDrive(std::string);
};

#endif /* __SICKKOALA_H__ */
