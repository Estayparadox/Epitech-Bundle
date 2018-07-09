//
// Chronometer.cpp for Chronometer in /home/pereni_j/Rendu/tools
//
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
//
// Started on  Wed May  4 12:56:33 2016 pereniguez joseph
// Last update Thu Apr  6 14:36:42 2017 pereniguez joseph
//

#include "Chronometer.hh"

Score::Score() : mil(0), sec(0), min(0)
{
}

Score::~Score()
{
}

void		Score::scoreWritter(std::string playerName, std::string filename)
{
  std::ofstream fileChrono(filename.c_str(), std::ios::app);

  if (fileChrono)
    {
      fileChrono << playerName << "         ";
      if (this->min < 10)
	fileChrono << "0" << this->min << ":";
      if (this->min >= 10)
	fileChrono << this->min << ":";
      if (this->sec < 10)
	fileChrono << "0" << this->sec <<":";
      if (this->sec >= 10)
	fileChrono << this->sec << ":";
      if (this->mil < 10)
	fileChrono << "0" << this->mil << std::endl;
      if (this->mil >= 10)
	fileChrono << this->mil << std::endl;
      fileChrono.close();
    }
  else
    std::cerr << "File not found." << std::endl;
}

std::map<std::string, int>              Score::PushTab(std::string filename)
{
  std::ifstream                     f1(filename.c_str());
  std::map<std::string,int>             Tab;
  if (f1)
    {
      std::string                   fW1;
      std::string                   Dictionary;
      int                           Value;
      std::map<std::string, int>            scoreTab;
      int                           cpt = -1;

      while (f1 >> fW1)
	{
	  for (unsigned int i = 0; i < fW1.size(); i++)
	    {
	      if (fW1[i] == ':')
		fW1.erase(i, 1);
	    }
	  if ((cpt % 2) != 0)
	    Dictionary = fW1;
	  if ((cpt % 2) == 0)
	    {
	      Value = atoi(fW1.c_str());
	      scoreTab[Dictionary] = Value;
	    }
	  cpt = cpt + 1;
	}
      Tab = scoreTab;
    }
  return (Tab);
}

void				Score::recup(int minutes, int seconde, int miliseconde)
{
  this->mil = miliseconde;
  this->sec = seconde;
  this->min = minutes;
}

int      func_classic(std::pair<std::string, int> const & a, std::pair<std::string, int> const & b) // fonction de tri score mode classic
{
  return a.second != b.second? a.second < b.second : a.first < b.first;
}

void                    Score::sortTab(std::map<std::string, int> scoreTab, std::string mode, Core core, std::string filename)
{
  std::ofstream file(filename.c_str(), std::ios::in);
  std::vector<std::pair<std::string, int> > items;
  for (std::map<std::string, int>::iterator it=scoreTab.begin(); it!=scoreTab.end(); ++it)
    items.push_back(std::make_pair(it->first, it->second));
  sort(items.begin(), items.end(), func_classic);
  for (unsigned int i=0; i<items.size(); i++)
  file << items[i].first << " -- " << items[i].second << std::endl;
}
