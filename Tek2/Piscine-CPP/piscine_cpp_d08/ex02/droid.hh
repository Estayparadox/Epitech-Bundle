//
// droid.hh for droid in /home/pereni_j/Rendu/piscine_cpp_d08/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Wed Jan 13 08:58:54 2016 pereniguez joseph
// Last update Wed Jan 13 20:44:26 2016 pereniguez joseph
//

#ifndef __DROID_HH__
#define __DROID_HH__

#include <string>
#include <iostream>

class		Droid
{
private:
  std::string		Id;
  size_t		Energy;
  size_t const		Attack;
  size_t const		Toughness;
  std::string		*Status;
public:
  Droid(std::string serial = "");
  Droid(Droid const &);
  ~Droid();
  bool		operator==(Droid const &) const;
  bool		operator!=(Droid const &) const;
  Droid&        operator<<(size_t &);
  Droid&	operator=(Droid const &);
  void		setId(std::string);
  void		setEnergy(size_t);
  void		setStatus(std::string*);
  std::string	getId() const;
  size_t        getEnergy() const;
  size_t	getAttack() const;
  size_t	getToughness() const;
  std::string   *getStatus() const;
};

std::ostream&	operator<<(std::ostream&, Droid const &);

#endif /* __DROID_HH__ */
