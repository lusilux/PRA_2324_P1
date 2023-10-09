#include <iostream>
#include <cmath>
#include "Circle.h"


double Circle::area() const {
	return M_PI*radius*radius;
}
double Circle::perimeter() const {
	return 2*M_PI*radius;	
}
void Circle::translate(double incX, double incY) {
	center.x+=incX;
	center.y+=incY;
}
void Circle::print() {
	cout << "Centro: (" << center.x << "," << center.y << ")" << endl 
	     <<	"Radio " << radius << endl
	     << "Color " << Shape::get_color() << endl;
}

Circle::Circle() : Shape() {
	center.x = 0;
	center.y = 0;
	radius = 1;
}

Circle::Circle(string color, Point2D center, double radius) : Shape(color){	
	this->center = center;
	this->radius = radius;
}

Circle::Circle(Point2D center, double radius) : Shape(){	
	this->center = center;
	this->radius = radius;
}

Point2D Circle::get_center() const {
	return center;
}

void Circle::set_center(Point2D p) {
	center = p;
}

double Circle::get_radius() const {
	return radius;
}
		
void Circle::set_radius(double r){
	radius = r;
}

ostream& operator<<(std::ostream &out, const Circle &c){
	out  << "Centro: (" << c.center.x << "," << c.center.y << ")" << endl 
	     <<	"Radio " << c.radius << endl
	     << "Color " << c.color << endl;	
	return out;
}