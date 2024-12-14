#ifndef COMMON_H 
#define COMMON_H

#include "pch.h"

#include <functional>
#include <string>
#include <vector>

typedef std::pair<std::string, std::string> PAIR_ATTR_VALUE;
typedef std::pair<std::string, std::vector<PAIR_ATTR_VALUE>> CHILD_NODE;


typedef struct{
    double lat;
    double lon;
}Coordinate;

bool operator==(const Coordinate& c1, const Coordinate& c2); 


extern "C" typedef struct {
    int i;
    double lat;
    double lon;
    unsigned int color;
    const char* title;
} PoiBridge;

extern "C" typedef struct {
    double* lats;
    double* lons;
    int size;
} WayBridge;

typedef struct {
	std::string id_element;
	std::vector<PAIR_ATTR_VALUE> atributs;
	std::vector<CHILD_NODE> fills;
} XmlElement;

//Definició dels colors per a la classe PuntDeInteresBotigaSolucio
#define COLOR_BOTIGA_SUPERMARKET 0xA5BE00
#define COLOR_BOTIGA_TOBACCO 0xFFAD69
#define COLOR_BOTIGA_BAKERY 0xE85D75
#define COLOR_BOTIGA_BAKERY_WHEELCHAIR 0x4CB944
#define COLOR_BOTIGA_DEFECTE 0xEFD6AC

//Definició dels colors per a la classe PuntDeInteresRestaurantSolucio
#define COLOR_RESTAURANT_PIZZA 0x03FCBA
#define COLOR_RESTAURANT_CHINESE 0xA6D9F7
#define COLOR_RESTAURANT_WHEELCHAIR 0x251351

#endif // COMMON_H