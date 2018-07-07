/*
** Parser.h for Parser in /home/pereni_j/Rendu/piscine_cpp_d16/ex00
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jan 21 20:01:47 2016 pereniguez joseph
** Last update Thu Jan 21 20:01:48 2016 pereniguez joseph
*/


#ifndef __PARSER_H__
#define __PARSER_H__

#include <iostream>
#include <string>
#include <stack>

class			Parser
{
 public:
  Parser();
  Parser(const Parser &);
  virtual ~Parser();
  void			feed(const std::string &);
  int			result() const;
  void			reset();
 protected:
  std::stack<std::string> operators;
  std::stack<std::string> operands;
};

#endif /* __PARSER_H__ */
