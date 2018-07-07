//
// ConveyorBeltPepeNoel.hh for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sun Jan 17 03:14:35 2016 Luca GUARNIERI
// Last update Sun Jan 17 09:36:05 2016 Pierrick Dol
//

#ifndef CONVEYORBELTPEPENOEL_HH_
# define CONVEYORBELTPEPENOEL_HH_

# include "IConveyorBelt.hh"
# include "GiftPaper.hh"
# include "Box.hh"
# include <iostream>
# include <string>

class		ConveyorBeltPePeNoel : public IConveyorBelt
{
private:
  Object	*_gift;

public:
  ConveyorBeltPePeNoel();
  ~ConveyorBeltPePeNoel();
  virtual	Object *takeObject();
  virtual	void putObject(Object *);
  virtual	void pressIN();
  virtual	void pressOUT();
  virtual	const std::string look() const;
  virtual	IConveyorBelt *createConveyorBelt();
};

#endif /* CONVEYORBELTPEPENOEL_HH_ */
