/**
 * Project Untitled
 */


#ifndef _MAINTENANCEBREAKTIME_H
#define _MAINTENANCEBREAKTIME_H

class MaintenanceBreakTime {
public: 
	
	/**
	 * @param Flight
	 */
	bool diagnostic(void Flight);
private: 
	Airplane airplane;
	maintenanceLenght maintenanceDuration;
	date maintenanceDate;
	int maintenancePrice;
	std::string maintenanceReport;
};

#endif //_MAINTENANCEBREAKTIME_H