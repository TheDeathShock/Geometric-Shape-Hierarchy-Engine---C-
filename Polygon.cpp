//
// Created by amera on 10/13/2025.
//

#include "Polygon.h"

#include <iostream>
#include <ostream>
#include <cmath>

using namespace std;


Polygon::Polygon() : size(3), points(nullptr){
};

Polygon::Polygon(int size, Point *p) : size(size), points(new Point[size]) {

    if (size < 3) {
        throw invalid_argument("Your shape must at least have 3 vertices to be a polygon");
    }

    if (p != nullptr) {
        for (int i = 0; i < size; ++i)
            points[i] = p[i];
    }


}

Polygon::Polygon(const Polygon &other) : size(other.size), points(new Point[other.size]) {
    if (size < 3) {
        throw invalid_argument("Your shape must at least have 3 vertices to be a polygon");

    }
    for (int i = 0; i < size; ++i)
        points[i] = other.points[i];
}


Polygon::~Polygon() {
    delete[] points;
}



bool Polygon::almostEqual(double x, double y) { //The reason I created this function, is that for doubles, we should not use '==' signs as they may be wrong due to rounding errors, etc... So this function is basically a more accurate way to check if double values are equal to each other or not. It gives them an extremely tiny margin of error that may be caused due to the use of doubles.

    bool result;

    double difference = fabs(x - y);

    double scale = fabs(x);
    if (fabs(y) > scale) {
        scale = fabs(y);
    }
    if (1.0 > scale) {
        scale = 1.0;
    }
    double tol= 1e-8;
    double absoluteTolerance = 1e-11;

    double tolerance = tol * scale;
    if (absoluteTolerance > tolerance) {
        tolerance = absoluteTolerance;
    }

    if (difference <= tolerance) {
        result = true;
    }else {
        result = false;
    }
    return result;


}





void Polygon::setPoint(int index, const Point &p) {

    //This is very important for an object created using the Default Constructor, because if it was created using the default constructor, then the pointer array part will be nullptr, meaning it is not pointing to anything, which will make our program crash since we are assigning coordinates to a memory location that does not exist. This part basically checks if it was nullptr, and if it was, it changes it accordingly.

    if (points == nullptr) {
        size = index + 1;
        points = new Point[size];
    }

    if (index >= size) {

        Point* newPNTS = new Point[index + 1];

        for (int i = 0; i < size; ++i)
            newPNTS[i] = points[i];

        delete[] points;
        points = newPNTS;
        size = index + 1;
    }
    points[index] = p;


}


void Polygon::setpoint(int index, double x, double y) {

    //Same idea as the other set function, if we don't do this, then the program crash, because we are basically setting values to a memory address that doesn't exist (nullptr)

    if (points == nullptr) {
        size = index + 1;
        points = new Point[size];
    }

    if (index >= size) {
        Point* newPNTS = new Point[index + 1];
        for (int i = 0; i < size; ++i)
            newPNTS[i] = points[i];

        delete[] points;
        points = newPNTS;
        size = index + 1;
    }
    points[index] = Point(x, y);

}












double Polygon::area() const {

    double area;
    double summation = 0.0;

    for (int i = 0; i < size; i++){
    summation += points[i].getXCoordinate() * points[(i+1)%size].getYCoordinate() - (points[i].getYCoordinate() * points[(i+1)%size].getXCoordinate());
    }

    area = 0.5 * summation;
    return std::fabs(area); //The fabs is so we can return the absolute value of the area, since the area cannot be negative.

}




void Polygon::display() const {
    for (int i = 0; i < size; i++) {

        cout<<points[i].getXCoordinate()<<" "<<points[i].getYCoordinate()<<endl;

    }
}