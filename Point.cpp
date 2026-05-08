//
// Created by amera on 10/13/2025.
//

#include "Point.h"

Point::Point() : xCoordinate(0), yCoordinate(0) {
};

Point::Point(double x, double y) : xCoordinate(x), yCoordinate(y) {
}

Point::Point(const Point &other) : xCoordinate(other.xCoordinate), yCoordinate(other.yCoordinate) {
};
Point::~Point() {
}


void Point::setXCoordinate(double x) {
    xCoordinate = x;
}
void Point::setYCoordinate(double y) {
    yCoordinate = y;
}
double Point::getXCoordinate() const {
    return xCoordinate;
}
double Point::getYCoordinate() const {
    return yCoordinate;
}



