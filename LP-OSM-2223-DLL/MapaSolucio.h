#pragma once
#include "pch.h"
#include "MapaBase.h"
class MapaSolucio : public MapaBase
{
public:
	MapaSolucio() { ; }
	void getPdis(std::vector<PuntDeInteresBase*>& pdis);
	void getCamins(std::vector<CamiBase*>& camins);
	void parsejaXmlElements(std::vector<XmlElement>& xmlElements) { ; }
private:
	//Estructures adequades per a guardar camins (nodes no interès relacionats)
	//Estrcutura adequada per a guardar nodes d'interes
	std::vector<PuntDeInteresBase*> m_puntsInteres;
	std::vector<CamiBase*> m_camins;
};

