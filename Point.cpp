#include <iostream>
using namespace std;
#include "Point.h" // defines Point class

Point::Point() {
	_x = 0;
	_y = 0;
}

Point::Point(double x, double y) {
	this->_x = x;
	this->_y = y;
}
double Point::x() const {
	return _x;
}
double Point::y() const {
	return _y;
}

//Returns polar coordinate r = ?x2 + y2
double Point::magnitude() const {
	double magnitude = sqrt((_x * _x) + (_y * _y));
	return magnitude;
}

//(b)Move the points(x, y), dx in the x direction and dy in the y direction
void Point::move(double dx, double dy) {
	_x += dx;
	_y += dy;
}

//(c)Print the point in the format(x, y).
void Point::print() const {
	cout << "(" << _x << " ," << _y << ")";
}