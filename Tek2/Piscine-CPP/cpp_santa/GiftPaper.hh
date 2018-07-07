//
// GiftPaper.hh for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sat Jan 16 15:20:05 2016 Luca GUARNIERI
// Last update Sun Jan 17 02:38:48 2016 Luca GUARNIERI
//

#ifndef GIFTPAPER_HH_
# define GIFTPAPER_HH_

# include "Box.hh"

class	GiftPaper : public Wrap 
{
public:
  GiftPaper(std::string const &title = "", std::string const &type = "");
  //  GiftPaper(GiftPaper const & );
  ~GiftPaper();
  virtual void		wrapMeThat(Object *);
};

#endif /* GIFTPAPER_HH_  */
