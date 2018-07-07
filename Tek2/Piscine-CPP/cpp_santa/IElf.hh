//
// IElf.hh for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sun Jan 17 05:09:03 2016 Luca GUARNIERI
// Last update Sun Jan 17 07:55:30 2016 Luca GUARNIERI
//

#ifndef IELF_HH_
# define IELF_HH_

# include "ConveyorBeltPepeNoel.hh"
# include "TablePepeNoel.hh"


class		IElf
{
public:
  IElf();
  ~IElf();
  virtual void wrapGift(TablePePeNoel &, ConveyorBeltPePeNoel const &) = 0;
};

#endif // IELF_HH_
