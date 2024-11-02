#pragma once
#include "pch.h"
#include "PuntDeInteresBase.h"

class PuntDeInteresBotigaSolucio : public PuntDeInteresBase
{
public:
	PuntDeInteresBotigaSolucio() : PuntDeInteresBase(), m_shop(""), m_opening_hours(""), m_wheelchair("") { ; }
	PuntDeInteresBotigaSolucio(Coordinate coord, const std::string& name) : PuntDeInteresBase(coord, name) { ; }
	PuntDeInteresBotigaSolucio(Coordinate coord, const std::string& name, const std::string& shop,
		const std::string& opening_hours, const std::string& wheelchair) : PuntDeInteresBase(coord, name),
		m_shop(shop), m_opening_hours(opening_hours), m_wheelchair(wheelchair) { ; }

	std::string getName() override;
	unsigned int getColor() override;

private:
	std::string m_shop;
	std::string m_opening_hours;
	std::string m_wheelchair;
};