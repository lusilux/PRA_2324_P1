#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include<cmath>

using namespace std;


class Point2D{
    public:
        double x;
        double y;

        Point2D(double x=0, double y=0){
            this->x = x;
            this->y = y;
        } 

        static double distance(const Point2D &a, const Point2D &b){
            double distance = sqrt(pow(a.x-b.x,2.0)+pow(a.y-b.y,2.0));
            return distance;
        } 

        friend bool operator==(const Point2D &a, const Point2D &b);
        friend bool operator!=(const Point2D &a, const Point2D &b);
        friend ostream& operator<<(std::ostream &out, const Point2D &p);
};

bool operator==(const Point2D &a, const Point2D &b){
    return a.x == b.x && a.y == b.y;
} 

bool operator!=(const Point2D &a, const Point2D &b){
    return a.x != b.x || a.y != b.y; 
} 

ostream& operator<<(std::ostream &out, const Point2D &p){
    out << "(" << p.x << "," << p.y << ")";
    return out;
} 

#endif