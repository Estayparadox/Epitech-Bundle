//
// Box.hh for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sat Jan 16 15:14:04 2016 Luca GUARNIERI
// Last update Sun Jan 17 02:18:09 2016 Luca GUARNIERI
//

#ifndef BOX_HH_
# define BOX_HH_

# include "Wrap.hh"

class	Box : public Wrap
{
public:
  Box(std::string const &title = "", std::string const &type = "");
  //  Box(Box const &);
  ~Box();

  virtual void	wrapMeThat(Object *);
};

#endif /* BOX_HH_  */
