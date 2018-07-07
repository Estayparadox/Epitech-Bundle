/*
** Skat.h for Skat in /home/pereni_j/Downloads
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Jan 13 23:39:42 2016 pereniguez joseph
** Last update Wed Jan 13 08:42:58 2016 pereniguez joseph
*/

#ifndef	__SKAT_H__
#define __SKAT_H__

#include <string>
#include <iostream>

class		Skat
{
 private:
  std::string	_name;
 public:
  Skat(std::string const& name, int stimPaks);
  Skat(std::string const& name);
  Skat(int stimPaks);
  Skat();
  ~Skat();
  unsigned int	stimPaks();
  const std::string& name();
  int		_stimPaks;
  void		shareStimPaks(unsigned int number, unsigned int stock);
  void		addStimPaks(unsigned int number);
  void		useStimPaks();
  void		status();
};

#endif	/* __SKAT_H__ */
