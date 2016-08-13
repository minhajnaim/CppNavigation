/* Generated by Together */
#ifndef CPOI_H
#define CPOI_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include "CWaypoint.h"


using namespace std;
enum t_poi{restaurant,club,mall,Nill};
class CPOI:public CWaypoint
{

private:
	t_poi m_type;
	string m_description;

public:
	CPOI();
	CPOI(t_poi type,string name,string description, double latitude,
			double longitude);
	void Print();
	string getDescription() const;
	t_poi getType() const;
};
#endif //CPOI_H
