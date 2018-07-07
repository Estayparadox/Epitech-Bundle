/**
 * Project Untitled
 */


#ifndef _FLIGHT_H
#define _FLIGHT_H

class Flight {
public: 
	
	void fly();
private: 
	Airplane airplane;
	date date;
	time time;
	airportName flightTo;
	airportName flightFrom;
	ArrayList<Employee> airplaneCrew;
	int price;
};

#endif //_FLIGHT_H