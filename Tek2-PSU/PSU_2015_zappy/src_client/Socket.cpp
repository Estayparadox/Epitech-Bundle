//
// Socket.hpp for  in /home/debern_d/2_rendu/PSU_2015_zappy/src_client
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Thu Jun 23 17:15:48 2016 Dylan Debernard
// Last update Sun Jun 26 18:20:26 2016 pereniguez joseph
//

#include		"head/Socket.hpp"

Socket::Socket(const int port, const std::string hostname)
{
  if ((_sock = socket(AF_INET , SOCK_STREAM , 0)) == -1)
    {
      std::cerr << "Socket failed. Error" << std::endl;
      exit(1);
    }
  _server.sin_addr.s_addr = inet_addr(hostname.c_str());
  _server.sin_family = AF_INET;
  _server.sin_port = htons(port);
  if (connect(_sock, (struct sockaddr*)&_server, sizeof(_server)) < 0)
    {
      std::cerr << "connect failed. Error" << std::endl;
      exit(1);
    }
  std::cout << "Connected" << std::endl;
}

Socket::Socket()
{
}

Socket::~Socket()
{
}
