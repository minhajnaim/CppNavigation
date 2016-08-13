/*
 * CWaypoint.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Minhaj
 */

#ifndef CWAYPOINT_H_
#define CWAYPOINT_H_
using namespace std;


class CWaypoint
{
public:
	CWaypoint();
	CWaypoint(string name,double latitude, double longitude);
	void set(string name, double latitude, double longitude);
	void print(int format);
	string getName() const;
	double getLatitude() const;
	double getLongitude() const;
	void getAllDataByPointer(string *pname, double *platitude,double *plongitude);
	void getAllDataByReference(string &name, double &latitude, double &longitude);
	double calculateDistance(const CWaypoint &wp);
	CWaypoint add(CWaypoint const &wp_right);
	bool less(CWaypoint const &wp_right);

private:
	string m_name;
	double m_latitude;
	double m_longitude;
	void transformLongitude2degmmss(int &deg,int &mm,double &ss);
	void transformLatitude2degmmss(int &deg,int &mm,double &ss);

};

#endif /* CWAYPOINT_H_ */
