//
// KeyEventMenu.hpp for  in /home/debern_d/2_rendu/cpp_indie_studio/include
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Tue May 17 13:43:24 2016 Dylan Debernard
// Last update Mon May 30 16:30:29 2016 Dylan Debernard
//

#ifndef                 _KEYEVENTMENU_HPP_
# define                _KEYEVENTMENU_HPP_

#include <irrlicht.h>
#include "../sources/Core.hpp"

typedef struct		SAppContext
{
  irr::IrrlichtDevice	*device;
  irr::s32		button;
  irr::s32	        bind1;
  irr::s32		bind2;
}			SAppContext;

enum
  {
    GUI_ID_PLAY_BUTTON = 101,
    GUI_ID_SCORE_BUTTON,
    GUI_ID_SETTING_BUTTON,
    GUI_ID_QUIT_BUTTON,

    GUI_UP_CONTROLE_1,
    GUI_DOWN_CONTROLE_1,
    GUI_RIGHT_CONTROLE_1,
    GUI_LEFT_CONTROLE_1,
    GUI_TURBO_CONTROLE_1,
    GUI_ROCKETKEY_CONTROLE_1,

    GUI_UP_CONTROLE_2,
    GUI_DOWN_CONTROLE_2,
    GUI_RIGHT_CONTROLE_2,
    GUI_LEFT_CONTROLE_2,
    GUI_TURBO_CONTROLE_2,
    GUI_ROCKETKEY_CONTROLE_2,

    GUI_BACK_MENU
  };

Core	readSettingFile(Core core, std::string filename);
int	HyperSprint(Core core, irr::IrrlichtDevice *device,
		    irr::video::IVideoDriver *driver,
		    irr::scene::ISceneManager *sceneManager);

class KeyEventMenu : public irr::IEventReceiver
{
public:
  KeyEventMenu(SAppContext &context) : Context(context) { }

  virtual bool OnEvent(const irr::SEvent& event)
  {
    if (event.EventType == irr::EET_GUI_EVENT)
      {
	irr::s32 id = event.GUIEvent.Caller->getID();
	switch (event.GUIEvent.EventType)
	  {
	  case irr::gui::EGET_BUTTON_CLICKED:
	    switch (id)
	      {
	      case GUI_ID_PLAY_BUTTON:
		Context.button = 1;
		return (true);
	      case GUI_ID_SCORE_BUTTON:
		Context.button = 2;
		return (true);
	      case GUI_ID_SETTING_BUTTON:
		Context.button = 3;
		return (true);
	      case GUI_ID_QUIT_BUTTON:
		//Context.device->closeDevice();
		Context.button = 4;
		return (true);
	      case GUI_UP_CONTROLE_1:
		Context.bind1 = 1;
		return (true);
	      case GUI_DOWN_CONTROLE_1:
		Context.bind1 = 2;
                return (true);
	      case GUI_RIGHT_CONTROLE_1:
		Context.bind1 = 3;
                return (true);
	      case GUI_LEFT_CONTROLE_1:
		Context.bind1 = 4;
                return (true);
	      case GUI_TURBO_CONTROLE_1:
		Context.bind1 = 5;
                return (true);
	      case GUI_ROCKETKEY_CONTROLE_1:
		Context.bind1 = 6;
                return (true);
	      case GUI_UP_CONTROLE_2:
                Context.bind2 = 1;
                return (true);
              case GUI_DOWN_CONTROLE_2:
                Context.bind2 = 2;
                return (true);
              case GUI_RIGHT_CONTROLE_2:
		Context.bind2 = 3;
                return (true);
              case GUI_LEFT_CONTROLE_2:
		Context.bind2 = 4;
		return (true);
              case GUI_TURBO_CONTROLE_2:
		Context.bind2 = 5;
		return (true);
              case GUI_ROCKETKEY_CONTROLE_2:
		Context.bind2 = 6;
		return (true);
	      case GUI_BACK_MENU:
		Context.button = 4;
		return (true);
	      }
	    break;
	  case irr::gui::EGET_FILE_SELECTED:
	  default:
	    break;
	  }
      }
    return false;
  }

private:
  SAppContext & Context;
};

#endif			/* !_KEYEVENTMENU_HPP_ */
