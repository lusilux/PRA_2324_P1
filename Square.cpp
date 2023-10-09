#include <iostream>
#include "Square.h"

using namespace std;

bool check(Point2D* vertices){
    bool s = false;
	if((Point2D::distance(vertices[0],vertices[1]) == Point2D::distance(vertices[1],vertices[2])) 
	&& (Point2D::distance(vertices[1],vertices[2]) == Point2D::distance(vertices[2],vertices[3]))
    && (Point2D::distance(vertices[1],vertices[2]) == Point2D::distance(vertices[0],vertices[3]))) s = true;
	return s;
} 

ostream& operator<<(ostream &out, const Square &square){
    out << "Square: ";
    for(int i = 0; i < 4; i++)out << "(" << square.vs[i].x << "," << square.vs[i].y << ") ";
	out << "Color " << square.color;
	return out;
} 

void Square::print(){
    cout << *this;
} 
void Square::set_vertices(Point2D* vertices){

    bool s = false;
	if((Point2D::distance(vertices[0],vertices[1]) == Point2D::distance(vertices[1],vertices[2])) 
	&& (Point2D::distance(vertices[1],vertices[2]) == Point2D::distance(vertices[2],vertices[3]))
    && (Point2D::distance(vertices[1],vertices[2]) == Point2D::distance(vertices[0],vertices[3]))) s = true;

	if(s)vs = vertices;
	else throw invalid_argument("Los vértices no conforman un cuadrado");
} 

Square::Square():Rectangle(){
    Point2D* vertices = new Point2D[4];
    vertices[0] = Point2D(-1,1);
    vertices[1] = Point2D(1,1);
    vertices[2] = Point2D(1,-1);
    vertices[3] = Point2D(-1,-1);
	Rectangle::set_vertices(vertices); 
} 
Square::Square(string color, Point2D* vertices){
    bool s = false;
	if((Point2D::distance(vertices[0],vertices[1]) == Point2D::distance(vertices[1],vertices[2])) 
	&& (Point2D::distance(vertices[1],vertices[2]) == Point2D::distance(vertices[2],vertices[3]))
    && (Point2D::distance(vertices[1],vertices[2]) == Point2D::distance(vertices[0],vertices[3]))) s = true;

    if(s){
        vs = vertices;
        this->color = color;
    } 
	else throw invalid_argument("Los vértices no conforman un cuadrado");
} 

    


