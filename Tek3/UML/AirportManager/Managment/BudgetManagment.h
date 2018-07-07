/**
 * Project Untitled
 */


#ifndef _BUDGETMANAGMENT_H
#define _BUDGETMANAGMENT_H

class BudgetManagment {
public: 
	
	/**
	 * @param Airport
	 */
	int findTicketPriceAverage(void Airport);
	
	/**
	 * @param CommandService
	 */
	int findRessources(void CommandService);
private: 
	int resourses;
	int charges;
	int totalFlight;
	int totalPassengers;
	int ticketPrice;
	int ticketPriceAverage;
	int overBooking;
};

#endif //_BUDGETMANAGMENT_H