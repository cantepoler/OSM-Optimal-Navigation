#pragma once
#include "PuntDeInteresBase.h"
class PuntDeInteresBotigaSolucio : public PuntDeInteresBase
{
public:
	unsigned int getColor() override;

private:
	std::string m_shop;
	std::string m_opening_hours;
	std::string m_wheelchair;
};