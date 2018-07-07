//
// Teddy.hh for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sat Jan 16 12:31:18 2016 Luca GUARNIERI
// Last update Sun Jan 17 02:12:38 2016 Luca GUARNIERI
//

#ifndef	TEDDY_HH_
# define TEDDY_HH_

# include "Toy.hh"

class		Teddy : public Toy
{
public:
  Teddy(std::string const &title = "", std::string const &type = "");
  //  Teddy(Teddy const &);
  ~Teddy();
  void		isTaken() const;
};

#endif	// TEDDY_HH_
