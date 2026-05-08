//
// Created by amera on 10/16/2025.
//

#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.h"

class Square : public Rectangle {

    public:
    Square();
    Square(int s, Point *p);
    Square(const Square &other);


    //There is no point of a destructor here, as it is already using the virtual constructor from Polygon.
    //~Square();

    double getSide();


};



#endif //SQUARE_H
