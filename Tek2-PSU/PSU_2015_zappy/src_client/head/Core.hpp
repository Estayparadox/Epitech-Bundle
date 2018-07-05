//
// Core.hpp for  in /home/debern_d/2_rendu/zappy
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Mon Jun 20 10:42:31 2016 Dylan Debernard
// Last update Sun Jun 26 18:06:44 2016 pereniguez joseph
//

#ifndef			__CORE_HPP__
# define		__CORE_HPP__

# include		<iostream>
# include		<stdlib.h>
# include		<sys/socket.h>
# include		<arpa/inet.h>
# include		<stdio.h>
# include		<string.h>
# include		<unistd.h>

class			Core
{
public:
  Core(int ac, char **av);
  Core();
  ~Core();
  void			initClient();
  int			getPort();
  void			setPort(int port);

protected:
  std::string		_teamname;
  int			_port;
  std::string		_hostname;
};

#endif			/* __CORE_HPP__ */
