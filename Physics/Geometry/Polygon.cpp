#include "Polygon.hpp"
#include "Point.hpp"

#define min(x, y) ((x < y) ? (x) : (y))
#define max(x, y) ((x > y) ? (x) : (y))

Polygon::Polygon(Body body, AreaPolygon areaPolygon) :
	Geometry(body, 0) {
	polygonData.areaPolygon = areaPolygon;
	generateRect();
}

Polygon::~Polygon() {}

bool Polygon::isInside(AreaRect areaRect) const {
	AreaRect ar = polygonData.areaPolygon.areaRect;
	return
		Point(Body(), Vector(ar.left, ar.top)).isInside(areaRect) &&
		Point(Body(), Vector(ar.right, ar.top)).isInside(areaRect) &&
		Point(Body(), Vector(ar.left, ar.bottom)).isInside(areaRect) &&
		Point(Body(), Vector(ar.right, ar.bottom)).isInside(areaRect);
}

bool Polygon::isInside(AreaPolygon areaPolygon) const {
	if (!isInside(areaPolygon.areaRect))
		return false;

	AreaRect ar = polygonData.areaPolygon.areaRect;

	return
		Point(Body(), Vector(ar.left, ar.top)).isInside(areaPolygon) &&
		Point(Body(), Vector(ar.right, ar.top)).isInside(areaPolygon) &&
		Point(Body(), Vector(ar.left, ar.bottom)).isInside(areaPolygon) &&
		Point(Body(), Vector(ar.right, ar.bottom)).isInside(areaPolygon);
}

void Polygon::generateRect() {
	AreaPolygon& ap = polygonData.areaPolygon;
	AreaRect& ar = ap.areaRect;

	ar.left = min(
		min(
			ap.vertices[0].components.x, ap.vertices[1].components.x
		),
		ap.vertices[2].components.x
	);
	ar.top = min(
		min(
			ap.vertices[0].components.y, ap.vertices[1].components.y
		),
		ap.vertices[2].components.y
	);
	ar.right = max(
		max(
			ap.vertices[0].components.x, ap.vertices[1].components.x
		),
		ap.vertices[2].components.x
	);
	ar.bottom = max(
		max(
			ap.vertices[0].components.y, ap.vertices[1].components.y
		),
		ap.vertices[2].components.y
	);
}