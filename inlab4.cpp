#include <iostream>
#include "Point.h"
#include "Circle.h"

using namespace std;

void main() {
    //create a point at 5, 10 then print it
    Point p(5, 10);
    cout << "Point: ";
    p.print();

    //create a circle at 3, 7 with a radius of 5 and print it 
    Circle c(3, 7, 5);
    cout << "\nCircle: ";
    c.display();
    //print the area, origin, and weather its at the origin with the circle functions
    cout << "\nArea: " << c.getArea();
    cout << "\nAt origin: ";
    if (c.isItOrigin()) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    //move the circle left 5 and down 3 and print new location
    c.moveCircle(-5, -3);
    cout << "\nMoved circle to: ";
    c.display();

}

/*
Point: (5 ,10)
Circle: [(3, 7), 5]
Area: 78.5375
At origin: false
Moved circle to: [(-2, 4), 5]
*/
