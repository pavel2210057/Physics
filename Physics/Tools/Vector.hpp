#ifndef VECTOR_HPP
#define VECTOR_HPP


class Vector {
public:
	struct VectorComp {
		double x, y;
	} components;

	Vector();

	Vector(double comps);

	Vector(double x, double y);

	~Vector();

	double getLength() const;

	double getLengthSqr() const;

	double getScalar(Vector right) const;

	Vector getNormal() const;

	Vector getNormalized() const;

	double getLinear() const;

	friend Vector operator+(Vector self, Vector right);
	
	friend Vector operator-(Vector self, Vector right);
	
	friend Vector operator*(Vector self, Vector right);
	
	friend Vector operator/(Vector self, Vector right);

	friend void operator+=(Vector& self, Vector right);

	friend void operator-=(Vector& self, Vector right);

	friend void operator*=(Vector& self, Vector right);

	friend void operator/=(Vector& self, Vector right);

	friend bool operator==(Vector self, Vector right);

	friend bool operator!=(Vector self, Vector right);
};

#endif //!VECTOR_HPP