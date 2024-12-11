#include "pch.h"
#include "GrafSolucio.h"

void GrafSolucio::afegirNode(const Coordinate& node)
{
	m_nodes.emplace_back(node);
	m_veins.resize(++m_numNodes);
}

void GrafSolucio::afegirAresta(Coordinate node1, Coordinate node2, double pes)
{
	size_t posNode1 = std::distance(m_nodes.begin(), std::find(m_nodes.begin(), m_nodes.end(), node1));
	size_t posNode2 = std::distance(m_nodes.begin(), std::find(m_nodes.begin(), m_nodes.end(), node2));

	if (posNode1 < m_numNodes && posNode2 < m_numNodes)
	{
		m_veins[posNode1].emplace_back(posNode2, pes);
		m_veins[posNode2].emplace_back(posNode1, pes);
		m_numArestes++;
	}
}
