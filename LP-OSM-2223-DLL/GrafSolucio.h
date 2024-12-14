#pragma once
#include <vector>
#include <list>
#include <utility>
#include "Common.h"
class GrafSolucio
{
public:
	GrafSolucio() : m_numNodes(0), m_numArestes(0) { ; }
	~GrafSolucio() { ; }

	void afegirNode(const Coordinate& node);
	void afegirAresta(size_t indNode1, size_t indNode2, double pes);

private:
	std::vector<std::list<std::pair<size_t, double>>> m_veins; //Els veins, per l'index i el pes (distància Haversine)
	std::vector<Coordinate> m_nodes;
	size_t m_numNodes;
	size_t m_numArestes;
};

