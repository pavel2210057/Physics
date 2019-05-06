#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include "Body\Body.hpp"
#include "Tools\Vector.hpp"
#include "Tools\Area.hpp"

class Geometry {
protected:
	struct GeometryData {
		Body body;
		Vector position;
	} geometryData;

	Geometry(Body body, Vector position = 0);

	~Geometry();
public:
	Body& body();

	Vector& position();

	virtual bool isInside(AreaRect areaRect) const = 0;

	virtual bool isInside(AreaPolygon areaPolygon) const = 0;
private:
	virtual void generateRect() = 0;
};

#endif //!GEOMETRY_HPP