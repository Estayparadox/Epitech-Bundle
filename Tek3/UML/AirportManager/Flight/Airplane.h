/**
 * Project Untitled
 */


#ifndef _AIRPLANE_H
#define _AIRPLANE_H

class Airplane {
public: 
	
	int consumation();
	
	bool flightAutorisation();
	
	int calcMiles();
private: 
	int airplaneNumber;
	availableState availability;
	airplaneType airplaneType;
	airportName currentAirport;
	int gasQuantity;
	int miles;
};

#endif //_AIRPLANE_H