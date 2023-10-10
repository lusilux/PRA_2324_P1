#include "Drawing.h"

using namespace std;

Drawing::Drawing() {
    shapes = new ListArray<Shape*>; 
} 

Drawing::~Drawing(){
    delete[] shapes; 
} 
void Drawing::add_front(Shape* shape){
    shapes->insert(0,shape);
} 

void Drawing::add_back(Shape* shape){
    shapes->append(shape);
} 
void Drawing::print_all(){
    Shape **a = shapes->arr();
    for(int i = 0; i < shapes->size(); i++)a[i]->print(); 
} 
double Drawing::get_area_all_circles(){
    double total = 0;
    Shape **a = shapes->arr();
    for(int i = 0; i < shapes->size(); i++){
        if(a[i]->type() == 'c')total += a[i]->area(); 
    } 
    return total; 
} 
void Drawing::move_squares(double incX, double incY){
    Shape **a = shapes->arr();
    for(int i = 0; i < shapes->size(); i++){
        if(a[i]->type() == 's')a[i]->translate(incX,incY); 
    } 
} 
