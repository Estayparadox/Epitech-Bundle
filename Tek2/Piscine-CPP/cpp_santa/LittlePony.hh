//
// LittlePony.hh for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sat Jan 16 12:34:59 2016 Luca GUARNIERI
// Last update Sun Jan 17 02:11:37 2016 Luca GUARNIERI
//

#ifndef LITTLEPONY_HH_
# define LITTLEPONY_HH_

# include "Toy.hh"

class		LittlePony : public Toy
{
public:
  LittlePony(std::string const &title = "", std::string const &type = "");
  //  LittlePony(LittlePony const &);
  ~LittlePony();

  void		isTaken() const;
};

#endif // LITTLEPONY_HH_
