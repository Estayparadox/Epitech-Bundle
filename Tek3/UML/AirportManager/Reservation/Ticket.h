/**
 * Project Untitled
 */


#ifndef _TICKET_H
#define _TICKET_H

class Ticket {
public: 
	int ticketID;
	
	void giveBoardingCard();
private: 
	paymentPlace where;
	paymentWay how;
	int ticketPrice;
	bool validity;
	date flightDate;
};

#endif //_TICKET_H