#pragma once
#include "PuntDeInteresBase.h"
class PuntDeInteresRestaurantSolucio : public PuntDeInteresBase
{
public:
	PuntDeInteresRestaurantSolucio() : PuntDeInteresBase(), m_cuisine(""), m_wheelchair("") { ; }
	PuntDeInteresRestaurantSolucio(Coordinate coord, const std::string& name, const std::string& cuisine,
		const std::string& wheelchair) : PuntDeInteresBase(coord, name), m_cuisine(cuisine), m_wheelchair(wheelchair) { ; }
	unsigned int getColor() override;

private:
	std::string m_cuisine;
	std::string m_wheelchair;
};

