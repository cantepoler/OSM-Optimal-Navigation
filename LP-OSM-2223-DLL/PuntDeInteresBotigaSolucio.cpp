#include "pch.h"
#include "PuntDeInteresBotigaSolucio.h"

std::string PuntDeInteresBotigaSolucio::getName()
{
    return PuntDeInteresBase::getName();
}

unsigned int PuntDeInteresBotigaSolucio::getColor()
{
    if (m_shop == "supermarket")
        return COLOR_BOTIGA_SUPERMARKET;
    if (m_shop == "tobacco")
        return COLOR_BOTIGA_TOBACCO;
    if (m_shop == "bakery")
    {
        int pos = m_opening_hours.find("06:00-22:00");
        if (pos != std::string::npos && m_wheelchair == "yes")
            return COLOR_BOTIGA_BAKERY_WHEELCHAIR;
        return COLOR_BOTIGA_BAKERY;
    }
    return COLOR_BOTIGA_DEFECTE;
}
