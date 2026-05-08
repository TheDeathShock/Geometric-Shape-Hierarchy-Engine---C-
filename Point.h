//
// Created by amera on 10/13/2025.
//

#ifndef POINT_H
#define POINT_H

class Point {
    double xCoordinate;
    double yCoordinate;

    public:
    Point();
    Point(double x, double y);
    Point(const Point& other);
    ~Point();

    void setXCoordinate(double x);
    void setYCoordinate(double y);
    double getXCoordinate() const;
    double getYCoordinate() const;


};



#endif //POINT_H
