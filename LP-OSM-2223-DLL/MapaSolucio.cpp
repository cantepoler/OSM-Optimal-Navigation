#include "pch.h"
#include "MapaSolucio.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "CamiSolucio.h"

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& pdis)
{
	m_puntsInteres.push_back(new PuntDeInteresBotigaSolucio({ 41.4918606, 2.1465411 }, "La Millor Pastisseria"));
	m_puntsInteres.push_back(new PuntDeInteresRestaurantSolucio({ 41.4902204, 2.1406477 }, "El Millor Restaurant", "regional", "yes"));
	pdis = m_puntsInteres;
}

void MapaSolucio::getCamins(std::vector<CamiBase*>& camins)
{
	CamiSolucio* cami = new CamiSolucio();
	
	m_camins.push_back(cami);
	camins = m_camins;
}
