//
// Parser.hpp for  in /home/rosset_p/C++/plazza/cpp_plazza/parser2
//
// Made by Paul Rosset
// Login   <rosset_p@epitech.net>
//
// Started on  Thu Apr 21 16:31:58 2016 Paul Rosset
// Last update Sun Apr 24 16:00:16 2016 pereniguez joseph
//

#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <list>
#include <cctype>
#include <cstdlib>
#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include "IParser.hpp"

class Parser : public IParser
{
enum Information
  {
    PHONE_NUMBER,
    EMAIL_ADDRESS,
    IP_ADDRESS
  };

public:
  Parser();
  virtual	~Parser();
  virtual bool	isCharacter(const char Character);
  virtual bool	isNumber(const char Character);
  virtual bool	isValidEmailAddress(const char * EmailAddress);
  virtual int	parserEA(std::string file, std::string catgr);
  virtual int	parserIA(std::string file, std::string catgr);
  virtual int	checkParser(std::string file, std::string catgr);
  virtual int	find_Enum(std::string file, std::string catgr);
  virtual bool	isValidIPAddress(char *st);
};

#endif // PARSER_HPP
