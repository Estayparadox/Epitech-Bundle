//
// Parser.cpp for Parser in /home/pereni_j/Rendu/piscine_cpp_d16/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Thu Jan 21 20:01:35 2016 pereniguez joseph
// Last update Thu Jan 21 20:01:38 2016 pereniguez joseph
//

#include "Parser.h"

Parser::Parser()
{
  result = 0;
}

Parser::Parser(const Parser & source)
{
  operators = source.operators;
  operands = source.operands;
  result = source.result;
}

Parser::~Parser()
{
}

void		Parser::feed(const std::string &operation)
{
  my_op(std::string("(") + opearation + ")");
}

int		Parser::result() const
{
  return result;
}

void		Parser::reset()
{
  std::stack<std::string> clear;
  operators = clear;
  operatands = clear;
  result = 0;
}
