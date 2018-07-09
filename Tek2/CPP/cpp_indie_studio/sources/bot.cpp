//
// bot.cpp for  in /home/debern_d/2_rendu/cpp_indie_studio/sources
// 
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
// 
// Started on  Wed Jun  1 16:43:44 2016 Dylan Debernard
// Last update Mon Jun  6 12:19:12 2016 Dylan Debernard
//

#include		<hyper_sprint.h>
#include		<limits>

std::string             getBot(Core core)
{
  std::string bot;

  if (core.getLevelBot() == 1)
    bot = "config/bot1_";
  else
    bot = "config/bot2_";
  if (core.getMapPath() == "media/mapSW/MapSnowV4.obj")
    bot += "map2_";
  else
    bot += "map1_";
  if (core.getLaps() == 1)
    bot += "1.txt";
  else if (core.getLaps() == 3)
    bot += "3.txt";
  else
    bot += "5.txt";
  return (bot);
}

std::ifstream           &GotoLine(std::ifstream &file, int num)
{
  std::string   line;
  file.seekg(std::ios::beg);
  for(int i = 0; i < num; i++)
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return (file);
}

int                     initBot(std::string filename)
{
  std::ifstream         file2(filename.c_str(), std::ios::in);
  std::string           nb;
  int                   nbLine(0);

  while (getline(file2, nb, '\n'))
    nbLine++;
  file2.close();
  return (nbLine);
}

void                    botCommand(std::string filename, int a, std::vector<Cars> bot, int j)
{
  std::ifstream         file(filename.c_str(), std::ios::in);
  float tab[6];
  std::string line;
  int   b;
  int   i(0);

  b = a + 6;
  while (a < b)
    {
      GotoLine(file, a);
      file >> line;
      tab[i] = atof(line.c_str());
      a++;
      i++;
    }
  bot[j]._node->setPosition(irr::core::vector3df(tab[0], tab[1], tab[2]));
  bot[j]._node->setRotation(irr::core::vector3df(tab[3], tab[4], tab[5]));
}

std::string		getScoreFilename(Core core)
{
  std::string		filename;

  if (core.getLaps() == 1)
    filename += "config/scoreUnTourMap";
  else if (core.getLaps() == 3)
    filename +="config/scoreTroisToursMap";
  else if (core.getLaps() == 5)
    filename +="config/scoreCinqToursMap";

  if (core.getMapPath() == "media/map7/mapOvalGood6.obj")
    filename += "1";
  else
    filename += "2";

  return (filename);
}

std::string             getScoreSortFilename(Core core)
{
  std::string           filename;

  if (core.getLaps() == 1)
    filename += "config/unTourMap";
  else if (core.getLaps() == 3)
    filename +="config/troisToursMap";
  else if (core.getLaps() == 5)
    filename +="config/cinqToursMap";

  if (core.getMapPath() == "media/map7/mapOvalGood6.obj")
    filename += "1";
  else
    filename += "2";

  return (filename);
}
