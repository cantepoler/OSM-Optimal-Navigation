#include "pch.h"
#include "CamiSolucio.h"

std::vector<Coordinate> CamiSolucio::getCamiCoords()
{
    return m_coordenades;
}

void CamiSolucio::afegirNode(Coordinate coord)
{
    m_coordenades.push_back(coord);
}
