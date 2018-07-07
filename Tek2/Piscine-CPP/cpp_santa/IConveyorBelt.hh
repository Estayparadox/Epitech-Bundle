//
// IConveyorBelt.hh for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sun Jan 17 03:03:41 2016 Luca GUARNIERI
// Last update Sun Jan 17 05:50:29 2016 Luca GUARNIERI
//

#ifndef ICONVEYORBELT_HH_
# define ICONVEYORBELT_HH_

#include "Object.hh"
#include "Wrap.hh"
#include <iostream>
#include <string>

class		IConveyorBelt
{
public:
  IConveyorBelt();
  ~IConveyorBelt();
  virtual	Object *takeObject() = 0;
  virtual	void putObject(Object *) = 0;
  virtual	void pressIN() = 0;
  virtual	void pressOUT() = 0;
  virtual	const std::string look() const = 0;
  virtual	IConveyorBelt *createConveyorBelt() = 0;
};

#endif /* ICONVOYERBELT_HH_ */
