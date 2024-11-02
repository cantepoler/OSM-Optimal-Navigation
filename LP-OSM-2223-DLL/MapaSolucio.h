#pragma once
#include <unordered_map>
#include <utility>
#include "pch.h"
#include "MapaBase.h"
class MapaSolucio : public MapaBase
{
public:
	MapaSolucio() { ; }
	void getPdis(std::vector<PuntDeInteresBase*>& pdis);
	void getCamins(std::vector<CamiBase*>& camins);
	void parsejaXmlElements(std::vector<XmlElement>& xmlElements);
private:
	std::unordered_map<int, Coordinate> m_nodesCami;
	std::vector<std::vector<int>> m_ways;
	std::vector<XmlElement> m_nodesInteres;
	std::vector<PuntDeInteresBase*> m_puntsInteres;
	std::vector<CamiBase*> m_camins;
	void parsejarNode(std::vector<XmlElement>::iterator& element);
	bool esNodeInteres(std::vector<XmlElement>::iterator& element);
	void classificarCami(std::vector<XmlElement>::iterator& element);
};

