//
// Created by amera on 10/13/2025.
//

#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H
#include "Polygon.h"
#include "Point.h"


class Quadrilateral : public Polygon {


    public:
    Quadrilateral();
    Quadrilateral(int s, Point *p); // The size(number of vertices) of a Quadrilateral should always be equal to 4, if the user input anything greater than 4, an exception would be thrown.
    Quadrilateral(const Quadrilateral &other);
    //There is no point of a destructor here, as it is already using the virtual constructor from Polygon.
   // ~Quadrilateral();


/*
 *  NOTE: There is no need to redefine and reimplement the stuff that are already inherited from the parent class (Polygon).
 */











};



#endif //QUADRILATERAL_H
