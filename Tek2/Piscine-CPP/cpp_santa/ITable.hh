//
// ITable.hh for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sun Jan 17 04:25:02 2016 Luca GUARNIERI
// Last update Sun Jan 17 07:44:19 2016 Luca GUARNIERI
//

#ifndef ITABLE_HH_
# define ITABLE_HH_

# include "Object.hh"

class		ITable
{
public:
  ITable();
  ~ITable();
  virtual Object	*takeObject(std::string) = 0;
  virtual void		putObject(Object *) = 0;
  virtual std::string	*look() const = 0;
  virtual ITable	*createTable() = 0;
};

#endif /* CONVEYORBELTPEPENOEL_HH_ */
