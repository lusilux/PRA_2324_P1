#include "Shape.h"

class Circle : public Shape {
	private:
		Point2D center;
		double radius;

	public:
		double area() const override;
		double perimeter() const override;
		void translate(double incX, double incY) override;
		void print() override;

		Circle();

		Circle(string color, Point2D center, double radius);
		Circle(Point2D center, double radius);
		Point2D get_center() const;

		void set_center(Point2D p);

		double get_radius() const;
		
		void set_radius(double r);

		friend ostream& operator<<(std::ostream &out, const Circle &c);
};