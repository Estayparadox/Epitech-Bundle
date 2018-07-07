/**
 * Project Untitled
 */


#ifndef _BOARDINGCARD_H
#define _BOARDINGCARD_H

class BoardingCard {
public: 
	
	void giveAccess();
private: 
	date flightDate;
	int row;
	std::string seat;
	bool validity;
};

#endif //_BOARDINGCARD_H