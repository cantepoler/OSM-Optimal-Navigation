#pragma once
#include "MapaBase.h"
class MapaSolucio : public MapaBase
{
public:

	void getPdis(std::vector<PuntDeInteresBase*>& pdis);

private:
	//Estructures adequades per a guardar camins (nodes no interès relacionats)
	//Estrcutura adequada per a guardar nodes d'interes
	std::vector<PuntDeInteresBase*> m_puntsInteres;
};

