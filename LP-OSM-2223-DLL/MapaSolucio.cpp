#include "pch.h"
#include "MapaSolucio.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "CamiSolucio.h"
#include "Util.h"

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& pdis)
{
	pdis = m_puntsInteres;
}

void MapaSolucio::getCamins(std::vector<CamiBase*>& camins)
{
	camins = m_camins;
}

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements)
{
	for (auto element = xmlElements.begin(); element < xmlElements.end(); element++)
	{
		if (element->id_element == "node")
			parsejarNode(element);
		else if (element->id_element == "way")
		{
			classificarCami(element);
		}
	}
	//Parsejem els camins
	for (int i = 0; i < m_ways.size(); i++)
	{
		CamiSolucio* nouCami = new CamiSolucio();
		for (int j = 0; j < m_ways[i].size(); j++)
			nouCami->afegirNode((m_nodesCami.find(m_ways[i][j]))->second);
		m_camins.push_back(nouCami);
	}

}

void MapaSolucio::parsejarNode(std::vector<XmlElement>::iterator& element)
{
	double lat = 0, lon = 0;
	std::string id = "";
	bool interes;

	//Capturem coordenades i ID
	for (int atribut = 0; atribut < element->atributs.size(); atribut++)
	{
		if (element->atributs[atribut].first == "lat")
			lat = std::stod(element->atributs[atribut].second);
		if (element->atributs[atribut].first == "lon")
			lon = std::stod(element->atributs[atribut].second);
		if (element->atributs[atribut].first == "id")
			id = element->atributs[atribut].second;

	}

	//Mirem si és de cami o d'interès
	if (esNodeInteres(element))
	{
		std::string name, shop = "", wheelchair="", opening_hours="", cuisine="", amenity="";
		for (int fill = 0; fill < element->fills.size(); fill++)
		{
			if (element->fills[fill].first == "tag")
			{
				std::pair<std::string, std::string> valorTag =
					Util::kvDeTag(element->fills[fill].second);
				if (valorTag.first == "name")
					name = valorTag.second;
				if (valorTag.first == "shop")
					shop = valorTag.second;
				if (valorTag.first == "opening_hours")
					opening_hours = valorTag.second;
				if (valorTag.first == "wheelchair")
					wheelchair = valorTag.second;
				if (valorTag.first == "cuisine")
					cuisine = valorTag.second;
				if (valorTag.first == "amenity")
					amenity = valorTag.second;
			}
		}
		if (amenity == "restaurant")
			m_puntsInteres.push_back(new PuntDeInteresRestaurantSolucio({ lat, lon }, name, cuisine, wheelchair));
		if (shop != "")
			m_puntsInteres.push_back(new PuntDeInteresBotigaSolucio({ lat, lon }, name, shop, opening_hours, wheelchair));
		else
			m_puntsInteres.push_back(new PuntDeInteresBase({ lat, lon }, name));
	}
	else
		m_nodesCami[id] = { lat, lon };				//Guardem les coordenades dels nodes camí a un unordered_map
}

bool MapaSolucio::esNodeInteres(std::vector<XmlElement>::iterator& element)
{
	bool interes = false;
	for (int fill = 0; fill < element->fills.size(); fill++)
	{
		if (element->fills[fill].first == "tag")
		{
			std::pair<std::string, std::string> valorTag =
				Util::kvDeTag(element->fills[fill].second);
			if (valorTag.first == "highway" || valorTag.first == "public_transport" ||
				valorTag.first == "access" || valorTag.first == "entrance")				//Ja no pot ser d'interès
			{
				interes = false;
				break;
			}
			else if (valorTag.first == "name")
				interes = true;												//Només serà true si no te cap dels tags anteriors i té name
		}
	}
	return interes;
}

void MapaSolucio::classificarCami(std::vector<XmlElement>::iterator& element)
{
	bool valid = false;
	for (int fill = 0; fill < element->fills.size(); fill++)
	{
		if (element->fills[fill].first == "tag")
		{
			std::pair<std::string, std::string> valorTag =
				Util::kvDeTag(element->fills[fill].second);
			if (valorTag.first == "highway")
			{
				valid = true;
				break;
			}
		}
	}
	if (valid)
	{
		m_ways.resize(m_ways.size() + 1);			//incrementem el valor de camins dins del vector
		for (int fill = 0; fill < element->fills.size(); fill++)
		{
			//Guardem l'ID de cada node en un vector únic per cada camí.
			if (element->fills[fill].first == "nd")
				m_ways[m_ways.size() - 1].push_back(element->fills[fill].second[0].second);
		}
	}
}

