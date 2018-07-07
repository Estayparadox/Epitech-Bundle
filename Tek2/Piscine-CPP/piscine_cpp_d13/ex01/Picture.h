/*
** Picture.h for Picture in /home/pereni_j/Rendu/piscine_cpp_d13/ex00
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Mon Jan 18 10:31:08 2016 pereniguez joseph
** Last update Mon Jan 18 19:58:43 2016 pereniguez joseph
*/

#ifndef __PICTURE_H__
#define __PICTURE_H__

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

class			Picture
{
 public:
  Picture();
  Picture(const std::string &);
  Picture(Picture const &);
  Picture               &operator=(Picture const &);
  std::string		data;
  bool			getPictureFromFile(const std::string &);
};

#endif
