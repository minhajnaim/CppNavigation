/*
 * CCSVCodec.cpp
 *
 *  Created on: Jan 16, 2014
 *      Author: Minhaj
 */

#include "CCSVCodec.h"

//CCSVCodec::CCSVCodec()
//{
//	// TODO Auto-generated constructor stub
//
//}

void CCSVCodec::write(ostream& myFile, const vector<CWaypoint>& waypoints,
		const vector<CPOI*>& pois) const
{
	for(int i=0;i<waypoints.size();i++)
	myFile<<"WP"<<";"<<waypoints[i].getName()<<";"<<waypoints[i].getLatitude()<<";"<<waypoints[i].getLongitude()<<endl;
	for(int j=0;j<pois.size();j++)

		{myFile<<"POI"<<";"<<pois[j]->getName()<<";"<<pois[j]->getDescription()<<";"<<pois[j]->getType()<<";";
	if(pois[j]->getType()==0)
					{myFile<<"restaurant";}
					else if(pois[j]->getType()==1)
					{myFile<<"club";}
					else if(pois[j]->getType()==2)
					{myFile<<"mall";}
	myFile<<";"<<pois[j]->getLatitude()<<";"<<pois[j]->getLongitude()<<endl;
}}

void CCSVCodec::read(std::vector<CWaypoint>& waypoints, std::vector<CPOI>& pois,
		istream& myFile) const
{

	t_poi type{Nill};
				int state=0,wpPoi_pos=0,name_pos=0,lat_pos=0,lon_pos=0,des_pos=0,type_pos=0,typst_pos=0,type_value=0;
				int keyword_indent=0;
				int indent=0,new_indent=0;
				int value_indent=0;
			string temp_WP_POI,WP,POI,line,keyword,value_name="",value_name_new="",value_type="",value_type_new="",value_description="",value_description_new="",nextLine;
			double value_latitude=0,value_latitude_new=0,value_longitude=0,value_longitude_new=0;
			unsigned pos=0;
//			waypoints.clear();
//			pois.clear();
				while (!myFile.eof())

				{
					getline(myFile,nextLine);




									wpPoi_pos=nextLine.find_first_of(";",0);
									temp_WP_POI=nextLine.substr(0,(wpPoi_pos));
									if(temp_WP_POI=="WP")
									{WP=nextLine.substr(0,(wpPoi_pos));
									cout<<WP<<endl;
									name_pos=nextLine.find_first_of(";",wpPoi_pos+1);
//									cout<<"name position"<<name_pos<<endl;
									value_name=nextLine.substr(wpPoi_pos+1,name_pos-wpPoi_pos-1);
									cout<<value_name<<endl;
									lat_pos=nextLine.find_first_of(";",name_pos+1);
//									cout<<"lat pos"<<lat_pos<<endl;
									value_latitude=atof(nextLine.substr(name_pos+1,lat_pos-name_pos-1).c_str());
									cout<<value_latitude<<endl;
									lon_pos=nextLine.find_first_of(";",lat_pos+1);
//									cout<<"position"<<lon_pos<<endl;
									value_longitude=atof(nextLine.substr(lat_pos+1,nextLine.length()).c_str());
									cout<<value_longitude<<endl;
									if(value_name!="" && value_latitude!=0 && value_longitude!=0)
									{CWaypoint hello(value_name,value_latitude,value_longitude);
									waypoints.push_back(hello);}
									else
									cerr<<"One of the Elements is Missing"<<endl;

									}
									else if(temp_WP_POI=="POI")
									{WP=nextLine.substr(0,(wpPoi_pos));
									cout<<WP<<endl;
									name_pos=nextLine.find_first_of(";",wpPoi_pos+1);
//									cout<<"name position"<<name_pos<<endl;
									value_name=nextLine.substr(wpPoi_pos+1,name_pos-wpPoi_pos-1);
									cout<<value_name<<endl;
									des_pos=nextLine.find_first_of(";",name_pos+1);
									value_description=nextLine.substr(name_pos+1,des_pos-name_pos-1);
									cout<<value_description<<endl;
									type_pos=nextLine.find_first_of(";",des_pos+1);
									type_value=atoi(nextLine.substr(des_pos+1,type_pos-des_pos-1).c_str());
									if(type_value==0)
										type=restaurant;
									else if(type_value==1)
									type=club;
									else if(type_value==2)
										type=mall;
									cout<<value_type;
									typst_pos=nextLine.find_first_of(";",type_pos+1);
									value_type_new=nextLine.substr(type_pos+1,typst_pos-type_pos-1);
									cout<<value_type_new<<endl;
									lat_pos=nextLine.find_first_of(";",typst_pos+1);
//									cout<<"lat pos"<<lat_pos<<endl;
									value_latitude=atof(nextLine.substr(typst_pos+1,lat_pos-typst_pos-1).c_str());
									cout<<value_latitude<<endl;
									lon_pos=nextLine.find_first_of(";",lat_pos+1);
//									cout<<"position"<<lon_pos<<endl;
									value_longitude=atof(nextLine.substr(lat_pos+1,nextLine.length()).c_str());
									cout<<value_longitude<<endl;
									if(value_name!="" && value_latitude!=0 && value_longitude!=0 && value_description!="" && type!=Nill)
										{CPOI hello1(type,value_name,value_description,value_latitude,value_longitude);
																			pois.push_back(hello1);}
									else
										cerr<<"One of the Elements is Missing"<<endl;
									}
//

						}

}

CCSVCodec::~CCSVCodec()
{
	// TODO Auto-generated destructor stub
}

