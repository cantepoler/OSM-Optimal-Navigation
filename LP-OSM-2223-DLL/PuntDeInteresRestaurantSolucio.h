#pragma once
#include "pch.h"
#include "PuntDeInteresBase.h"
class PuntDeInteresRestaurantSolucio : public PuntDeInteresBase
{
public:
	PuntDeInteresRestaurantSolucio() : PuntDeInteresBase(), m_cuisine(""), m_wheelchair("") { ; }
	PuntDeInteresRestaurantSolucio(Coordinate coord, const std::string& name, const std::string& cuisine,
		const std::string& wheelchair) : PuntDeInteresBase(coord, name), m_cuisine(cuisine), m_wheelchair(wheelchair) { ; }

	PuntDeInteresRestaurantSolucio* clone() override { return new PuntDeInteresRestaurantSolucio(*this); }

	std::string getName() override;
	unsigned int getColor() override;

private:
	std::string m_cuisine;
	std::string m_wheelchair;
};

