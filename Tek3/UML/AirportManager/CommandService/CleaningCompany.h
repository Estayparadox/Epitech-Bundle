/**
 * Project Untitled
 */


#ifndef _CLEANINGCOMPANY_H
#define _CLEANINGCOMPANY_H

#include "CommandService.h"


class CleaningCompany: public CommandService {
public: 
	
	void sellCleaning();
private: 
	std::string companyName;
};

#endif //_CLEANINGCOMPANY_H