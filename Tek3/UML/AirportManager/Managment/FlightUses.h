/**
 * Project Untitled
 */


#ifndef _FLIGHTUSES_H
#define _FLIGHTUSES_H

class FlightUses {
public: 
	
	/**
	 * @param airplaneType
	 * @param airportName
	 * @param airportName
	 */
	Flight organizeFlight(void airplaneType, void airportName, void airportName);
	
	/**
	 * @param Flight
	 * @param time
	 * @param flightType
	 */
	Flight setFlightOptions(void Flight, void time, void flightType);
	
	/**
	 * @param Flight
	 */
	void deleteFlight(void Flight);
};

#endif //_FLIGHTUSES_H