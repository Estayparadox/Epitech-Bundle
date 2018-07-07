//
// main.cpp for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sat Jan 16 11:30:58 2016 Luca GUARNIERI
// Last update Sun Jan 17 09:36:30 2016 Pierrick Dol
//

#include "Toy.hh"
#include "LittlePony.hh"
#include "Teddy.hh"
#include "GiftPaper.hh"
#include "Box.hh"
#include "Wrap.hh"
#include "ConveyorBeltPepeNoel.hh"
#include "TablePepeNoel.hh"
#include "ElfOfPePeNoel.hh"

Object		**MyUnitTests()
{
  Object	**objArray = new Object*[2];

  objArray[0] = new LittlePony("gay pony");
  objArray[1] = new Teddy("bisounours");
  
  return objArray;
}

Object		*MyUnitTestsBis(Object **obj)
{
  ((Wrap *)obj[1])->openMe();
  ((Wrap *)obj[1])->wrapMeThat(obj[0]);
  ((Wrap *)obj[2])->wrapMeThat(obj[1]);
  
  return *obj;
}

std::ostream	&operator<<(std::ostream &os, const LittlePony &k)
{
  return (os << k.getTitle());
}

std::ostream	&operator<<(std::ostream &os, const Teddy &k)
{
  return (os << k.getTitle());
}

int	main()
{
  //Object	**unit = new Object *[4];
  TablePePeNoel table;
  ConveyorBeltPePeNoel conveyor;
  ElfOfPePeNoel elf;
  //Object	*unit2 = MyUnitTestsBis(unit);

  // unit[0] = new Teddy("Bear");
  // unit[1] = new Box("Playstation");
  // unit[2] = new GiftPaper("Paper");
  table.createTable();
  elf.wrapGift(table, conveyor);
  return 0;
}
