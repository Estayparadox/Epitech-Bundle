//
// GiftPaper.cpp for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sat Jan 16 15:18:49 2016 Luca GUARNIERI
// Last update Sun Jan 17 07:38:06 2016 Luca GUARNIERI
//

#include "GiftPaper.hh"

GiftPaper::GiftPaper(std::string const &title, std::string const &type) : Wrap(title, type)
{

}

GiftPaper::~GiftPaper()
{

}

void    GiftPaper::wrapMeThat(Object *obj)
{
  if (_gift == NULL)
    {
      _gift = obj;
      std::cout << "**Wrapping the box** tuuuut tuuut tuut" << std::endl;
    }
  else
    std::cerr << "The box must be empty" << std::endl;
}
