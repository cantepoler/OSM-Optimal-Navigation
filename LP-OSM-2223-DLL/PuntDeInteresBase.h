#pragma once

#include <string>
#include "Common.h"

class PuntDeInteresBase {
public:
	PuntDeInteresBase();
	PuntDeInteresBase(Coordinate coord, std::string name);
	virtual ~PuntDeInteresBase() { ; }

	virtual PuntDeInteresBase* clone() { return new PuntDeInteresBase(*this); }
	virtual std::string getName();
	Coordinate getCoord();
	virtual unsigned int getColor();

protected:
	Coordinate m_coord;
	std::string m_name;
};