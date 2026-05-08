//
// Created by amera on 10/15/2025.
//

#ifndef TRAPEZOID_H
#define TRAPEZOID_H
#include "Point.h"
#include "Quadrilateral.h"

class Trapezoid : public Quadrilateral {

protected:
    double shorterSide = getShorterSide();
    double longerSide = getLongerSide();

    public:
    Trapezoid();
    Trapezoid(int s, Point *p);
    Trapezoid(const Trapezoid &other);

    //There is no point of a destructor here, as it is already using the virtual constructor from Polygon.
    //~Trapezoid();

    static double getMagnitude(const double vec[]);
    static bool isParallel(const double vec1[], const double vec2[]);

    double getShorterSide() const;
    double getLongerSide() const;


};



#endif //TRAPEZOID_H
