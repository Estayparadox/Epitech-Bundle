//
// TablePepeNoel.hh for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sun Jan 17 03:56:38 2016 Luca GUARNIERI
// Last update Sun Jan 17 07:44:22 2016 Luca GUARNIERI
//

#ifndef TABLEPEPENOEL_HH_
# define TABLEPEPENOEL_HH_

# include "LittlePony.hh"
# include "Teddy.hh"
# include "ConveyorBeltPepeNoel.hh"
# include "ITable.hh"

class		TablePePeNoel : public ITable
{
private:
  Object	**_obj;
  int		_length;

public:
  TablePePeNoel();
  Object		*getObj(int) const;
  virtual		~TablePePeNoel();
  virtual void		putObject(Object *);
  virtual Object	*takeObject(std::string);
  virtual std::string	*look() const;
  virtual ITable	*createTable();
};

#endif /* TABLEPEPENOEL_HH_ */
