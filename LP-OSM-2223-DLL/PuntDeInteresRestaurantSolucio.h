#pragma once
#include "PuntDeInteresBase.h"
class PuntDeInteresRestaurantSolucio : public PuntDeInteresBase
{
public:
	unsigned int getColor() override;

private:
	std::string m_cuisine;
	std::string m_wheelchair;
};

