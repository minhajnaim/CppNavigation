/*
 * CIndentCodec.cpp
 *
 *  Created on: Jan 16, 2014
 *      Author: Minhaj
 */

#include "CIndentCodec.h"

void CIndentCodec::write(ostream& myFile, const vector<CWaypoint>& waypoints,
		const vector<CPOI*>& pois) const
{


	//   myFile <<"hello"<<endl;
		for(unsigned int i=0;i<waypoints.size();i++)
		{	myFile<<"WP"<<endl;
			myFile<<"  "<<"name"<<endl;
			myFile<<"    "<<waypoints[i].getName()<<endl;
			myFile<<"  "<<"Latitude"<<endl;
			myFile<<"    "<<waypoints[i].getLatitude()<<endl;
			myFile<<"  "<<"Longitude"<<endl;
			myFile<<"    "<<waypoints[i].getLongitude()<<endl<<endl<<endl<<endl;

		}
		for(unsigned int i=0;i<pois.size();i++)
			{	myFile<<"POI"<<endl;
				myFile<<"  "<<"name"<<endl;
				myFile<<"    "<<pois[i]->getName()<<endl;
				myFile<<"  "<<"Latitude"<<endl;
				myFile<<"    "<<pois[i]->getLatitude()<<endl;
				myFile<<"  "<<"Longitude"<<endl;
				myFile<<"    "<<pois[i]->getLongitude()<<endl;
				myFile<<"  "<<"type"<<endl;
				if(pois[i]->getType()==0)
				{myFile<<"    "<<"restaurant"<<endl;}
				else if(pois[i]->getType()==1)
				{myFile<<"    "<<"club"<<endl;}
				else if(pois[i]->getType()==2)
				{myFile<<"    "<<"mall"<<endl;}
				myFile<<"  "<<"description"<<endl;
				myFile<<"    "<<pois[i]->getDescription()<<endl;



			}

}

