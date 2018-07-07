/**
 * Project Untitled
 */


#ifndef _COUNTER_H
#define _COUNTER_H

#include "IReservation.h"


class Counter: public IReservation {
private: 
	int overBooked;
	paymentPlace where;
	paymentWay how;
	int finalPrice;
	bool isFree;
};

#endif //_COUNTER_H