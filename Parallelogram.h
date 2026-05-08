//
// Created by amera on 10/15/2025.
//

#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include "Quadrilateral.h"
#include "Point.h"

//NOTE: In my definition, Parallelogram is not a Trapezoid, as I am using the North American System for definition of geometric shapes.
class Parallelogram : public Quadrilateral{

protected:
    double shorterSide = getShorterSide();
    double longerSide = getLongerSide();
    double acuteAngleInRadians = getAcuteAngleInRadians();

public:
    Parallelogram();
    Parallelogram(int s, Point *p);
    Parallelogram(const Parallelogram &other);

    //There is no point of a destructor here, as it is already using the virtual constructor from Polygon.
    //~Parallelogram();

    static double getMagnitude(const double vec[]);
    static bool isParallel(const double vec1[], const double vec2[]);


    double getShorterSide() const;
    double getLongerSide () const;
    double getAcuteAngleInRadians() const;

};



#endif //PARALLELOGRAM_H