void CIndentCodec::read(std::vector<CWaypoint>& waypoints,
		std::vector<CPOI>& pois, istream& myFile) const
{

	t_poi type{};
			int state=0;
			int keyword_indent=0;
			int indent=0,new_indent=0;
			int value_indent=0;
		string WP,POI,line,keyword,value_name="",value_name_new="",value_type="",value_type_new="",value_description="",value_description_new="",nextLine;
		double value_latitude=0,value_latitude_new=0,value_longitude=0,value_longitude_new=0;
		unsigned pos=0;

			while (!myFile.eof())

			{
				getline(myFile,nextLine);

					switch(state){

					case 0:
						hello1:


								if(nextLine=="WP"||nextLine=="POI")
								{WP=nextLine;
								POI=nextLine;
								state=1;
	//							cout<<"this is starting"<<WP<<endl;
								}
								else if(nextLine=="")
									state=0;
								else
									{
									cerr<<"WP or POI not found"<<endl;
									state=0;
									}
	//

						break;
					case 1:
						hello:

							pos=0;
							keyword_indent=0;
								while(nextLine.find_first_of(' ',pos)==pos)
							{
								keyword_indent=keyword_indent++;
								indent=keyword_indent;
								pos++;
							}

								if(indent>0 && WP=="WP")
								{
									if(nextLine.substr(keyword_indent)=="name")
									{keyword=nextLine.substr(keyword_indent);
	//								cout<<"keyWORD IS"<<keyword<<endl;
									state=2;

									//break;
									}
									else if(nextLine.substr(keyword_indent)=="Latitude")
									{keyword=nextLine.substr(keyword_indent);
	//								cout<<"keyWORD IS "<<keyword<<endl;
									state=2;

									//break;
									}
									else if(nextLine.substr(keyword_indent)=="Longitude")
									{keyword=keyword=nextLine.substr(keyword_indent);
	//								cout<<"keyWORD IS "<<keyword<<endl;
									state=2;

									//break;
									}
									else
									{cerr<<"Keyword Missing or Wrong entered for WP"<<endl;
									state =0;
									//myFile.close();
									//break;
									}
								}

								else if(indent>0 && POI=="POI")
								{
									if(nextLine.substr(keyword_indent)=="name")
									{keyword=nextLine.substr(keyword_indent);
	//							cout<<"keyWORD IS"<<keyword<<endl;
									state=2;

									//break;
									}
									else if(nextLine.substr(keyword_indent)=="Longitude")
									{keyword=nextLine.substr(keyword_indent);
	//								cout<<"keyWORD IS"<<keyword<<endl;
									state=2;

									//break;
									}
									else if(nextLine.substr(keyword_indent)=="type")
									{keyword=nextLine.substr(keyword_indent);
	//								cout<<"keyWORD IS"<<keyword<<endl;
									state=2;

									//break;
									}
									else if(nextLine.substr(keyword_indent)=="Latitude")
									{keyword=nextLine.substr(keyword_indent);
	//								cout<<"keyWORD IS"<<keyword<<endl;
									state=2;

									//break;
									}
									else if(nextLine.substr(keyword_indent)=="description")
									{keyword=nextLine.substr(keyword_indent);
	//								cout<<"keyWORD IS"<<keyword<<endl;
									state=2;

									//break;
									}
									else
										{cerr<<"keyword missing for POI"<<endl;
										state=0;}
								}
								else
								{cerr<<"keyword missin for"<<keyword<<endl;
								state=0;
								//myFile.close();
								//break;
								}


	break;






					case 2:
							//while(!nextLine.empty())
						//{
							pos=0;

							value_indent=0;
							while(nextLine.find_first_of(' ',pos)==pos)
							{
								value_indent=value_indent++;
								indent=value_indent;
								pos++;
							}

							if(value_indent>keyword_indent)
							{	if(keyword=="name")
								{value_name=nextLine.substr(value_indent);
	//							cout<<"value is "<<value_name<<endl;
								state=1;
								//break;
								}
								else if(keyword=="Latitude")
								{value_latitude=atof(nextLine.c_str());
	//							cout<<"value is "<<value_latitude<<endl;
								state=1;
								//break;
								}
								else if(keyword=="Longitude")
								{value_longitude=atof(nextLine.c_str());
	//							cout<<"value is "<<value_longitude<<endl;
								state=1;
								//break;
								}
								else if(keyword=="type")
								{value_type=nextLine.substr(value_indent);
								{	if(value_type=="restaurant")
									 type=restaurant;
									else if(value_type=="club")
										type=club;
									else if (value_type=="mall")
										type=mall;
								}
	//							cout<<"value is "<<value_type<<endl;
								state=1;
								//break;
								}
								else if(keyword=="description")
								{value_description=nextLine.substr(value_indent);
								cout<<"value is "<<value_description<<endl;
								state=1;
								getline(myFile,line);
								pos=0;
								new_indent=0;
								{while(line.find_first_of(' ',pos)==pos)
								{new_indent=new_indent++;
								indent=new_indent;
								pos++;}}
								if(new_indent>=value_indent)
								{
									if(keyword=="description")
									{value_description_new=line.substr(new_indent);
								value_description.append(value_description_new);
	//							cout<<"value is "<<value_description<<endl;
								state=1;
								}}

								else if (new_indent<value_indent && new_indent>0)
										{
									nextLine=line;
									goto hello;
										}

								else if (new_indent==0)
											{
									nextLine=line;
									goto hello1;
											}



								}

							}
							else if(value_indent<keyword_indent)
								{cerr<<"There is a value with  error"<<endl;state=0;}
							else
								cerr<<"Value missing"<<endl;

						break;

					}
					 if(value_name!="" && value_latitude!=0 && value_longitude!=0 && WP=="WP")
					{	CWaypoint obj(value_name,value_longitude,value_latitude);
						waypoints.push_back(obj);
						WP="";
						value_name="";
						value_latitude=0.0;
						value_longitude=0.0;
						state=0;	}

					 else if(value_name!="" && value_latitude!=0 && value_longitude!=0 && value_description!="" && value_type!="" && POI=="POI")
					{
//						 m_pPoiDatabase->addPoi(type,value_name,value_description,value_latitude,value_longitude);
//						addPoi(value_name);
						CPOI POI(type,value_name,value_description,value_latitude,value_longitude);
						pois.push_back(POI);
						value_name="";
						value_latitude=0.0;
						value_longitude=0.0;
						value_description="";
						value_type="";
	//					POI="";
	//				state=0;
					}
			}



}

//CIndentCodec::CIndentCodec()
//{
//	// TODO Auto-generated constructor stub
//
//}

CIndentCodec::~CIndentCodec()
{
	// TODO Auto-generated destructor stub
}

