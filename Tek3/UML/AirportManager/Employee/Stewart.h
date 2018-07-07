/**
 * Project Untitled
 */


#ifndef _STEWART_H
#define _STEWART_H

#include "Employee.h"


class Stewart: public Employee {
public: 
	
	/**
	 * @param boardingCard
	 */
	bool checkBoardingCard(void boardingCard);
	
	void sellFood();
private: 
	int airplaneId;
	int income;
};

#endif //_STEWART_H