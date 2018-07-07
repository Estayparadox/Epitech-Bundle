//
// KeyEvent.hpp for  in /home/debern_d/2_rendu/cpp_indie_studio
// 
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
// 
// Started on  Mon May  2 18:29:46 2016 Dylan Debernard
// Last update Wed May 18 14:20:23 2016 Dylan Debernard
//

#ifndef			_KEYEVENT_HPP_
# define		_KEYEVENT_HPP_

#include		<irrlicht.h>
#include		<iostream>

class KeyEvent : public irr::IEventReceiver
{
public:
  virtual bool OnEvent(const irr::SEvent& event)
  {
    /*if (event.EventType == irr::EET_KEY_INPUT_EVENT)
      KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
      return (false);*/
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
      {
	KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
	Key = event.KeyInput.Key;
      }
    return (false);
  }
  virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const
  {
    return (KeyIsDown[keyCode]);
  }

  KeyEvent()
  {
    for (irr::u32 i=0; i<irr::KEY_KEY_CODES_COUNT; ++i)
      KeyIsDown[i] = false;
  }
  
private:
  bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
  
public:
  irr::EKEY_CODE Key;
};

bool		collision(irr::scene::ISceneNode* one, const irr::scene::ISceneNode* two);

#endif			/* !_KEYEVENT_HPP_ */
