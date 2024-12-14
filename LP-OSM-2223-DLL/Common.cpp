#include"pch.h"
#include "Common.h"
bool operator==(const Coordinate& c1, const Coordinate& c2) { return c1.lat == c2.lat && c1.lon == c2.lon; }
//Definim aqui l'operador d'igualtat pels Coordinate, ja que si ho faig a Common.h es redefineix massa cops.