/**
 * Project Untitled
 */


#ifndef _EMPLOYEEUSES_H
#define _EMPLOYEEUSES_H

class EmployeeUses {
public: 
	
	/**
	 * @param IEmployee
	 */
	void hireAnEmployee(void IEmployee);
	
	/**
	 * @param IEmployee
	 */
	void fireAnEmployee(void IEmployee);
	
	/**
	 * @param IEmployee
	 * @param jobType
	 */
	void addJob(void IEmployee, void jobType);
};

#endif //_EMPLOYEEUSES_H