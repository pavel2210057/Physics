#ifndef POINT_HPP
#define POINT_HPP

#include "Geometry.hpp"

class Point : public Geometry {
public:
	Point(Body body, Vector position = 0);

	~Point();

	virtual bool isInside(AreaRect areaRect) const;

	virtual bool isInside(AreaPolygon areaPolygon) const;
private:
	virtual void generateRect();
};

#endif //!POINT_HPP