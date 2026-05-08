//
// Created by amera on 10/16/2025.
//

#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "Parallelogram.h"
#include "Point.h"

class Rhombus : public Parallelogram {

    protected:
    double side = getLongerSide(); //Doesn't matter if it is the longer or shorter side, as both of them must be equal.

    public:
    Rhombus();
    Rhombus(int s, Point *p);
    Rhombus(const Rhombus &other);

    //There is no point of a destructor here, as it is already using the virtual constructor from Polygon.
    //~Rhombus();

    double getSide();
};



#endif //RHOMBUS_H
