#include "Vector.hpp"
#include <cmath>

Vector::Vector() {
	components.x = 0;
	components.y = 0;
}

Vector::Vector(double comps) {
	components.x = comps;
	components.y = comps;
}

Vector::Vector(double x, double y) {
	components.x = x;
	components.y = y;
}

Vector::~Vector() {}

double Vector::getLength() const {
	return sqrt(getLengthSqr());
}

double Vector::getLengthSqr() const {
	return pow(components.x, 2) + pow(components.y, 2);
}

double Vector::getScalar(Vector right) const {
	return components.x * right.components.x + components.y * right.components.y;
}

Vector Vector::getNormal() const {
	return Vector(-components.y, components.x);
}

Vector Vector::getNormalized() const {
	double len = getLength();

	return Vector(components.x / len, components.y / len);
}

double Vector::getLinear() const {
	if (!components.y)
		return 0;
	return components.y / components.x;
}

Vector operator+(Vector self, Vector right) {
	return Vector(self.components.x + right.components.x, self.components.y + right.components.y);
}

Vector operator-(Vector self, Vector right) {
	return Vector(self.components.x - right.components.x, self.components.y - right.components.y);
}

Vector operator*(Vector self, Vector right) {
	return Vector(self.components.x * right.components.x, self.components.y * right.components.y);
}

Vector operator/(Vector self, Vector right) {
	return Vector(self.components.x / right.components.x, self.components.y / right.components.y);
}

void operator+=(Vector& self, Vector right) {
	self = self + right;
}

void operator-=(Vector& self, Vector right) {
	self = self - right;
}

void operator*=(Vector& self, Vector right) {
	self = self * right;
}

void operator/=(Vector& self, Vector right) {
	self = self / right;
}

bool operator==(Vector self, Vector right) {
	return self.components.x == right.components.y && self.components.y == right.components.y;
}

bool operator!=(Vector self, Vector right) {
	return self.components.x != right.components.y || self.components.y != right.components.y;
}