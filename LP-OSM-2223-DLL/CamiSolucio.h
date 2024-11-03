#pragma once
#include "pch.h"
#include "CamiBase.h"
class CamiSolucio : public CamiBase
{
public:
	std::vector<Coordinate> getCamiCoords() override;
	void afegirNode(Coordinate coord);
	CamiSolucio* clone() override { return new CamiSolucio(*this); }

private:
	std::vector<Coordinate> m_coordenades;
};

