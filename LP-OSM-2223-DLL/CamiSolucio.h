#pragma once
#include "CamiBase.h"
class CamiSolucio : public CamiBase
{
public:
	std::vector<Coordinate> getCamiCoords() override;

private:
	std::vector<Coordinate> m_coordenades;
};

