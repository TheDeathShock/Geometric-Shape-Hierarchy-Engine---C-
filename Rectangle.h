//
// Created by amera on 10/16/2025.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Parallelogram.h"

class Rectangle : public Parallelogram{

    public:
    Rectangle();
    Rectangle(int s, Point *p);
    Rectangle(const Rectangle &other);

    //There is no point of a destructor here, as it is already using the virtual constructor from Polygon.
    //~Rectangle();

};



#endif //RECTANGLE_H
