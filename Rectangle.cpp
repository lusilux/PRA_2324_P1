#include <iostream>
#include <cmath>
#include "Rectangle.h"

using namespace std;


Point2D Rectangle::operator[](int ind) const{
	if(ind < 0 || ind >= N_VERTICES)throw out_of_range("Indice no valido");
	else return vs[ind]; 
} 

Rectangle& Rectangle::operator=(const Rectangle &r) {
	delete[] vs;
	vs = new Point2D[4];  
	color = r.color;
	for(int i = 0; i < 4; i++){
		vs[i] = r.vs[i];   
	}    
	return *this; 
} 
ostream& operator<<(ostream &out, const Rectangle &r){
	for(int i = 0; i < 4; i++)out << "Rectángulo vértices: (" << r.vs[i].x << "," << r.vs[i].y << ") ";
	out << "Color " << r.color;
	return out;
} 

static bool check(Point2D* vertices){
	bool rect = false;
	if((Point2D::distance(vertices[0],vertices[1]) == Point2D::distance(vertices[2],vertices[3])) 
	&& (Point2D::distance(vertices[1],vertices[2]) == Point2D::distance(vertices[0],vertices[3]))) rect = true;
	return rect;
} 

double Rectangle::area() const {
	double b = Point2D::distance(vs[0],vs[1]);
	double h = Point2D::distance(vs[1],vs[2]);
	return b*h;
}
double Rectangle::perimeter() const {
	double l1 = Point2D::distance(vs[0],vs[1]);
	double l2 = Point2D::distance(vs[1],vs[2]);
	return 2*l1+2*l2;
}

void Rectangle::translate(double incX, double incY){
	for(int i = 0; i < 4; i++){
		vs[i].x += incX;
		vs[i].y += incY;
	}
	
}

void Rectangle::print() {
	for(int i = 0; i < 4; i++)cout << "Rectángulo vértices: (" << vs[i].x << "," << vs[i].y << ") ";
	cout << "Color " << color;
}

Rectangle::Rectangle():Shape(){
	Point2D* vertices = new Point2D[4];
    vertices[0] = Point2D(-1,0.5);
    vertices[1] = Point2D(1,0.5);
    vertices[2] = Point2D(1,-0.5);
    vertices[3] = Point2D(-1,-0.5);
	Rectangle::set_vertices(vertices); 
}

Rectangle::Rectangle(string color, Point2D* vertices) : Shape(color){
	Rectangle::set_vertices(vertices);
}
Rectangle::Rectangle(const Rectangle &r){
	vs = r.vs;
	color = r.color;
} 
Rectangle::~Rectangle(){delete[] vs;} 

Point2D Rectangle::get_vertex(int ind) const{
	if(ind < 0 || ind >= N_VERTICES)throw out_of_range("Indice no valido");
	else return vs[ind]; 
} 

void Rectangle::set_vertices(Point2D* vertices){
	bool rect = false;
	if((Point2D::distance(vertices[0],vertices[1]) == Point2D::distance(vertices[2],vertices[3])) 
	&& (Point2D::distance(vertices[1],vertices[2]) == Point2D::distance(vertices[0],vertices[3]))) rect = true;
	if(rect)vs = vertices;
	else throw invalid_argument("Los vértices no conforman un cuadrado");
} 


