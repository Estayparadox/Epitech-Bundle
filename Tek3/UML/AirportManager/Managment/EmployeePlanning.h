/**
 * Project Untitled
 */


#ifndef _EMPLOYEEPLANNING_H
#define _EMPLOYEEPLANNING_H

#include "GeneralPlanning.h"


class EmployeePlanning: public GeneralPlanning {
public: 
	
	/**
	 * @param IEmployee
	 */
	void makePlanning(void IEmployee);
};

#endif //_EMPLOYEEPLANNING_H