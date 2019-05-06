#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "Geometry.hpp"

class Polygon : public Geometry {
protected:
	struct PolygonData {
		AreaPolygon areaPolygon;
	} polygonData;
public:
	Polygon(Body body, AreaPolygon areaPolygon);

	~Polygon();

	virtual bool isInside(AreaRect areaRect) const;

	virtual bool isInside(AreaPolygon areaPolygon) const;
private:
	virtual void generateRect();
};

#endif //!POLYGON_HPP