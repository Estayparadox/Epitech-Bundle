//
// Menu.hpp for  in /home/debern_d/2_rendu/cpp_indie_studio/sources
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Wed May 18 10:14:05 2016 Dylan Debernard
// Last update Tue May 24 13:34:59 2016 Dylan Debernard
//

#ifndef			_MENU_HPP_
# define		_MENU_HPP_

#include		<irrlicht.h>
#include		<KeyEvent.hpp>
#include		<KeyEventMenu.hpp>
#include		"Core.hpp"
#include		"Cars.hpp"
#include		<irrKlang.h>

class			Menu
{
private:

public:
  Menu();
  Menu(Core core, irr::IrrlichtDevice *device, irr::video::IVideoDriver *driver,
       irr::scene::ISceneManager *sceneManager);
  ~Menu();

  int			menu(Core core, irr::IrrlichtDevice *device,
			     irr::video::IVideoDriver *driver,
			     irr::scene::ISceneManager *sceneManager);
  int			menuSetting(Core core, irr::IrrlichtDevice *device,
				    irr::video::IVideoDriver *driver,
				    irr::scene::ISceneManager *sceneManager,
				    SAppContext context);
  int			menuScore(Core core, irr::IrrlichtDevice *device,
				  irr::video::IVideoDriver *driver,
				  irr::scene::ISceneManager *sceneManager,
				  SAppContext context);
  int			menuPlay(Core core, irr::IrrlichtDevice *device,
				 irr::video::IVideoDriver *driver,
				 irr::scene::ISceneManager *sceneManager,
				 SAppContext context);
  void		        changeControle(irr::IrrlichtDevice *device, KeyEvent keyEvent,
				       SAppContext context, KeyEventMenu receiver);
};

#endif			/* !_MENU_HPP_ */
