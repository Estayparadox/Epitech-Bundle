//
// koalanurse.cpp for koalanurse in /home/pereni_j/Rendu/piscine_cpp_d06/ex03
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Mon Jan 11 22:26:44 2016 pereniguez joseph
// Last update Tue Jan 12 08:23:37 2016 pereniguez joseph
//

#include <fstream>
#include "koalanurse.h"

KoalaNurse::KoalaNurse(int id)
{
  this->id = id;
}

KoalaNurse::~KoalaNurse()
{
  std::cout << "Nurse " << this->id << ": Enfin un peu de repos !" << std::endl;
}

void            KoalaNurse::timeCheck()
{
  static bool   time;

  time = false;
  if (time == false)
    {
      std::cout << "Nurse " << this->id << ": Je commence le travail !" << std::endl;
      time = true;
    }
  else if (time == true)
    {
      std::cout << "Nurse " << this->id << ": Je rentre dans ma foret d'eucalyptus !" << std::endl;
      time = false;
    }
}

void		KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
  patient->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
  std::string patientName;
  std::string drugName;
  std::ifstream file;

  if (filename.substr(filename.find_last_of(".") + 1) == "report")
    {
      patientName = filename.substr(0, filename.find("."));
      file.open(filename.c_str());
      if (file.is_open())
	{
	  getline(file, drugName);
	  std::cout << "Nurse " << this->id << ": Kreog ! Il faut donner un " << drugName << " a Mr." << patientName << " !" << std::endl;
	  return drugName;
	}
    }
  return "";
}
