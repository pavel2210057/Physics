#ifndef AREA_HPP
#define AREA_HPP

#include "Vector.hpp"

struct AreaRect {
	double left;
	double top;
	double right;
	double bottom;
};

struct AreaPolygon {
	Vector vertices[3];
	AreaRect areaRect;
};

#endif //!AREA_HPP