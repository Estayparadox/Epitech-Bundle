/**
 * Project Untitled
 */


#ifndef _CUSTOMER_H
#define _CUSTOMER_H

class Customer {
public: 
	
	void buyFood();
	
	void register();
	
	void giveLuguage();
private: 
	std::string name;
	bool hasLuguage;
	int milesDone;
};

#endif //_CUSTOMER_H