//
// Socket.hpp for  in /home/debern_d/2_rendu/PSU_2015_zappy/src_client
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Thu Jun 23 17:15:48 2016 Dylan Debernard
// Last update Sun Jun 26 18:07:35 2016 pereniguez joseph
//

#ifndef			__SOCKET_HPP__
# define		__SOCKET_HPP__

# include		"Core.hpp"

class			Socket : public Core
{
public:
  Socket();
  Socket(const int port, const std::string hostname);
  ~Socket();


protected:
  int _sock;
  struct sockaddr_in _server;
};

#endif			/* __SOCKET_HPP__ */
