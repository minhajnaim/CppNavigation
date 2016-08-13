/*
 * CCodec.h
 *
 *  Created on: Jan 15, 2014
 *      Author: Minhaj
 */

#ifndef CCODEC_H_
#define CCODEC_H_
using namespace std;
#include <iostream>
#include <vector>
#include "CWaypoint.h"
#include "CPOI.h"
#include "CPOIDataBase.h"
class CCodec
{
public:
	CCodec();
	virtual void write(ostream& stream, const vector<CWaypoint>& waypoints,
	const vector<CPOI*>& pois) const= 0;
	virtual void read(std::vector<CWaypoint>& waypoints, std::vector<CPOI>& pois,
	istream& stream) const= 0;
	virtual ~CCodec(){};
};

#endif /* CCODEC_H_ */
