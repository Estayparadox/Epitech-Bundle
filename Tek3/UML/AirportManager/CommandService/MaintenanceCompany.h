/**
 * Project Untitled
 */


#ifndef _MAINTENANCECOMPANY_H
#define _MAINTENANCECOMPANY_H

#include "CommandService.h"


class MaintenanceCompany: public CommandService {
private: 
	std::string companyName;
};

#endif //_MAINTENANCECOMPANY_H