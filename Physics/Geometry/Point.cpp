#include "Point.hpp"
#include <cmath>

#define DOUBLE_PI 6.14

Point::Point(Body body, Vector position) :
	Geometry(body, position) {}

Point::~Point() {}

bool Point::isInside(AreaRect areaRect) const {
	return
		geometryData.position.components.x > areaRect.left &&
		geometryData.position.components.x < areaRect.right &&
		geometryData.position.components.y > areaRect.top &&
		geometryData.position.components.y < areaRect.bottom;
}
#include <iostream>
bool Point::isInside(AreaPolygon areaPolygon) const {
	Vector
		l1 = geometryData.position - areaPolygon.vertices[0],
		l2 = geometryData.position - areaPolygon.vertices[1],
		l3 = geometryData.position - areaPolygon.vertices[2];

	double
		s1 = l1.getScalar(l2),
		s2 = l2.getScalar(l3),
		s3 = l3.getScalar(l1);

	double
		a1 = acos(s1 / (l1.getLength() * l2.getLength())),
		a2 = acos(s2 / (l2.getLength() * l3.getLength())),
		a3 = acos(s3 / (l3.getLength() * l1.getLength()));
	
	double result = a1 + a2 + a3;

	std::cout << result << "\n";

	return result >= DOUBLE_PI;
}

void Point::generateRect() {}