#pragma once
#include <unordered_map>
#include <utility>
#include "Util.h"
#include "MapaBase.h"
class MapaSolucio : public MapaBase
{
public:
	MapaSolucio() { ; }
	~MapaSolucio();
	void getPdis(std::vector<PuntDeInteresBase*>& pdis);
	void getCamins(std::vector<CamiBase*>& camins);
	void parsejaXmlElements(std::vector<XmlElement>& xmlElements);
private:
	std::unordered_map<std::string, Coordinate> m_nodesCami;
	std::vector<std::vector<std::string>> m_ways;
	std::vector<PuntDeInteresBase*> m_puntsInteres;
	std::vector<CamiBase*> m_camins;
	void parsejarNode(std::vector<XmlElement>::iterator& element);
	bool esNodeInteres(std::vector<XmlElement>::iterator& element);
	void classificarCami(std::vector<XmlElement>::iterator& element);
};

