//
// Wrap.hh for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sat Jan 16 14:37:19 2016 Luca GUARNIERI
// Last update Sun Jan 17 07:18:04 2016 Luca GUARNIERI
//

#ifndef WRAP_HH_
# define WRAP_HH_

# include "Object.hh"

class	Wrap : public Object
{
protected:
  Object	*_gift;
  bool		_open;
public:
  Wrap(std::string const &title = "", std::string const &type = "");
  ~Wrap();
  void  closeMe();
  void  openMe();
  bool  isOpen();
  bool	isWrapped();
  Wrap	&operator=(Wrap const &);
  virtual void	wrapMeThat(Object *) = 0;
};

#endif /* WRAP_HH_ */
