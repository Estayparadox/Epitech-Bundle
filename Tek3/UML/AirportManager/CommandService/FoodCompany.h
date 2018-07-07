/**
 * Project Untitled
 */


#ifndef _FOODCOMPANY_H
#define _FOODCOMPANY_H

#include "CommandService.h"


class FoodCompany: public CommandService {
public: 
	
	void sellFood();
private: 
	std::string companyName;
};

#endif //_FOODCOMPANY_H