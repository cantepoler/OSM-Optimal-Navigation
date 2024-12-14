#pragma once
#include "pch.h"
#include <vector>
#include "Common.h"

class CamiBase {
	public:
		virtual std::vector<Coordinate> getCamiCoords() = 0;
};

