//
// Box.cpp for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sat Jan 16 15:13:32 2016 Luca GUARNIERI
// Last update Sun Jan 17 07:17:39 2016 Luca GUARNIERI
//

#include "Box.hh"

Box::Box(std::string const &name, std::string const &type) : Wrap(name, type)
{

}

Box::~Box()
{

}

void    Box::wrapMeThat(Object *obj)
{
  if ((isOpen() == true) && (_gift == NULL) && (obj != NULL))
    {
      _gift = obj;
      std::cout << "**Putting gift in the box** tuuuut tuuut tuut" << std::endl;
    }
  else
    {
      if (isOpen() == false)
	std::cerr << "[Error] : Box is not opened" << std::endl;
      else if (_gift != NULL)
	std::cerr << "[Error] : Box is full" << std::endl;
      else if (obj == NULL)
	std::cerr << "[Error] : You sent nothing. Please send something" << std::endl;
    }
}
