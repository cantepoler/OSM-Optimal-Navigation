#include "pch.h"
#include "PuntDeInteresRestaurantSolucio.h"

std::string PuntDeInteresRestaurantSolucio::getName()
{
	return m_name;
}

unsigned int PuntDeInteresRestaurantSolucio::getColor()
{
	if (m_wheelchair == "yes")
	{
		if (m_cuisine == "pizza")
			return COLOR_RESTAURANT_PIZZA;
		return COLOR_RESTAURANT_WHEELCHAIR;
	}
	if (m_cuisine == "chinese")
		return COLOR_RESTAURANT_CHINESE;
	return getColor();
}
