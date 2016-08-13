/*
 * CIndentCodec.h
 *
 *  Created on: Jan 16, 2014
 *      Author: Minhaj
 */

#ifndef CINDENTCODEC_H_
#define CINDENTCODEC_H_

#include "CCodec.h"
#include "CWaypoint.h"
#include "CPOI.h"
#include "CPOIDataBase.h"
class CIndentCodec: public CCodec
{
public:
//	CIndentCodec();
	 void write(ostream& myFile, const vector<CWaypoint>& waypoints,
		const vector<CPOI*>& pois) const;
	 void read(std::vector<CWaypoint>& waypoints, std::vector<CPOI>& pois,
		istream& myFile) const;
	virtual ~CIndentCodec();
};

#endif /* CINDENTCODEC_H_ */
