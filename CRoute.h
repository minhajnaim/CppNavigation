/* Generated by Together */


#ifndef CROUTE_H_
#define CROUTE_H_
#include <iostream>
#include <stdlib.h>
#include <string>
#include "CWaypoint.h"
#include "CPOIDataBase.h"
#include <vector>
#include <fstream>
#include "CPOI.h"
#include "CIndentCodec.h"
using namespace std;

class CRoute
{
private:
	vector<CWaypoint> m_pWaypoint;
	vector<CWaypoint>m_new;
//	unsigned int m_maxWp;
//	unsigned int m_nextWp;
	vector<CPOI*> m_pPoi;
//	unsigned int m_maxPoi;
//	unsigned int m_nextPoi;
	CPOIDataBase *m_pPoiDatabase  ;
public:

		CRoute();
		CRoute(CRoute const & Origin );
		void ConnecttoPoiDatabase(CPOIDataBase* pPoiDB);
		void addwaypoint(const CWaypoint & wp);
		void addPoi(string namePoi);
		double getDistanceNextPoi(const CWaypoint & wp, CPOI & poi);
		void print();
		void writeToFile(string filename,const CCodec& coder);
		void readFromFile(string filename,bool deleteOldData,const CCodec& coder);
		~CRoute();


};

#endif /* CROUTE_H_ */