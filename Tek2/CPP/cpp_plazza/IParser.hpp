//
// IParser.hpp for  in /home/rosset_p/C++/plazza/cpp_plazza/parser2
// 
// Made by Paul Rosset
// Login   <rosset_p@epitech.net>
// 
// Started on  Fri Apr 22 11:23:32 2016 Paul Rosset
// Last update Sun Apr 24 15:25:06 2016 vatinelle maxime
//

#ifndef IPARSER_HPP
#define IPARSER_HPP

class IParser
{
public:
  virtual ~IParser() {}
  virtual bool  isCharacter(const char Character) = 0;
  virtual bool  isNumber(const char Character) = 0;
  virtual bool  isValidEmailAddress(const char * EmailAddress) = 0;
  virtual bool  isValidIPAddress(char * EmailAddress) = 0;
  virtual int   parserEA(std::string file, std::string catgr) = 0;
  virtual int   checkParser(std::string file, std::string catgr) = 0;
  virtual int   find_Enum(std::string file, std::string catgr) = 0;
};

#endif // IPARSER_HPP
