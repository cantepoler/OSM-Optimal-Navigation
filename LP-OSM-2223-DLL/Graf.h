#pragma once
#include <vector>
#include <list>
#include <utility>
#include "Common.h"
class Graf
{
public:
	Graf();
	~Graf();

	void afegirNode(const Coordinate& node);
	void afegirAresta(size_t posNode1, size_t posNode2, double pes);

private:
	std::vector<std::list<std::pair<size_t, double>>> m_veins; //Els veins, per l'index i el pes (distància Haversine)

	std::vector<Coordinate> m_nodes;
	size_t m_numNodes;
	size_t m_numArestes;
};

