//
// Created by amera on 10/13/2025.
//

#ifndef POLYGON_H
#define POLYGON_H
#include "Point.h"

class Polygon {

    friend class testDriver;

protected:
int size;
Point *points;
    static bool almostEqual(double a, double b);

    Point defaultPoint[2] = {Point(0,0),Point(0,0)};

    public:
    Polygon();
    Polygon(int size , Point *p);
    Polygon(const Polygon &other);
    virtual ~Polygon();


    void setPoint(int index, const Point& p);
    void setpoint(int index, double x, double y);
    double area() const;

    void display() const;



};



#endif //POLYGON_H
