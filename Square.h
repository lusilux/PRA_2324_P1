#include <iostream>
#include "Rectangle.h"
#include "Point2D.h"

using namespace std;

class Square : public Rectangle{

    public:
        void print() override;
        void set_vertices(Point2D* vertices) override;
        char type() override;

        Square();
        Square(string color, Point2D* vertices);
        friend ostream& operator<<(ostream &out, const Square &square);
    private:
        static bool check(Point2D* vertices);

};