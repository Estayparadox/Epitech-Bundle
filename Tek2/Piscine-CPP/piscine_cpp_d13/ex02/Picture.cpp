//
// Picture.cpp for Picture in /home/pereni_j/Rendu/piscine_cpp_d13/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Mon Jan 18 11:16:16 2016 pereniguez joseph
// Last update Mon Jan 18 19:27:40 2016 pereniguez joseph
//

#include "Picture.h"

Picture::Picture() : data("")
{
}

Picture::Picture(const std::string & file)
{
  getPictureFromFile(file);
}

Picture::Picture(Picture const & content)
{
  data = content.data;
}

Picture		&Picture::operator=(Picture const & content)
{
  data = content.data;
  return *this;
}

bool		Picture::getPictureFromFile(const std::string & file)
{
  std::ifstream content(file.data());
  if (content.is_open())
    {
      std::stringstream buffer;
      buffer << content.rdbuf();
      data = buffer.str();
      content.close();
      return true;
    }
  data = "ERROR";
  return false;
}
