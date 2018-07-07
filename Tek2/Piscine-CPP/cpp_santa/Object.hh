//
// Object.hh for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sat Jan 16 10:50:34 2016 Luca GUARNIERI
// Last update Sun Jan 17 02:37:40 2016 Luca GUARNIERI
//

#ifndef OBJECT_HH_
# define OBJECT_HH_

# include <string>
# include <iostream>

class		Object
{
protected:
  const std::string	*_title;
  const std::string	*_type;
public:
  Object(std::string const &name = "", std::string const &title = "");
  //  Object(Object const &);
  virtual ~Object();
  const std::string		&getTitle() const;
  const std::string		&getType() const;
  Object			&operator=(Object const & );
};


#endif // OBJECT_HH_
