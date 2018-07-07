//
// ElfOfPePeNoel.hh for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sun Jan 17 05:21:55 2016 Luca GUARNIERI
// Last update Sun Jan 17 07:54:58 2016 Luca GUARNIERI
//

#ifndef ELFOFPEPENOEL_HH_
#define ELFOFPEPENOEL_HH_

#include "IElf.hh"

class ElfOfPePeNoel : public IElf
{
public:
  ElfOfPePeNoel();
  ~ElfOfPePeNoel();
  virtual void wrapGift(TablePePeNoel &, ConveyorBeltPePeNoel const &);
};

#endif /* ELFOFPEPENOEL_HH_  */
