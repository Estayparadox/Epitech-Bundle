//
// main.cpp for main in /home/pereni_j/Transfert
//
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
//
// Started on  Thu Apr 14 12:21:15 2016 pereniguez joseph
// Last update Sun Apr 24 23:06:50 2016 pereniguez joseph
//

#include "Parser.hpp"

std::string		PN = "PHONE_NUMBER";
std::string		EA = "EMAIL_ADDRESS";
std::string		IA = "IP_ADDRESS";

int			Parser::checkParser(std::string file, std::string catgr)
{
  char			*myFile = (char *)file.c_str();
  std::ifstream		flux(myFile);

  if (flux)
    return 0;
  else
    return (-1);
}

int			Parser::find_Enum(std::string file, std::string catgr)
{
  std::string		catgr_no2d = catgr.substr(0, catgr.size()-1);

  if ((catgr_no2d.compare(PN) == 0) && (checkParser(file, catgr_no2d) == 0))
    {
    }
  if ((catgr_no2d.compare(EA) == 0) && (checkParser(file, catgr_no2d) == 0))
    parserEA(file, catgr);
  if ((catgr_no2d.compare(IA) == 0) && (checkParser(file, catgr_no2d) == 0))
    parserIA(file, catgr_no2d);
  else
    return -1;
  return 0;
}
