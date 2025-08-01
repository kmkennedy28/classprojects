#pragma once
#include "Point.h" //defines the circle class

class Circle {
public:
	Circle(Point cp, double r); // constructor using a point object and radius
	Circle(double x, double y, double r); // constructor for coordinates and radius
	double getArea(); // calculate and return the area of the circle
	void moveCircle(double dx, double dy); //move the circle's center point x coordinates, and y coordinates
	void display() const; //display the data
	bool isItOrigin(); //return weather or not it is centered at 0,0
private:
	Point center;
	double radius;
};