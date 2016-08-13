/*
 * CCSVCodec.h
 *
 *  Created on: Jan 16, 2014
 *      Author: Minhaj
 */

#ifndef CCSVCODEC_H_
#define CCSVCODEC_H_

#include "CCodec.h"
//#include "CWaypoint.h"
//#include "CPOI.h"

class CCSVCodec: public CCodec
{
public:
//	CCSVCodec();

	void write(ostream& myFile, const vector<CWaypoint>& waypoints,
			const vector<CPOI*>& pois) const;
		 void read(std::vector<CWaypoint>& waypoints, std::vector<CPOI>& pois,
			istream& myFile) const;
	virtual ~CCSVCodec();
};

#endif /* CCSVCODEC_H_ */
