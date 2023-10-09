#include "Shape.h"

using namespace std;

Shape::Shape(){
	color = "red";
}

Shape::Shape(string color){
	if(color == "red" || color == "blue" || color == "green")this->color = color;
	else throw invalid_argument("Color proporcionado no válido");
}

string Shape::get_color() const {
	return color;
}

void Shape::set_color(string c){
	if(c == "red" || c == "blue" || c == "green")color = c;
	else throw invalid_argument("Color proporcionado no válido");
}