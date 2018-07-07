//
// ConveyorBeltPepeNoel.cpp for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sun Jan 17 03:18:13 2016 Luca GUARNIERI
// Last update Sun Jan 17 09:35:57 2016 Pierrick Dol
//

#include "ConveyorBeltPepeNoel.hh"

ConveyorBeltPePeNoel::ConveyorBeltPePeNoel() : _gift(NULL)
{

}

ConveyorBeltPePeNoel::~ConveyorBeltPePeNoel()
{

}


Object		*ConveyorBeltPePeNoel::takeObject()
{
  Object	*newGift;

  newGift = _gift;
  return newGift;
}

void		ConveyorBeltPePeNoel::putObject(Object *obj)
{
  _gift = obj;
}

void		ConveyorBeltPePeNoel::pressIN()
{
  putObject(new GiftPaper);
}

void		ConveyorBeltPePeNoel::pressOUT()
{
  _gift = NULL;
}

const std::string	ConveyorBeltPePeNoel::look() const
{
  return _gift->getType();
}

IConveyorBelt	*ConveyorBeltPePeNoel::createConveyorBelt()
{
  IConveyorBelt	*newGift = new ConveyorBeltPePeNoel;
  return newGift;
}
