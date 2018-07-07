/**
 * Project Untitled
 */


#ifndef _WAITER_H
#define _WAITER_H

#include "Employee.h"


class Waiter: public Employee {
public: 
	
	/**
	 * @param ticket
	 */
	boardingCard checkTicket(void ticket);
	
	bool checkLuguage();
	
	void loadingLuguage();
	
	void unloadingLuguage();
private: 
	airportName airportName;
	int income;
};

#endif //_WAITER_H