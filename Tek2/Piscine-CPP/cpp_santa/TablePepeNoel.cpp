//
// TablePepeNoel.cpp for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sun Jan 17 04:01:28 2016 Luca GUARNIERI
// Last update Sun Jan 17 07:44:30 2016 Luca GUARNIERI
//

#include "TablePepeNoel.hh"

TablePePeNoel::TablePePeNoel()
{
  int	i;

  i = 0;
  _length = 10;
  _obj = new Object *[10];
  while (i < 10)
    {
      _obj[i] = NULL;
      i++;
    }
}

TablePePeNoel::~TablePePeNoel()
{
  int	i;

  i = 0;
  while (i < 10)
    {
      _obj[i] = NULL;
      delete _obj[i];
      i++;
    }
  delete _obj;
}

ITable	*TablePePeNoel::createTable()
{
  ITable	*newTable;

  newTable = new TablePePeNoel;

  _obj[0] = new Box;
  _obj[1] = new Teddy("Bear");
  _obj[2] = new GiftPaper;
  _obj[3] = new Teddy("Squalifiaient");
  _obj[4] = new LittlePony("Morphisme");
  _obj[5] = new Box;
  _obj[6] = new LittlePony("Findus");
  _obj[7] = new GiftPaper;
  _obj[8] = new Teddy("Tamgho");
  _obj[9] = new LittlePony("Fernanda");
  _obj[10] = NULL;
  return newTable;
}

std::string	*TablePePeNoel::look() const
{
  std::string	*getTable = new std::string[10];
  int	i;

  i = 0;
  while (i < _length)
    {
      getTable[i] = _obj[i]->getType();
      if ((getTable[i] == "LittlePony") || (getTable[i] == "Teddy"))
	std::cout << "The gift is a "  << _obj[i]->getType() << " and his name is " << _obj[i]->getTitle() << std::endl;
      else if ((getTable[i] == "Box") || (getTable[i] == "GiftPaper"))
	std::cout << "This is a " << _obj[i]->getType() << std::endl;
      i++;
    }
  return getTable;
}

Object	*TablePePeNoel::getObj(int i) const
{
  return _obj[i];
}

void	TablePePeNoel::putObject(Object *obj)
{
  int	i;

  i = 0;
  while (i < _length)
    {
      if (_obj[i] == NULL)
	_obj[i] = obj;
      i++;
    }
}

Object		*TablePePeNoel::takeObject(std::string type)
{
  int		i;
  Object	*newGift = new Object;

  while (_obj[i])
    {
      if (_obj[i]->getType() == type)
	{
	  newGift = _obj[i];
	  _obj[i] = NULL;
	}
      i++;
    }
  _length = _length - 1;
  return newGift;
}
