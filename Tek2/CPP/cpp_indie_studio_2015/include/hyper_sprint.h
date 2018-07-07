/*
** hyper_sprint.h for  in /home/debern_d/2_rendu/cpp_indie_studio/sources
**
** Made by Dylan Debernard
** Login   <debern_d@epitech.net>
**
** Started on  Thu May 19 21:28:30 2016 Dylan Debernard
** Last update Mon Jun  6 12:19:29 2016 Dylan Debernard
*/

#ifndef			_HYPER_SPRINT_H_
# define		_HYPER_SPRINT_H_

#include                <irrlicht.h>
#include                <iostream>
#include                <fstream>
#include                <string>
#include                <unistd.h>
#include                <KeyEvent.hpp>
#include                <KeyEventMenu.hpp>
#include                "../sources/Core.hpp"
#include                "../sources/Cars.hpp"
#include                "../sources/Camera.hpp"
#include                "../sources/PowerUp.hpp"
#include                "../sources/Menu.hpp"

//screen.cpp
void			splashScreen(irr::IrrlichtDevice *device,
                                     irr::video::IVideoDriver *driver,
                                     irr::scene::ISceneManager *sceneManager);
void			loadingScreen(irr::IrrlichtDevice *device,
                                      irr::video::IVideoDriver *driver,
                                      irr::gui::IGUIEnvironment* env);
//map.cpp
irr::scene::ISceneNode	*initSkyBox(irr::video::IVideoDriver *driver,
				    irr::scene::ISceneManager *sceneManager,
				    irr::scene::ISceneNode *skybox);
irr::scene::ISceneNode	*initMap(irr::scene::ISceneManager *sceneManager, Core core,
				 std::vector<Cars> player, std::vector<Cars> bot);
irr::scene::ISceneNode	*initMapDecors(irr::scene::ISceneManager *sceneManager);
irr::scene::ISceneNode	*nodePlane(irr::scene::ISceneManager *sceneManager,
				   std::string mapPath, irr::scene::ISceneNode *avion);
irr::scene::ISceneNode	*startFlag(Core core, irr::video::IVideoDriver *driver,
                                   irr::scene::ISceneNode *start);
irr::scene::ISceneNode	*cpFlag(Core core, irr::video::IVideoDriver *driver,
				irr::scene::ISceneNode *cp);
//print.cpp
void			printWinner(Core core, irr::IrrlichtDevice *device,
                                    irr::video::IVideoDriver *driver, int end);
void                    printInfo(Core core, irr::video::IVideoDriver *driver,
                                  irr::gui::IGUIFont* font, int i,
                                  std::vector<Cars> player);
void                    printFPS(Core core, irr::video::IVideoDriver *driver,
                                 irr::gui::IGUIFont* font);
std::string		getBot(Core core);
std::ifstream		&GotoLine(std::ifstream &file, int num);
int			initBot(std::string filename);
void			botCommand(std::string filename, int a, std::vector<Cars> bot,int j);
std::string	        getScoreFilename(Core core);
std::string		getScoreSortFilename(Core core);
#endif			/* !_HYPER_SPRINT_H_ */
