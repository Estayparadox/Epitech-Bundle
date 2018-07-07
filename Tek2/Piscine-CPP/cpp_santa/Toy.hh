//
// Toy.hh for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sat Jan 16 10:17:22 2016 Luca GUARNIERI
// Last update Sun Jan 17 02:10:34 2016 Luca GUARNIERI
//

#ifndef TOY_HH_
# define TOY_HH_

# include "Object.hh"

class		Toy : public Object
{
public:
  Toy(std::string const &title = "", std::string const &type = "");
  Toy(Toy const &);
  ~Toy();
};

#endif // TOY_HH_
