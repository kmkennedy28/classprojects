#include <iostream>
#include "Circle.h"
using namespace std;

// center point and radius
Circle::Circle(Point cp, double r) {
	center = cp;
	radius = r;
}
// constructor for the individual coordinates and the radius
Circle::Circle(double x, double y, double r) {
	center = Point(x, y);
	radius = r;
}
// return the area of the circle
double Circle::getArea() {
	double area = (3.1415) * (radius * radius);
	return area;
}

//move the center point
void Circle::moveCircle(double dx, double dy) {
	//use x and y coordinates
	center.move(dx, dy);
}

//check if the Circle object is centered at the origin
bool Circle::isItOrigin() {
	if (center.x() == 0 && center.y() == 0) { //x and y must equal 0
		return true;
	}
	return false;
}

//print a Circle object in the format [(x-coordinate, y-coordinate), radius]
//ex [(2.50, 3.00), 5.00]
void Circle::display() const {
	cout << "[(" << center.x() << ", " << center.y() << "), " << radius << "]";
}