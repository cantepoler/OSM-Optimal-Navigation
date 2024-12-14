#include "pch.h"
#include "GrafSolucio.h"

void GrafSolucio::afegirNode(const Coordinate& node)
{
	for (size_t i = 0; i < m_numNodes; i++)
	{
		if (m_nodes[i] == node)					//Ens assegurem de que el node no està repetit
			return;
	}
	m_nodes.emplace_back(node);
	m_veins.resize(++m_numNodes);
}

void GrafSolucio::afegirAresta(size_t indNode1, size_t indNode2, double pes)
{
	m_veins[indNode1].emplace_back(indNode2, pes);
	m_veins[indNode2].emplace_back(indNode1, pes);
	m_numArestes++;
}
