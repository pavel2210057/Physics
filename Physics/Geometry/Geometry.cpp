#include "Geometry.hpp"

Geometry::Geometry(Body body, Vector position) {
	geometryData.body = body;
	geometryData.position = position;
}

Geometry::~Geometry() {}

Body& Geometry::body() {
	return geometryData.body;
}

Vector& Geometry::position() {
	return geometryData.position;
}