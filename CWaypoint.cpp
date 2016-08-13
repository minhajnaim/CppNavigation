#include <iostream>
#include <stdlib.h>
#include "CWaypoint.h"
#include <math.h>
#include <string>
#define PI 3.14159265
using namespace std;
//#define SHOWADDRESS

CWaypoint::CWaypoint()
{}
CWaypoint::CWaypoint(string name, double latitude, double longitude)
{
	set(name, latitude, longitude);
#ifdef SHOWADDRESS
	cout<<"Object Created at : "<<this<<endl;
	cout<<"The Value of Attribute 'm_name' is "<<this->m_name<<" and the address is "<<&this->m_name<<" & the data occupies is "<<sizeof(this->m_name)<<" Bytes"<<endl;
	cout<<"The Value of Attribute 'm_latitude' is "<<this->m_latitude<<" and the address is "<<&this->m_latitude<<" & the data occupies is "<<sizeof(this->m_latitude)<<" Bytes"<<endl;
	cout<<"The Value of Attribute 'm_longitude' is "<<this->m_longitude<<" and the address is "<<&this->m_longitude<<" & the data occupies is "<<sizeof(this->m_longitude)<<" Bytes"<<endl;
#endif
}

void CWaypoint::set(string name, double latitude, double longitude)
{
		m_name=name;
	if((latitude>=-90 && latitude<=90) && (longitude>=-180 && longitude <=180))
	{

		m_latitude=latitude;
		m_longitude=longitude;
	}
	else
	{
		m_latitude=0;
		m_longitude=0;

	}
}

void CWaypoint::print(int format)
{
		int deg,mm;
		double ss;
	if(format==1)
	{
		cout<<m_name<<" on Latitude in decimal = "<<m_latitude;
		cout<<" & "<<m_name<<" on Longitude in decimal= "<<m_longitude<<endl;
	}
	else if(format==2)
	{
		transformLatitude2degmmss(deg,mm,ss);
		cout<<m_name<<" on Latitude = "<<deg<<"deg "<<mm<<"min "<<ss<<"s and ";
		transformLongitude2degmmss(deg,mm,ss);
		cout<<m_name<<" on Longitude = "<<deg<<"deg "<<mm<<"min "<<ss<<"s"<<endl;

	}



}

string CWaypoint::getName() const
{

	return m_name;
}

double CWaypoint::getLatitude() const
{
	return m_latitude;
}

double CWaypoint::getLongitude() const
{
	return m_longitude;
}

void CWaypoint::getAllDataByPointer(string* pname, double* platitude,
		double* plongitude)
{
	*pname=m_name;
	*platitude=m_latitude;
	*plongitude=m_longitude;
	cout<<"Value & Address of attributes are  "<<pname<<"   "<<&m_name<<endl;
	cout<<"Value & Address of attributes are  "<<platitude<<"      "<<&m_latitude<<endl;
	cout<<"Value & Address of attributes are  "<<plongitude<<"      "<<&m_longitude<<endl;
}

void CWaypoint::getAllDataByReference(string& name, double& latitude,
		double& longitude)
{
	name=m_name;
	latitude=m_latitude;
	longitude=m_longitude;
	cout<<"Value & Address of attributes are  "<<m_name<<"   "<<&m_name<<endl;
	cout<<"Value & Address of attributes are  "<<m_latitude<<"      "<<&m_latitude<<endl;
	cout<<"Value & Address of attributes are  "<<m_longitude<<"      "<<&m_longitude<<endl;

}

double CWaypoint::calculateDistance(const CWaypoint& wp)
{
	double latitude_1,latitude_2,longitude_1,longitude_2,distance;
	latitude_1=wp.getLatitude();
	latitude_2=this->getLatitude();
	longitude_1=wp.getLongitude();
	longitude_2=this->getLongitude();
	distance=6378*acos((sin(latitude_1*(PI/180))*sin(latitude_2*(PI/180)))+(cos(latitude_1*(PI/180))*cos(latitude_2*(PI/180))*cos(longitude_2*(PI/180)-longitude_1*(PI/180))));

	return distance;
}

CWaypoint CWaypoint::add(const CWaypoint& wp_right)
{
	string name_1,name_2,newName;
	double lat_1,lat_2,lon_1,lon_2,sumLat,sumLong;
	name_1=this->getName();
	lat_1=this->getLatitude();
	lon_1=this->getLongitude();
	name_2=wp_right.getName();
	lat_2=wp_right.getLatitude();
	lon_2=wp_right.getLongitude();
	sumLat=lat_1+lat_2;
	sumLong=lon_1+lon_2;
	newName=name_1 +" + " +name_2;
	CWaypoint result;
	/*while((sumLat>90)||(sumLat<-90)||(sumLong>180)||(sumLong<-180))
	{
		if(sumLat>90)
		{
			sumLat=sumLat-90;
			sumLat=-90+sumLat;
		}

		if(sumLat<-90)
		{
			sumLat=sumLat+90;
			sumLat=90+sumLat;
		}
		if(sumLong>180)
		{
			sumLong=sumLong-180;
			sumLong=-180+sumLong;
		}
		if(sumLong<-180)
		{
			sumLong=sumLong+180;
			sumLong=180+sumLong;
		}
	}*/
	result.m_name=newName;
	result.m_latitude=sumLat;
	result.m_longitude=sumLong;
	return result;

}
bool CWaypoint::less(const CWaypoint& wp_right)
{
	double latitude_1,longitude_1,latitude_2,longitude_2,distanceOfFirst,distanceOfSecond;
	latitude_1=this->getLatitude();
	longitude_1=this->getLongitude();
	latitude_2=wp_right.getLatitude();
	longitude_2=wp_right.getLongitude();
	distanceOfFirst=6378*acos((sin(latitude_1*(PI/180))*sin(0*(PI/180)))+(cos(latitude_1*(PI/180))*cos(0*(PI/180))*cos(0*(PI/180)-longitude_1*(PI/180))));
	distanceOfSecond=6378*acos((sin(latitude_2*(PI/180))*sin(0*(PI/180)))+(cos(latitude_2*(PI/180))*cos(0*(PI/180))*cos(0*(PI/180)-longitude_2*(PI/180))));

if(distanceOfFirst>distanceOfSecond)
	{
		cout<<wp_right.m_name<<"<"<<this->m_name;
		return 0;
	}
else
	{
		cout<<wp_right.m_name<<">"<<this->m_name;
		return 1;
	}

}

void CWaypoint::transformLatitude2degmmss(int & deg,int & mm, double & ss)
{
	double tempFractionalValueofDeg,tempMinValue ;


	deg=m_latitude;
	tempFractionalValueofDeg=m_latitude-deg;
	tempMinValue=tempFractionalValueofDeg*60;
	mm=tempMinValue;
	ss=(tempMinValue-mm)*60;
}

void CWaypoint::transformLongitude2degmmss(int& deg, int& mm, double& ss)
{
	double tempFractionalValueofDeg,tempMinValue ;

	deg=m_longitude;
	tempFractionalValueofDeg=m_longitude-deg;
	tempMinValue=tempFractionalValueofDeg*60;
	mm=tempMinValue;
	ss=(tempMinValue-mm)*60;
}





