#include "pch.h"
#include "PuntDeInteresBotigaSolucio.h"

std::string PuntDeInteresBotigaSolucio::getName()
{
    return m_name;
}

unsigned int PuntDeInteresBotigaSolucio::getColor()
{
    if (m_shop == "supermarket")
        return COLOR_BOTIGA_SUPERMARKET;
    if (m_shop == "tobacco")
        return COLOR_BOTIGA_TOBACCO;
    if (m_shop == "bakery")
    {
        if (m_opening_hours.find("06:00-22:00") && m_wheelchair == "yes")
            return COLOR_BOTIGA_BAKERY_WHEELCHAIR;
        return COLOR_BOTIGA_BAKERY;
    }
    return COLOR_BOTIGA_DEFECTE;
}
