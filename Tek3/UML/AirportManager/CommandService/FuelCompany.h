/**
 * Project Untitled
 */


#ifndef _FUELCOMPANY_H
#define _FUELCOMPANY_H

#include "CommandService.h"


class FuelCompany: public CommandService {
private: 
	std::string companyName;
};

#endif //_FUELCOMPANY_H