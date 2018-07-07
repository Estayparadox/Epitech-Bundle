/**
 * Project Untitled
 */


#ifndef _CURRENTMAINTENANCE_H
#define _CURRENTMAINTENANCE_H

#include "MaintenanceCompany.h"


class CurrentMaintenance: public MaintenanceCompany {
private: 
	date orderingDate;
	maintenanceLenght standingBy;
	int maintenancePrice;
	std::string rapport;
};

#endif //_CURRENTMAINTENANCE_H