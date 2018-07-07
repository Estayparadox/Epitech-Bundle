//
// ElfOfPePeNoel.cpp for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sun Jan 17 05:22:00 2016 Luca GUARNIERI
// Last update Sun Jan 17 09:05:51 2016 Pierrick Dol
//

#include "ElfOfPePeNoel.hh"

ElfOfPePeNoel::ElfOfPePeNoel()
{
  std::cout << "Hello I'm your Elf for today, I'm ready to start wrapping your gifts !! :) " << std::endl;
}

ElfOfPePeNoel::~ElfOfPePeNoel()
{
std::cout << "Sorry but it seems you have no gift to wrap anymore :/, good bye !" << std::endl;
}

void	ElfOfPePeNoel::wrapGift(TablePePeNoel &table, ConveyorBeltPePeNoel const &conveyor)
{
  (void) conveyor;
  
  table.look();
  ((Wrap*)table.getObj(0))->openMe();
  if (((Wrap*)table.getObj(0))->isOpen() == true)
    std::cout << "The box is opened" << std::endl;
  ((Wrap*)table.getObj(0))->wrapMeThat(table.getObj(9));
  if (((Wrap*)table.getObj(9))->isOpen() == true)
    std::cout << "The '" << table.getObj(9)->getTitle() << "' is in the box" << std::endl;
  ((Wrap*)table.getObj(0))->closeMe();
  if (((Wrap*)table.getObj(0))->isOpen() == false)
    std::cout << "The box is closed" << std::endl;
  std::cout << "Whistles while working" << std::endl;
  ((Wrap*)table.getObj(2))->wrapMeThat(table.getObj(0));
    std::cout << "Everything went right, your gift is ready to be sent !! Merry Christmas to everyone :) !" << std::endl;
}
